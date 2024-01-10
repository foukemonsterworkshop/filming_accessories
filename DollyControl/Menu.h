class DisplayShape{
  public:
    int x,x2,y,y2;

    DisplayType display_type;

    int width,height,radius;

    int16_t bg_color;

    DisplayShape(){}
    DisplayShape(int x,int x2,int y,int y2, int16_t bg_color){
      this->x=x;
      this->x2=x2;
      this->y=y;
      this->y2=y2;
      this->width = (x2-x);
      this->height = (y2-y);
      this->bg_color = bg_color;
      this->display_type = RECTANGLE;
    }

    DisplayShape(int x, int y, int radius, int16_t bg_color){
      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bg_color = bg_color;
      this->display_type = CIRCLE;
    }

    void set_color(int bg_color){
      this->bg_color= bg_color;
    }

    boolean is_pressed(int px, int py){
      switch(this->display_type){
        case RECTANGLE: return is_r_pressed(px, py);
        case CIRCLE: return is_c_pressed(px, py);
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
    int textColor, bgTextColor;
    int textSize;
    String content;
    boolean mode;

    boolean initialized = false;

    Label(){}
    Label(String str, int x, int y, uint8_t csize, uint16_t frontTextColor, uint16_t backTextColor, boolean mode){
        this->x = x;
        this->y = y;
        this->textSize = csize;
        this->textColor = textColor;
        this->bgTextColor = backTextColor;
        this->content = str;
        this->mode = mode;

        this->initialized = true;
    }

    void set_content(String content){
      this->content = content;
    }
};

class Button{
  public:
    MenuState navigateTarget;

    DisplayShape area;

    ButtonAction action;

    Label label;
    String value;

    boolean *affectedBoolean;
    
    boolean initialized = false;

    int active_color, inactive_color;
    String active_text, inactive_text;

    Button(){}
    Button(DisplayShape area, Label label, ButtonAction action){
        this->area = area;
        this->label = label;
        this->action = action;

        this->initialized = true;
    }
    Button(DisplayShape area, Label label, ButtonAction action, MenuState navigateTarget){
        this->area = area;
        this->label = label;
        this->action = action;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
    }
    Button(DisplayShape area, Label label, boolean *affectedBoolean, ButtonAction action, String active_text, String inactive_text){
        this->area = area;
        this->label = label;
        this->affectedBoolean = affectedBoolean;
        this->action = action;

        this->initialized = true;

        this->active_color = GREEN;
        this->inactive_color = RED;

        this->active_text = active_text;
        this->inactive_text = inactive_text;
    }
    Button(DisplayShape area, Label label, boolean *affectedBoolean, ButtonAction action, MenuState navigateTarget){
        this->area = area;
        this->label = label;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
    }

    boolean is_pressed(int px, int py){
      return area.is_pressed(px, py);
    }

};

class Menu{
  public:
    Button *buttons;
    Label *labels;

    int button_size = 0;
    int label_size = 0;

    String name = "";

    Menu(){}
    Menu(Button buttons[], int button_size, Label labels[], int label_size, String name){
        this->buttons = buttons;
        this->labels = labels;
        
        this->name = name;

        this->button_size = sizeof(buttons);
        this->label_size = sizeof(labels);
    }

    Menu(Button buttons[], int button_size, String name){
        this->buttons = buttons;
        
        this->name = name;

        this->button_size = button_size;
        this->label_size = 0;
    }

    Menu(Label labels[], int label_size, String name){
        this->buttons = buttons;
        this->labels = labels;
        
        this->name = name;

        this->button_size = 0;
        this->label_size = label_size;
    }
};