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

    boolean is_pressed(int px, int py){
      return px > x1 && px < x2 && py > y1 && py < y2;
    }
};

class DisplayCircle{
  public:
    int x,y;
    int radius;

    int16_t bgColor;

    DisplayCircle(){}
    DisplayCircle(int x, int y, int radius, int16_t bgColor){
      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bgColor = bgColor;
    }
    boolean is_pressed(int px,int py){
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

    DisplayRectangle area;
    DisplayCircle c_area;

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
    Button(DisplayCircle c_area, ButtonAction action, MenuState navigateTarget){
        this->c_area = c_area;
        this->action = action;
        this->separateButton = separateButton;
    }

    boolean is_pressed(int px, int py){
      return area.is_pressed(px, py);
    }

    boolean is_c_pressed(int px, int py){
      return c_area.is_pressed(px, py);
    }
};

class HomeButton : public Button{
  public:
    boolean initialized = false;
    HomeButton(){}
    HomeButton(DisplayCircle c_area, ButtonAction action, MenuState navigateTarget) : Button(c_area, action, navigateTarget){
        this->initialized = true;
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

    boolean is_pressed(int px, int py){
      return button.is_pressed(px,py);
    }
};

class Menu{
  public:
    MenuItem *items;
    int size = 0;

    String name = "";

    HomeButton homeButton;

    Menu(){}
    Menu(MenuItem pItems[], int size, String name){
      items = pItems;
      this->size = size;
      this->name = name;
    }
    Menu(MenuItem pItems[], int size, String name, HomeButton homeButton){
      items = pItems;
      this->size = size;
      this->name = name;
      this->homeButton = homeButton;
    }
};