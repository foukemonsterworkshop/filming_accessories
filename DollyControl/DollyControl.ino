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

uint16_t px,py;

//navigation variables and setup

static Menu mainMenu;
static Menu homeMenu;
static Menu jogMenu;
static Menu panMenu;
static Menu truckMenu;
static Menu parallaxMenu;
static Menu valueEntry;

Menu get_menu(MenuState state){
  switch(state){
    case MAIN: return mainMenu;
    case HOME: return homeMenu;
    case JOG: return jogMenu;
    case PAN: return panMenu;
    case TRUCK: return truckMenu;
    case PARALLAX: return parallaxMenu;
    case VALUE_ENTRY: return valueEntry;
  }
};

//machine travel variables
boolean steppersActive = true;

void setup(void) 
{    
  currentState = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
  
  Serial.begin(9600);
  Serial.println("Initializing...");
  initializeMenus();
  draw_menu(mainMenu);
  Serial.println("Exiting setup");
}

void loop(void)
{
  boolean debug = true;

  boolean requires_redraw = false;

  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State()&TP_PRES_DOWN) 
  {
    px = touch.x;
    py = touch.y;
  }
  
  Menu currentMenu = get_menu(currentState);
  MenuItem* menuPtr = currentMenu.items;

  if(debug){
      Serial.println("Testing clicks in: ");
      Serial.println(currentMenu.name);
      Serial.println("Clicked region: ");
      Serial.println(px);
      Serial.println(py); 
  }

  for(int i = 0; i < currentMenu.size; i++){
    if(!menuPtr->initialized)break;
    if(debug){
      Serial.println("Button Region: ");
      Serial.println(menuPtr->button.area.x1);
      Serial.println(menuPtr->button.area.x2);
      Serial.println(menuPtr->button.area.y1);
      Serial.println(menuPtr->button.area.y2);
    }
    if(menuPtr->is_pressed(px, py)){
      
      if(debug){
        Serial.println("clicked: " + i);
      }
      //react to being clicked
      draw_rectangle(menuPtr->area, DARKGREY);
      
      //change current
      switch(menuPtr->button.action){
        case NAVIGATE:
          currentState = menuPtr->button.navigateTarget;
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
    draw_menu(get_menu(currentState));
  }

}
