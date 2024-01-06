enum MenuState {MAIN, HOME, JOG, PAN, TRUCK, PARALLAX} currentState;

class Rectangle{
  public:
    int16_t minX;
    int16_t maxX;
    int16_t minY;
    int16_t maxY;
    boolean contains(int16_t px, int16_t py){
      return px > minX && px < maxX && py > minY && py < maxY;
    }
};

class Button{
  public:
    MenuState navigateTarget;
    Rectangle touchableArea;
};

class MenuItem{
  #include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <LCDWIKI_TOUCH.h> //touch screen library
  public:
    LCDWIKI_SPI lcd;
    LCDWIKI_TOUCH touch;
    int16_t xSize, ySize;
    int16_t startX, startY;
    String title;
    Button interaction;
    
    /*
    MenuItem(LCDWIKI_SPI passedLcd, LCDWIKI_TOUCH passedTouch){
      lcd = passsedLcd;
      touch = passedTouch;
    }

    MenuItem(LCDWIKI_SPI lcd, LCDWIKI_TOUCH touch, Button interaction){
      lcd = lcd;
      touch = touch;
      interaction = interaction;
    }
    */

    void show_picture(const uint8_t *color_buf,int16_t buf_size,int16_t x1,int16_t y1,int16_t x2,int16_t y2)
    {
        lcd.Set_Addr_Window(x1, y1, x2, y2); 
        lcd.Push_Any_Color(color_buf, buf_size, 1, 1);
    }

    void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
    {
      lcd.Set_Text_Mode(mode);
      lcd.Set_Text_Size(csize);
      lcd.Set_Text_colour(fc);
      lcd.Set_Text_Back_colour(bc);
      lcd.Print_String(str,x,y);
    }

    void draw_item(){
      lcd.Set_Draw_color(192, 192, 192);
      lcd.Draw_Fast_HLine(0, 3, lcd.Get_Display_Width());
      show_picture(switch_on_2,sizeof(switch_on_2)/2,5,5,34,34);
      show_string("Motors Active",50,11,2,GREEN, BLACK,1);
    }
};

class Menu{
  public:
    
    //placeholder size
    Menu(){
    }
    //MenuItem menuItems[15];
    
    void draw_menu(){
      //loop over menuItems and then draw lines between
      lcd.Draw_Fast_HLine(0, 37, lcd.Get_Display_Width());

      /*
 show_string("Home Machine",5,40,2,BLACK, BLACK,1);
 show_picture(switch_on_3,sizeof(switch_on_3)/2,195,40,234,54);

 lcd.Draw_Fast_HLine(0, 57, lcd.Get_Display_Width());
 
 show_string("Jog Machine",5,60,2,BLACK, BLACK,1);
 show_picture(switch_on_3,sizeof(switch_on_3)/2,195,60,234,74);

 lcd.Draw_Fast_HLine(0, 77, lcd.Get_Display_Width());
 
 show_string("Conf. Pan",5,80,2,BLACK, BLACK,1);
 show_picture(switch_on_1,sizeof(switch_on_1)/2,204,80,218,94);

 lcd.Draw_Fast_HLine(0, 97, lcd.Get_Display_Width());
 
 show_string("Conf. Truck",5,100,2,BLACK, BLACK,1);
 show_picture(switch_on_1,sizeof(switch_on_1)/2,204,100,218,114);

 lcd.Draw_Fast_HLine(0, 116, lcd.Get_Display_Width());
 
 show_string("Conf. Parallax",5,119,2,BLUE, BLACK,1);
 lcd.Draw_Fast_HLine(0, 138, lcd.Get_Display_Width());
      */
    }
};