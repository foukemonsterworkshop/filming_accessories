#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library

#include "switch_font.c"

#include "ScreenDefinitions.h"
#include "MenuEnums.h"
#include "Menu.h"

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI lcd(MODEL,CS,CD,RST,LED); //model,cs,dc,reset,led
LCDWIKI_TOUCH touch(TCS,TCLK,TDOUT,TDIN,TIRQ);

int px,py;

//navigation variables and setup
Menu current_menu;

//machine travel variables
boolean steppersActive = true;

void setup(void) 
{    
  current_state = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
  
  Serial.begin(9600);
  Serial.println("Initializing...");
  current_menu = init_main_menu();
  draw_menu(current_menu);
  Serial.println("Exiting setup");

}

void loop(void)
{
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
  
  MenuItem* menuPtr = current_menu.items;
  if(debug){
      Serial.println("Testing clicks in: ");
      Serial.println(current_menu.name);
      Serial.println("Clicked region: ");
      Serial.println(px);
      Serial.println(py); 
  }

  for(int i = 0; i < current_menu.size; i++){
    if(!menuPtr->initialized)break;

    if(debug){
      Serial.println("Button Region: ");
      Serial.println(menuPtr->button.area.x);
      Serial.println(menuPtr->button.area.x2);
      Serial.println(menuPtr->button.area.y);
      Serial.println(menuPtr->button.area.y2);
    }

    if(menuPtr->is_pressed(px, py)){
      
      if(true){
        Serial.println("clicked: " + i);
      }
      //react to being clicked
      //draw_shape(*menuPtr);
      
      switch(menuPtr->button.action){
        case NAVIGATE:
          current_state = menuPtr->button.navigateTarget;
          requires_redraw = true;
          break;
        case UPDATE_VALUE: 
          *menuPtr->button.affectedBoolean = !*menuPtr->button.affectedBoolean;
          break;
        case MODIFY_INPUT:
          break;
        default:
          Serial.println("bad state");
      }
    }
    menuPtr++;
  }

  if(requires_redraw){
    lcd.Fill_Screen(WHITE);
    Serial.println("Loading new menu: " + current_state);
    current_menu = init_menu(current_state);
    draw_menu(current_menu);
  }
}
