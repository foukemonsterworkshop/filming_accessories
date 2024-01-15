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

//navigation variables and setup
int px,py;
boolean requires_redraw = false;

//machine travel variables
boolean steppers_active = true;

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
  Serial.begin(1200);
  Serial.println("");

  current_state = MAIN;
  requires_redraw = true;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);

  Serial.print("Available Memory after Setup: ");
  Serial.println(freeMemory());
}

void loop(void){

  if(requires_redraw){
    lcd.Fill_Screen(WHITE);
    requires_redraw = false;

    init_menu(current_state);
  }

  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State()&TP_PRES_DOWN){
    px = touch.x;
    py = touch.y;
  }

  press_menu_button(current_state, px, py);
  
}