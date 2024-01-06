#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library
#include "switch_font.c"

#include "ScreenDefs.h"
#include "Menu.h"

boolean switch_flag_1 = true,switch_flag_2 = true,switch_flag_3 = true,switch_flag_4 = true,switch_flag_5 = true,switch_flag_6 = true;  
int16_t menu_flag = 1,old_menu_flag;     

uint16_t px,py;

void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    my_lcd.Set_Text_Mode(mode);
    my_lcd.Set_Text_Size(csize);
    my_lcd.Set_Text_colour(fc);
    my_lcd.Set_Text_Back_colour(bc);
    my_lcd.Print_String(str,x,y);
}

void show_picture(const uint8_t *color_buf,int16_t buf_size,int16_t x1,int16_t y1,int16_t x2,int16_t y2)
{
    my_lcd.Set_Addr_Window(x1, y1, x2, y2); 
    my_lcd.Push_Any_Color(color_buf, buf_size, 1, 1);
}

boolean is_pressed(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py)
{
    if((px > x1 && px < x2) && (py > y1 && py < y2))
    {
        return true;  
    } 
    else
    {
        return false;  
    }
 }

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
  drawMainMenu();
}

void loop(void)
{
  px = 0;
  py = 0;
  my_touch.TP_Scan(0);
  if (my_touch.TP_Get_State()&TP_PRES_DOWN) 
  {
    px = my_touch.x;
    py = my_touch.y;
  } 
  
  //String stateString = currentState.to
  switch (currentState) {
    case MAIN:
      Serial.print((String)stateString[currentState] + "\n");
      navigateMainMenu(px, py);
      break;
    case HOME:
      Serial.print((String)stateString[currentState] + "\n");
      navigateHomeMenu();
      break;
    case JOG:
      Serial.print((String)stateString[currentState] + "\n");
      navigateJogMenu();
      break;
    case PAN:
      Serial.print((String)stateString[currentState] + "\n");
      navigatePanMenu();
      break;
    case TRUCK:
      Serial.print((String)stateString[currentState] + "\n");
      navigateTruckMenu();
      break;
    case PARALLAX:
      Serial.print((String)stateString[currentState] + "\n");
      navigateParallaxMenu();
      break;
    default:
      Serial.println("oops");
      break;
  }

}

void drawMainMenu(){
 my_lcd.Init_LCD();
 my_lcd.Set_Rotation(2);
 my_touch.TP_Set_Rotation(3);
 my_touch.TP_Init(my_lcd.Get_Rotation(),my_lcd.Get_Display_Width(),my_lcd.Get_Display_Height()); 
 my_lcd.Fill_Screen(WHITE); 
 
 my_lcd.Set_Draw_color(192, 192, 192);
 my_lcd.Draw_Fast_HLine(0, 3, my_lcd.Get_Display_Width());
 show_picture(switch_on_2,sizeof(switch_on_2)/2,5,5,34,34);
 show_string("Motors Active",50,11,2,GREEN, BLACK,1);

 my_lcd.Draw_Fast_HLine(0, 37, my_lcd.Get_Display_Width());
 
 show_string("Home Machine",5,40,2,BLACK, BLACK,1);
 show_picture(switch_on_3,sizeof(switch_on_3)/2,195,40,234,54);

  my_lcd.Draw_Fast_HLine(0, 57, my_lcd.Get_Display_Width());
 
 show_string("Jog Machine",5,60,2,BLACK, BLACK,1);
 show_picture(switch_on_3,sizeof(switch_on_3)/2,195,60,234,74);

 my_lcd.Draw_Fast_HLine(0, 77, my_lcd.Get_Display_Width());
 
 show_string("Conf. Pan",5,80,2,BLACK, BLACK,1);
 show_picture(switch_on_1,sizeof(switch_on_1)/2,204,80,218,94);

 my_lcd.Draw_Fast_HLine(0, 97, my_lcd.Get_Display_Width());
 
 show_string("Conf. Truck",5,100,2,BLACK, BLACK,1);
 show_picture(switch_on_1,sizeof(switch_on_1)/2,204,100,218,114);

 my_lcd.Draw_Fast_HLine(0, 116, my_lcd.Get_Display_Width());
 
 show_string("Conf. Parallax",5,119,2,BLUE, BLACK,1);
 my_lcd.Draw_Fast_HLine(0, 138, my_lcd.Get_Display_Width());
}

