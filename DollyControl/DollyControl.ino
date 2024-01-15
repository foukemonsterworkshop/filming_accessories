#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library

#include "ScreenDefinitions.h"
#include "MenuEnums.h"
#include "Button.h"

#include <Stepper.h>

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI lcd(MODEL,CS,CD,RST,LED); //model,cs,dc,reset,led
LCDWIKI_TOUCH touch(TCS,TCLK,TDOUT,TDIN,TIRQ);

int px,py;

//navigation variables and setup
Button * buttons;
boolean requires_redraw = false;

//machine travel variables
boolean steppersActive = true;

struct StepperMove {
  int speed = 0;
  int duration = 0;
  Unit unit = SECOND;
} motion;

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
  
  Serial.begin(1200);

  Serial.println("Initializing Main Menu...");
  buttons = init_main_menu();
  Serial.println("Exiting setup");

}

void loop(void){

  if(requires_redraw){
    lcd.Fill_Screen(WHITE);
    Serial.println("Loading new menu: " + current_state);

    delete [] buttons;
    requires_redraw = false;

    buttons = init_menu(current_state);
  }

  boolean debug = false;

  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State()&TP_PRES_DOWN){
    px = touch.x;
    py = touch.y;
  }

  for(int i = 0; i < 5; i++){

    Button current = buttons[i];

    if(debug){ 
      Serial.println("At index: " + i);
      Serial.print("Looking at button: ");
      Serial.println(current.name);
      Serial.print("Initialized State: ");
      Serial.println(current.initialized);

      Serial.print("Touched-> x: ");
      Serial.print(px);
      Serial.print(" y: ");
      Serial.println(py);

      Serial.print("Button press zone: x: ");
      Serial.print(current.x);
      Serial.print(" y: ");
      Serial.print(current.y);
      Serial.print(" x1: ");
      Serial.print(current.x1);
      Serial.print(" y1: ");
      Serial.println(current.y1);

      Serial.println("Testing for press");
      boolean press = buttons->is_pressed(px, py);
      Serial.print("Tested result: ");
      Serial.println(press);
    }

    if(buttons->is_pressed(px, py)){
      switch(buttons->action){
        case NAVIGATE:
          Serial.println("Detected NAV touch");
          current_state = current.navigateTarget;
          requires_redraw = true;
          break;
        case UPDATE_VALUE: 
          Serial.println("Detected UPDATE touch");
          *current.affectedBoolean = !*current.affectedBoolean;

          //buttons->display.set_color(*buttons->affectedBoolean ? buttons->active_color : buttons->inactive_color);
          //buttons->label.set_content(*buttons->affectedBoolean ? buttons->active_text : buttons->inactive_text);
          //draw_button(*buttons);

          break;
        case MODIFY_INPUT:
          Serial.println("Detected Mod input touch");
          break;
        default:
          Serial.println("bad state");
          break;
      }
    }
  }
}