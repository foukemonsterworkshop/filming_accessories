#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library
#include "switch_font.c"

#include "ScreenDefinitions.h"
#include "Menu.h"

boolean switch_flag_1 = true,switch_flag_2 = true,switch_flag_3 = true,switch_flag_4 = true,switch_flag_5 = true,switch_flag_6 = true;  
int16_t menu_flag = 1,old_menu_flag;     

uint16_t px,py;

/*void show_system_menu(void)
{    
    show_string("Home Machine",10,150,2,BLACK, BLACK,1);
    show_string("Jog Machine",10,170,2,BLACK, BLACK,1);
    show_string("Configured Pan",10,190,2,BLACK, BLACK,1);
    show_string("Configured Truck",10,210,2,BLACK, BLACK,1);
    show_string("Configured Parallax",10,230,2,BLACK, BLACK,1);
    switch(menu_flag)
    {
      case 1:
      {
          my_lcd.Set_Draw_color(BLUE);
          my_lcd.Fill_Rectangle(0, 147, my_lcd.Get_Display_Width()-1, 166);
          show_string("time setting",10,150,2,WHITE, BLACK,1);
          break;
      }
      case 2:
      {
          my_lcd.Set_Draw_color(BLUE);
          my_lcd.Fill_Rectangle(0, 167, my_lcd.Get_Display_Width()-1, 186);
          show_string("date setting",10,170,2,WHITE, BLACK,1);
          break;
      }
      case 3:
      {
          my_lcd.Set_Draw_color(BLUE);
          my_lcd.Fill_Rectangle(0, 187, my_lcd.Get_Display_Width()-1, 206);
          show_string("alarm setting",10,190,2,WHITE, BLACK,1);
          break;
      }
      case 4:
      {
          my_lcd.Set_Draw_color(BLUE);
          my_lcd.Fill_Rectangle(0, 207, my_lcd.Get_Display_Width()-1, 226);
          show_string("talk setting",10,210,2,WHITE, BLACK,1);
          break;
      }
      case 5:
      {
          my_lcd.Set_Draw_color(BLUE);
          my_lcd.Fill_Rectangle(0, 227, my_lcd.Get_Display_Width()-1, 246);
          show_string("sound setting",10,230,2,WHITE, BLACK,1);
          break;
      }
      default:
        break;
    }
}*/

//navigation variables and setup
Menu mainMenu;
Menu homeMenu;
Menu jogMenu;
Menu panMenu;
Menu truckMenu;
Menu parallaxMenu;

static const char *stateString[] = {"Main", "Home", "Jog", "Pan", "Truck", "Parallax"};

//machine travel variables

void setup(void) 
{    
  Serial.begin(9600);
  currentState = MAIN;

  lcd.Init_LCD();
  lcd.Set_Rotation(2);
  touch.TP_Set_Rotation(3);
  touch.TP_Init(lcd.Get_Rotation(),lcd.Get_Display_Width(),lcd.Get_Display_Height()); 
  lcd.Fill_Screen(WHITE);
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
  
  //String stateString = currentState.to
  switch (currentState) {
    case MAIN:
      Serial.print((String)stateString[currentState] + "\n");
      //navigateMainMenu(px, py);
      break;
    case HOME:
      Serial.print((String)stateString[currentState] + "\n");
      //navigateHomeMenu();
      break;
    case JOG:
      Serial.print((String)stateString[currentState] + "\n");
      //navigateJogMenu();
      break;
    case PAN:
      Serial.print((String)stateString[currentState] + "\n");
      //navigatePanMenu();
      break;
    case TRUCK:
      Serial.print((String)stateString[currentState] + "\n");
      //navigateTruckMenu();
      break;
    case PARALLAX:
      Serial.print((String)stateString[currentState] + "\n");
      //navigateParallaxMenu();
      break;
    default:
      Serial.println("oops");
      break;
  }

}