void navigateMainMenu(int16_t px, int16_t py){
  if(is_pressed(5,5,34,34,px,py))
  {
      if(switch_flag_1)
      {
          show_picture(switch_off_2,sizeof(switch_off_2)/2,5,5,34,34);
          my_lcd.Set_Draw_color(WHITE);
          my_lcd.Fill_Rectangle(60, 11,  216, 27);
          show_string("Motors Inactive",50,11,2,RED, BLACK,1); 
          switch_flag_1 = false;
       }
       else
       {
         show_picture(switch_on_2,sizeof(switch_on_2)/2,5,5,34,34);
         my_lcd.Set_Draw_color(WHITE);
         my_lcd.Fill_Rectangle(60, 11,  216, 27);
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
     if(is_pressed(5,119,my_lcd.Get_Display_Width()-1,137,px,py))
     {     
          my_lcd.Set_Draw_color(MAGENTA);
          my_lcd.Fill_Rectangle(0, 117, my_lcd.Get_Display_Width()-1, 137);
          delay(100);
          my_lcd.Set_Draw_color(WHITE);
          my_lcd.Fill_Rectangle(0, 117, my_lcd.Get_Display_Width()-1, 137);
          if(switch_flag_6)
          {
              show_string("system setting   <",5,119,2,BLUE, BLACK,1);
              //show_system_menu();
              switch_flag_6 = false;
          }
          else
          {
               show_string("system setting   >",5,119,2,BLUE, BLACK,1);
               my_lcd.Set_Draw_color(WHITE);
               my_lcd.Fill_Rectangle(0, 147, my_lcd.Get_Display_Width()-1, 250);
               switch_flag_6 = true;
          }
     }
     if(is_pressed(0,147,my_lcd.Get_Display_Width()-1,247,px,py)&&(!switch_flag_6))
     {
        old_menu_flag = menu_flag;     
        if(is_pressed(0,147,my_lcd.Get_Display_Width()-1,166,px,py))
        {
            my_lcd.Set_Draw_color(BLUE);
            my_lcd.Fill_Rectangle(0, 147, my_lcd.Get_Display_Width()-1, 166);
            show_string("time setting",10,150,2,WHITE, BLACK,1);
            menu_flag = 1;
         }
         if(is_pressed(0,167,my_lcd.Get_Display_Width()-1,186,px,py))
         {
            my_lcd.Set_Draw_color(BLUE);
            my_lcd.Fill_Rectangle(0, 167, my_lcd.Get_Display_Width()-1, 186);
            show_string("date setting",10,170,2,WHITE, BLACK,1);
            menu_flag = 2;
         }
         if(is_pressed(0,187,my_lcd.Get_Display_Width()-1,206,px,py))
         {
            my_lcd.Set_Draw_color(BLUE);
            my_lcd.Fill_Rectangle(0, 187, my_lcd.Get_Display_Width()-1, 206);
            show_string("alarm setting",10,190,2,WHITE, BLACK,1);
            menu_flag = 3;
         }
         if(is_pressed(0,207,my_lcd.Get_Display_Width()-1,226,px,py))
         {
             my_lcd.Set_Draw_color(BLUE);
             my_lcd.Fill_Rectangle(0, 207, my_lcd.Get_Display_Width()-1, 226);
            show_string("talk setting",10,210,2,WHITE, BLACK,1);
            menu_flag = 4;
         }
         if(is_pressed(0,227,my_lcd.Get_Display_Width()-1,246,px,py))
         {
            my_lcd.Set_Draw_color(BLUE);
            my_lcd.Fill_Rectangle(0, 227, my_lcd.Get_Display_Width()-1, 246);
            show_string("sound setting",10,230,2,WHITE, BLACK,1);
            menu_flag = 5;
         }  
         if(old_menu_flag != menu_flag)
         {
            switch(old_menu_flag)
            {
              case 1:
              {
                  my_lcd.Set_Draw_color(WHITE);
                  my_lcd.Fill_Rectangle(0, 147, my_lcd.Get_Display_Width()-1, 166);
                  show_string("time setting",10,150,2,BLACK, BLACK,1);
                  break;
              }
              case 2:
              {
                  my_lcd.Set_Draw_color(WHITE);
                  my_lcd.Fill_Rectangle(0, 167, my_lcd.Get_Display_Width()-1, 186);
                  show_string("date setting",10,170,2,BLACK, BLACK,1);
                  break;
              }
              case 3:
              {
                  my_lcd.Set_Draw_color(WHITE);
                  my_lcd.Fill_Rectangle(0, 187, my_lcd.Get_Display_Width()-1, 206);
                  show_string("alarm setting",10,190,2,BLACK, BLACK,1);
                  break;
              }
              case 4:
              {
                  my_lcd.Set_Draw_color(WHITE);
                  my_lcd.Fill_Rectangle(0, 207, my_lcd.Get_Display_Width()-1, 226);
                  show_string("talk setting",10,210,2,BLACK, BLACK,1);
                  break;
              }
              case 5:
              {
                  my_lcd.Set_Draw_color(WHITE);
                  my_lcd.Fill_Rectangle(0, 227, my_lcd.Get_Display_Width()-1, 246);
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

void drawHomeMachineMenu(){

}

void navigateHomeMenu(){

}

void drawJogMachineMenu(){

}

void navigateJogMenu(){

}

void drawPanMenu(){

}

void navigatePanMenu(){

}

void drawTruckMenu(){

}

void navigateTruckMenu(){

}

void drawParallaxMenu(){

}

void navigateParallaxMenu(){

}