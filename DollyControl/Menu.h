#include "Vector.h"

enum MenuState {MAIN, HOME, JOG, PAN, TRUCK, PARALLAX} currentState;
static const char *stateString[] = {"Main", "Home", "Jog", "Pan", "Truck", "Parallax"};

class Label{
  public:
    int16_t x,y;
    int16_t textColor, bgTextColor;
    uint8_t textSize;
    String content;
    boolean mode;

    Label(){}
    Label(String str, int16_t x, int16_t y, uint8_t csize, uint16_t frontTextColor, uint16_t backTextColor, boolean mode){
        this->x = x;
        this->y = y;
        this->textSize = csize;
        this->textColor = textColor;
        this->bgTextColor = backTextColor;
        this->content = str;
        this->mode = mode;
    }
};

class Button{
  public:
    MenuState navigateTarget;
    //picture information
    int16_t x1,x2,y1,y2;
    const uint8_t *color_buf;
    int16_t buf_size;

    boolean hasImage = false;

    Button(){};
    Button(uint8_t *color_buf, int16_t buf_size, int16_t x1, int16_t x2, int16_t y1, int16_t y2, boolean hasImage){

        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;

        this->hasImage = hasImage;
    }

    boolean is_pressed(int16_t px, int16_t py){
      return px > x1 && px < x2 && py > y1 && py < y2;
    }
};

class MenuItem{
  public:
    int16_t x1,x2,y1,y2;
    int16_t bgColor;
    Label label;
    Button interaction;

    MenuItem(){}
    MenuItem(int16_t x1, int16_t x2, int16_t y1, int16_t y2, int16_t bgColor){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->bgColor = bgColor;
    }

    boolean is_pressed(int16_t px, int16_t py){
      return interaction.is_pressed(px,py);
    }
      
};

class Menu{
  public:
    String value = "Data";
    MenuItem item;

    //Vector<MenuItem> menuItems;
};