/*void navigateMainMenu(int16_t px, int16_t py){
  if(is_pressed(5,5,34,34,px,py))
  {
      if(switch_flag_1)
      {
          show_picture(switch_off_2,sizeof(switch_off_2)/2,5,5,34,34);
          lcd.Set_Draw_color(WHITE);
          lcd.Fill_Rectangle(60, 11,  216, 27);
          show_string("Motors Inactive",50,11,2,RED, BLACK,1); 
          switch_flag_1 = false;
       }
       else
       {
         show_picture(switch_on_2,sizeof(switch_on_2)/2,5,5,34,34);
         lcd.Set_Draw_color(WHITE);
         lcd.Fill_Rectangle(60, 11,  216, 27);
         show_string("Motors Active",50,11,2,GREEN, BLACK,1);
         switch_flag_1 = true;
       }
       delay(100);
   }
   if(is_pressed(195,40,234,54,px,py))
   {
      if(switch_flag_2)
      {
          show_picture(switch_off_3,sizeof(switch_off_3)/2,195,40,234,54);
          switch_flag_2 = false;
      }
      else
      {
         show_picture(switch_on_3,sizeof(switch_on_3)/2,195,40,234,54);
         switch_flag_2 = true;
      }
      delay(100);
    }
    if(is_pressed(195,60,234,74,px,py))
    {
       if(switch_flag_3)
      {
          show_picture(switch_off_3,sizeof(switch_off_3)/2,195,60,234,74);
          switch_flag_3 = false;
      }
      else
      {
         show_picture(switch_on_3,sizeof(switch_on_3)/2,195,60,234,74);
         switch_flag_3 = true;
      }
      delay(100);
     }
     if(is_pressed(205,81,217,93,px,py))
     {
       if(switch_flag_4)
       {
         show_picture(switch_off_1,sizeof(switch_off_1)/2,204,80,218,94);
          switch_flag_4 = false;
       }
       else
       {
         show_picture(switch_on_1,sizeof(switch_on_1)/2,204,80,218,94);
          switch_flag_4 = true;
       }
      delay(100);
     }
     if(is_pressed(205,101,217,113,px,py))
     {
       if(switch_flag_5)
       {
        show_picture(switch_off_1,sizeof(switch_off_1)/2,204,100,218,114);
        switch_flag_5 = false;
       }
       else
       {
         show_picture(switch_on_1,sizeof(switch_on_1)/2,204,100,218,114);
         switch_flag_5 = true;
        }
       delay(100);
     }
     if(is_pressed(5,119,lcd.Get_Display_Width()-1,137,px,py))
     {     
          lcd.Set_Draw_color(MAGENTA);
          lcd.Fill_Rectangle(0, 117, lcd.Get_Display_Width()-1, 137);
          delay(100);
          lcd.Set_Draw_color(WHITE);
          lcd.Fill_Rectangle(0, 117, lcd.Get_Display_Width()-1, 137);
          if(switch_flag_6)
          {
              show_string("system setting   <",5,119,2,BLUE, BLACK,1);
              //show_system_menu();
              switch_flag_6 = false;
          }
          else
          {
               show_string("system setting   >",5,119,2,BLUE, BLACK,1);
               lcd.Set_Draw_color(WHITE);
               lcd.Fill_Rectangle(0, 147, lcd.Get_Display_Width()-1, 250);
               switch_flag_6 = true;
          }
     }
     if(is_pressed(0,147,lcd.Get_Display_Width()-1,247,px,py)&&(!switch_flag_6))
     {
        old_menu_flag = menu_flag;     
        if(is_pressed(0,147,lcd.Get_Display_Width()-1,166,px,py))
        {
            lcd.Set_Draw_color(BLUE);
            lcd.Fill_Rectangle(0, 147, lcd.Get_Display_Width()-1, 166);
            show_string("time setting",10,150,2,WHITE, BLACK,1);
            menu_flag = 1;
         }
         if(is_pressed(0,167,lcd.Get_Display_Width()-1,186,px,py))
         {
            lcd.Set_Draw_color(BLUE);
            lcd.Fill_Rectangle(0, 167, lcd.Get_Display_Width()-1, 186);
            show_string("date setting",10,170,2,WHITE, BLACK,1);
            menu_flag = 2;
         }
         if(is_pressed(0,187,lcd.Get_Display_Width()-1,206,px,py))
         {
            lcd.Set_Draw_color(BLUE);
            lcd.Fill_Rectangle(0, 187, lcd.Get_Display_Width()-1, 206);
            show_string("alarm setting",10,190,2,WHITE, BLACK,1);
            menu_flag = 3;
         }
         if(is_pressed(0,207,lcd.Get_Display_Width()-1,226,px,py))
         {
             lcd.Set_Draw_color(BLUE);
             lcd.Fill_Rectangle(0, 207, lcd.Get_Display_Width()-1, 226);
            show_string("talk setting",10,210,2,WHITE, BLACK,1);
            menu_flag = 4;
         }
         if(is_pressed(0,227,lcd.Get_Display_Width()-1,246,px,py))
         {
            lcd.Set_Draw_color(BLUE);
            lcd.Fill_Rectangle(0, 227, lcd.Get_Display_Width()-1, 246);
            show_string("sound setting",10,230,2,WHITE, BLACK,1);
            menu_flag = 5;
         }  
         if(old_menu_flag != menu_flag)
         {
            switch(old_menu_flag)
            {
              case 1:
              {
                  lcd.Set_Draw_color(WHITE);
                  lcd.Fill_Rectangle(0, 147, lcd.Get_Display_Width()-1, 166);
                  show_string("time setting",10,150,2,BLACK, BLACK,1);
                  break;
              }
              case 2:
              {
                  lcd.Set_Draw_color(WHITE);
                  lcd.Fill_Rectangle(0, 167, lcd.Get_Display_Width()-1, 186);
                  show_string("date setting",10,170,2,BLACK, BLACK,1);
                  break;
              }
              case 3:
              {
                  lcd.Set_Draw_color(WHITE);
                  lcd.Fill_Rectangle(0, 187, lcd.Get_Display_Width()-1, 206);
                  show_string("alarm setting",10,190,2,BLACK, BLACK,1);
                  break;
              }
              case 4:
              {
                  lcd.Set_Draw_color(WHITE);
                  lcd.Fill_Rectangle(0, 207, lcd.Get_Display_Width()-1, 226);
                  show_string("talk setting",10,210,2,BLACK, BLACK,1);
                  break;
              }
              case 5:
              {
                  lcd.Set_Draw_color(WHITE);
                  lcd.Fill_Rectangle(0, 227, lcd.Get_Display_Width()-1, 246);
                  show_string("sound setting",10,230,2,BLACK, BLACK,1);
                  break;
              }
              default:
                break;                  
           }       
       }
       delay(100);
   }
}
*/