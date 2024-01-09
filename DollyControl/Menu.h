class DisplayShape{
  public:
    int x,x2,y,y2;

    DisplayType display_type;

    int width,height,radius;

    int16_t bgColor;

    DisplayShape(){}
    DisplayShape(int x1,int x2,int y1,int y2, int16_t bgColor){
      this->x=x;
      this->x2=x2;
      this->y=y;
      this->y2=y2;
      this->width = (x2-x);
      this->height = (y2-y);
      this->bgColor = bgColor;
      this->display_type = RECTANGLE;
    }

    DisplayShape(int x, int y, int radius, int16_t bgColor){
      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bgColor = bgColor;
      this->display_type = CIRCLE;
    }

    boolean is_pressed(int px, int py){
      switch(this->display_type){
        case RECTANGLE:
          is_r_pressed(px, py);
          break;
        case CIRCLE:
          is_c_pressed(px, py);
      }
    }

    boolean is_r_pressed(int px, int py){
      return px > x && px < x2 && py > y && py < y2;
    }

    boolean is_c_pressed(int px,int py){
    return (px > x-radius && px < x+radius) && (py > y-radius && py < y+radius);
    }
};

class Label{
  public:
    int x,y;
    int16_t textColor, bgTextColor;
    uint8_t textSize;
    String content;
    boolean mode;

    Label(){}
    Label(String str, int x, int y, uint8_t csize, uint16_t frontTextColor, uint16_t backTextColor, boolean mode){
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

    DisplayShape area;

    boolean *affectedBoolean;
    ButtonAction action;
    boolean separateButton = false;

    String debugStr = "";

    Button(){}
    Button(DisplayShape area, ButtonAction action, boolean separateButton){
        this->area = area;
        this->action = action;
        this->separateButton = separateButton;
    }
    Button(DisplayShape area, ButtonAction action, boolean separateButton, MenuState navigateTarget){
        this->area = area;
        this->action = action;
        this->separateButton = separateButton;
        this->navigateTarget = navigateTarget;
    }
    Button(DisplayShape area, boolean *affectedBoolean, ButtonAction action, boolean separateButton){
        this->area = area;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->separateButton = separateButton;
    }
    Button(DisplayShape area, boolean *affectedBoolean, ButtonAction action, boolean separateButton, MenuState navigateTarget){
        this->area = area;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->separateButton = separateButton;
        this->navigateTarget = navigateTarget;
    }
    
    boolean is_pressed(int px, int py){
      return area.is_pressed(px, py);
    }

};

class MenuItem{
  public:
    Label label;
    Button button;
    DisplayShape area;
    boolean initialized = false;
    String name;

    MenuItem(){}
    MenuItem(DisplayShape area, Label label, Button button, String name){
        this->area = area;
        this->label = label;
        this->button = button;
        this->initialized = true;
        this->name = name;
    }

    boolean is_pressed(int px, int py){
      return button.is_pressed(px,py);
    }
};

class Menu{
  public:
    MenuItem *items;
    int size = 0;

    String name = "";

    Menu(){}
    Menu(MenuItem pItems[], int size, String name){
      items = pItems;
      this->size = size;
      this->name = name;
    }
};