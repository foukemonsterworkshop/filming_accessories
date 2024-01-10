#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library

#include "ScreenDefinitions.h"
#include "MenuEnums.h"
#include "Menu.h"

#include <Stepper.h>

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI lcd(MODEL,CS,CD,RST,LED); //model,cs,dc,reset,led
LCDWIKI_TOUCH touch(TCS,TCLK,TDOUT,TDIN,TIRQ);

int px,py;

//navigation variables and setup
Menu current_menu;

//machine travel variables
boolean steppersActive = true;

/*
struct StepperMove {
  int speed = 0;
  int duration = 0;
  Unit unit = SECOND;
} motion;
*/

/*
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper gantry_stepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
*/

void setup(void) 
{    
  current_state = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
  
  Serial.begin(600);

  Serial.println("Finished General Setup");

  current_menu = init_main_menu();
  Serial.println("Finished init, drawing...");
  draw_menu(current_menu);

  Serial.println("Finished drawing, entering main loop...");
}

void loop(void)
{
  Serial.println("Entered main loop");

/*
  gantry_stepper.setSpeed(20);
	gantry_stepper.step(stepsPerRevolution);
	delay(1000);
	
	// Rotate CCW quickly at 10 RPM
	gantry_stepper.setSpeed(30);
	gantry_stepper.step(-stepsPerRevolution);
	delay(1000);
*/
  boolean debug = false;

  boolean requires_redraw = false;
  boolean skip_click_check = false;

  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State()&TP_PRES_DOWN){
    px = touch.x;
    py = touch.y;
  }

  Button* bPtr = current_menu.buttons;
  if(debug){
      Serial.println("Testing clicks in: ");
      Serial.println(current_menu.name);
      Serial.println("Clicked region: ");
      Serial.println(px);
      Serial.println(py); 
  }

  for(int i = 0; i < current_menu.button_size; i++){
    if(!bPtr->initialized)break;
    if(debug){
      Serial.println(bPtr->display->display_type);
      Serial.println("Button Region: ");
      Serial.println(bPtr->display->x);
      Serial.println(bPtr->display->x2);
      Serial.println(bPtr->display->y);
      Serial.println(bPtr->display->y2);
    }

    if(bPtr->is_pressed(px, py)){
      if(debug){
        Serial.println("clicked: " + i);
      }
      switch(bPtr->action){
        case NAVIGATE:
          current_state = bPtr->navigateTarget;
          requires_redraw = true;
          break;
        case UPDATE_VALUE: 
          *bPtr->affectedBoolean = !*bPtr->affectedBoolean;
          bPtr->display->set_color(*bPtr->affectedBoolean ? bPtr->active_color : bPtr->inactive_color);
          bPtr->label.set_content(*bPtr->affectedBoolean ? bPtr->active_text : bPtr->inactive_text);
          draw_button(*bPtr);
          delay(250);
          break;
        case MODIFY_INPUT:
          break;
        default:
          Serial.println("bad state");
      }
    }
    bPtr++;
  }

  if(requires_redraw){
    lcd.Fill_Screen(WHITE);
    Serial.println("Loading new menu: " + current_state);
    current_menu = init_menu(current_state);
    draw_menu(current_menu);
  }
}