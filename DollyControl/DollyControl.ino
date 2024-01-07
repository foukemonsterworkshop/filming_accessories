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
static Menu mainMenu;
static Menu homeMenu;
static Menu jogMenu;
static Menu panMenu;
static Menu truckMenu;
static Menu parallaxMenu;

Menu getMenu(MenuState state){
  switch(state){
    case MAIN: return mainMenu;
    case HOME: return homeMenu;
    case JOG: return jogMenu;
    case PAN: return panMenu;
    case TRUCK: return truckMenu;
    case PARALLAX: return parallaxMenu;
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

void draw_menu(){
  
      lcd.Fill_Rect(getMenu(MAIN).item.x1, getMenu(MAIN).item.y1, getMenu(MAIN).item.x2, getMenu(MAIN).item.y2-getMenu(MAIN).item.y1, getMenu(MAIN).item.bgColor);
      show_Label(getMenu(MAIN).item.label);
      

}

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
  
  if(getMenu(MAIN).item.is_pressed(px,py)){
    Serial.println("clicked");
    lcd.Fill_Rect(getMenu(MAIN).item.x1, getMenu(MAIN).item.y1, lcd.Get_Display_Width(), getMenu(MAIN).item.y2-getMenu(MAIN).item.y1, DARKGREY);
    delay(2000);
    draw_menu();
  }

}

void initializeMenus(){
  Serial.println("lcd info:");
  Serial.println(lcd.Get_Display_Width());
  Serial.println(lcd.Get_Width());
  Serial.println(lcd.Get_Height());
  int16_t xOffset = lcd.Get_Display_Width()-10;
  Serial.println(xOffset);
  Button stepperMotorState = Button(5,xOffset,5,30);
  Label label = Label("Motors Active",50,11,2,GREEN, BLUE,1, "label created");

  MenuItem stepperMotorControl = MenuItem(5,xOffset,5,30, LIGHTGREY, label, stepperMotorState);
  Serial.println(label.extraData);
  Serial.println(stepperMotorControl.label.content);
  
  //menuArray[MAIN].menu.menuItems.push_back(stepperMotorControl);
  mainMenu = Menu(stepperMotorControl);
  Serial.println(getMenu(MAIN).item.label.content);

}