#include <LCDWIKI_GUI.h>    //Core graphics library
#include <LCDWIKI_SPI.h>    //Hardware-specific library
#include <LCDWIKI_TOUCH.h>  //touch screen library

#include <Regexp.h>

#include "ScreenDefinitions.h"
#include "MenuEnums.h"

#include "StepperOperation.h"

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI lcd(MODEL, CS, CD, RST, LED);  //model,cs,dc,reset,led
LCDWIKI_TOUCH touch(TCS, TCLK, TDOUT, TDIN, TIRQ);

//navigation and interaction variables
int px, py;
boolean requires_redraw = false;

MenuState current_state;
MenuState prev_state;

STEPPER_FOCUS s_focus;
STEPPER_INPUT s_input;

String current_input = "";

//machine travel variables
boolean steppers_active = true;

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence

//g2t belt driven
//Belt pitch: 2mm
//No. Teeth in model pulley: 40
//mm per rotation = 80mm
Stepper gantry_stepper = Stepper(stepsPerRevolution, 2, 3, 4, 5);

//herringbone gear driven
//drive gear has 18 teeth
//camera stand gear has 36 teeth
//1 rotation = .5 camera rotation
Stepper pan_stepper = Stepper(stepsPerRevolution, 6, 7, 8, 9);

void setup(void) {
  Serial.begin(9600);
  Serial.println("");

  current_state = MAIN;
  requires_redraw = true;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(), lcd.Get_Display_Width(), lcd.Get_Display_Height());
  lcd.Fill_Screen(WHITE);
}

void loop(void) {

  if (requires_redraw) {
    lcd.Fill_Screen(WHITE);
    requires_redraw = false;

    init_menu(current_state);
  }

  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State() & TP_PRES_DOWN) {
    px = touch.x;
    py = touch.y;
  }

  interact_with_menu(current_state, px, py);

}