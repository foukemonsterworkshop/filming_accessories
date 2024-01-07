#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library

#include "switch_font.c"

#include "ScreenDefinitions.h"
#include "Menu.h"


//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI lcd(MODEL,CS,CD,RST,LED); //model,cs,dc,reset,led
LCDWIKI_TOUCH touch(TCS,TCLK,TDOUT,TDIN,TIRQ);

uint16_t px,py;

//navigation variables and setup
Menu mainMenu;
Menu homeMenu;
Menu jogMenu;
Menu panMenu;
Menu truckMenu;
Menu parallaxMenu;

typedef struct{
  MenuState menuState;
  Menu menu;
} menuDictionary;

const menuDictionary menuArray[]{
    {MAIN, mainMenu},
    {HOME, homeMenu},
    {JOG, jogMenu},
    {PAN, panMenu},
    {TRUCK, truckMenu},
    {PARALLAX, parallaxMenu}
  };

//machine travel variables

void setup(void) 
{    
  Serial.begin(9600);
  Serial.println("Serial Activated");
  currentState = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
  
  
  Serial.println("initializing");
  initializeMenus();
  Serial.println("initialized");
  draw_menu();
  Serial.println("drawn");
  
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
  
  if(menuArray[currentState].menu.item.is_pressed(px,py)){
    draw_menu();
  }
  //navigateActiveMenu(currentState, px, py);

}

void navigateActiveMenu(MenuState currentState, int16_t px, int16_t py){

}

void initializeMenus(){
  Serial.println("Idk something I guess");
  MenuItem stepperMotorControl = MenuItem(0,0,100,100, WHITE);
  Button stepperMotorState = Button(switch_on_2,sizeof(switch_on_2)/2,5,5,34,34,1);
  Label label = Label("Motors Active",50,11,2,GREEN, BLACK,1);
  stepperMotorControl.interaction=stepperMotorState;
  stepperMotorControl.label=label;
  Serial.println(label.content);
  Serial.println(stepperMotorControl.label.content);
  
  //menuArray[MAIN].menu.menuItems.push_back(stepperMotorControl);
  menuArray[MAIN].menu.item = stepperMotorControl;
}

void show_Button(Button button)
    {
        lcd.Set_Addr_Window(button.x1, button.y1, button.x2, button.y2); 
        lcd.Push_Any_Color(button.color_buf, button.buf_size, 1, 1);
    }

void show_Label(Label label)
    {
      lcd.Set_Text_Mode(label.mode);
      lcd.Set_Text_Size(label.textSize);
      lcd.Set_Text_colour(label.textColor);
      lcd.Set_Text_Back_colour(label.bgTextColor);
      lcd.Print_String(label.content,label.x,label.y);
    }

void draw_menu(){
  
      lcd.Set_Draw_color(192, 192, 192);
      lcd.Draw_Fast_HLine(0, 3, lcd.Get_Display_Width());
      //loop over menuItems and then draw lines between
      Serial.println("Global Data in draw method:");
      Serial.println(menuArray[currentState].menu.item.label.content);
      show_Label(menuArray[currentState].menu.item.label);
        show_Button(menuArray[currentState].menu.item.interaction);
      /*for(MenuItem item : menuArray[currentState].menu.menuItems){
        show_Label(item.label);
        show_Button(item.interaction);
      }*/
    }