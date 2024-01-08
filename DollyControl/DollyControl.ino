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

void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    lcd.Set_Text_Mode(mode);
    lcd.Set_Text_Size(csize);
    lcd.Set_Text_colour(fc);
    lcd.Set_Text_Back_colour(bc);
    lcd.Print_String(str,x,y);
}

void show_picture(const uint8_t *color_buf,int16_t buf_size,int16_t x1,int16_t y1,int16_t x2,int16_t y2)
{
    lcd.Set_Addr_Window(x1, y1, x2, y2); 
    lcd.Push_Any_Color(color_buf, buf_size, 1, 1);
}

void button_show_holder(const uint8_t *color_buf,int16_t buf_size,int16_t x1,int16_t y1,int16_t x2,int16_t y2){
    lcd.Set_Addr_Window(x1, y1, x2, y2); 
    lcd.Push_Any_Color(color_buf, buf_size, 1, 1);
}

void show_Label(Label label)
    {
      lcd.Set_Text_Mode(label.mode);
      lcd.Set_Text_Size(label.textSize);
      lcd.Set_Text_colour(label.textColor);
      lcd.Set_Text_Back_colour(label.bgTextColor);
      lcd.Print_String(label.content,label.x,label.y);
    }



void setup(void) 
{    
  currentState = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
  
  Serial.begin(600);
  initializeMenus();
  draw_menu(get_menu(MAIN));
}

void loop(void)
{
  px = 0;
  py = 0;
  touch.TP_Scan(0);
  if (touch.TP_Get_State()&TP_PRES_DOWN) 
  {
    px = touch.x;
    py = touch.y;
  }
  
  Serial.println("Clicked region: ");
  Serial.println(px);
  Serial.println(py);
  Menu currentMenu = get_menu(currentState);
  MenuItem* menuPtr = currentMenu.items;
  for(int i = 0; i < currentMenu.size; i++){
    if(menuPtr->is_pressed(px, py)){
      Serial.println("clicked");
      //react to being clicked
      draw_rectangle(menuPtr->area, DARKGREY);
      
      //change current
      switch(menuPtr->button.action){
        case NAVIGATE:
          currentState = menuPtr->button.navigateTarget;
          break;
        case UPDATE_VALUE: 
          /*
          Serial.println("Swapping stepper motor state:");
          Serial.println(steppersActive);
          Serial.println(*menuPtr->button.affectedBoolean);
          */
          *menuPtr->button.affectedBoolean = !*menuPtr->button.affectedBoolean;
          /*
          Serial.println(steppersActive);
          Serial.println(*menuPtr->button.affectedBoolean);
          */
          delay(300);
          break;
        case MODIFY_INPUT:
          break;
        default:
          Serial.println("bad state");
      }
      
      //most objects sshould be initialized
      //need to figure out how to change which value is editted
      //when on value entry, likely pass a pointer to the object

      //swaps state of boolean related to button
      

    }
    menuPtr++;
  }
}
