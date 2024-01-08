class DisplayRectangle{
  public:
    int x1,x2,y1,y2;
    int width,height;

    DisplayRectangle(){}
    DisplayRectangle(int x1,int x2,int y1,int y2){
      this->x1=x1;
      this->x2=x2;
      this->y1=y1;
      this->y2=y2;
      this->width = (x2-x1);
      this->height = (y2-y1);
    }

    boolean is_pressed(int16_t px, int16_t py){
      return px > x1 && px < x2 && py > y1 && py < y2;
    }
};

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
    DisplayRectangle area;
    boolean *affectedBoolean;
    ButtonAction action;
    boolean separateButton = false;

    Button(){}
    Button(DisplayRectangle area, ButtonAction action, boolean separateButton){
        this->area = area;
        this->action = action;
        this->separateButton = separateButton;
    }
    Button(DisplayRectangle area, ButtonAction action, boolean separateButton, MenuState navigateTarget){
        this->area = area;
        this->action = action;
        this->separateButton = separateButton;
        this->navigateTarget = navigateTarget;
    }
    Button(DisplayRectangle area, boolean *affectedBoolean, ButtonAction action, boolean separateButton){
        this->area = area;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->separateButton = separateButton;
    }
    Button(DisplayRectangle area, boolean *affectedBoolean, ButtonAction action, boolean separateButton, MenuState navigateTarget){
        this->area = area;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->separateButton = separateButton;
        this->navigateTarget = navigateTarget;
    }

    boolean is_pressed(int16_t px, int16_t py){
      return area.is_pressed(px, py);
    }
};

class MenuItem{
  public:
    int16_t bgColor;
    Label label;
    Button button;
    DisplayRectangle area;
    boolean initialized = false;
    String name;

    MenuItem(){}
    MenuItem(DisplayRectangle area, int16_t bgColor, Label label, Button button, String name){
        this->area = area;
        this->bgColor = bgColor;
        this->label = label;
        this->button = button;
        this->initialized = true;
        this->name = name;
    }

    boolean is_pressed(int16_t px, int16_t py){
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