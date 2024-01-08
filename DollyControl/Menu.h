class DisplayRectangle{
  public:
    int16_t x1,x2,y1,y2;
    int16_t width,height;

    DisplayRectangle(){}
    DisplayRectangle(int16_t x1,int16_t x2,int16_t y1,int16_t y2){
      this->x1=x1;
      this->x2=x2;
      this->y1=y1;
      this->y2=y2;
      this->width = x2-x1;
      this->height = y2-y1;
    }
};

class Label{
  public:
    int16_t x,y;
    int16_t textColor, bgTextColor;
    uint8_t textSize;
    String content;
    boolean mode;
    String extraData;

    Label(){}
    Label(String str, int16_t x, int16_t y, uint8_t csize, uint16_t frontTextColor, uint16_t backTextColor, boolean mode, String extraData){
        this->x = x;
        this->y = y;
        this->textSize = csize;
        this->textColor = textColor;
        this->bgTextColor = backTextColor;
        this->content = str;
        this->mode = mode;
        this->extraData = extraData;
    }
};

class Button{
  public:
    MenuState navigateTarget;
    DisplayRectangle area;
    boolean *affectedBoolean;
    ButtonAction action;

    Button(){}
    Button(DisplayRectangle area, boolean *affectedBoolean, ButtonAction action){
        this->area = area;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
    }

    boolean is_pressed(int16_t px, int16_t py){
      return px > area.x1 && px < area.x2 && py > area.y1 && py < area.y2;
    }
};

class MenuItem{
  public:
    int16_t bgColor;
    Label label;
    Button button;
    DisplayRectangle area;
    boolean initialized = false;

    MenuItem(){}
    MenuItem(DisplayRectangle area, int16_t bgColor, Label label, Button button){
        this->area = area;
        this->bgColor = bgColor;
        this->label = label;
        this->button = button;
        this->initialized = true;
    }

    boolean is_pressed(int16_t px, int16_t py){
      return button.is_pressed(px,py);
    }
};

class Menu{
  public:
    MenuItem *items;
    int size = 0;

    Menu(){}
    Menu(MenuItem pItems[], int size){
      items = pItems;
      this->size = size;
    }
};