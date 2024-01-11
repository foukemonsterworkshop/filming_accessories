#ifndef MENU_H
#define MENU_H

#include "DisplayShape.h"

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

    DisplayShape display;

    ButtonAction action;

    Label label;
    String value;

    boolean *affectedBoolean;
    
    boolean initialized = false;

    int active_color, inactive_color;
    String active_text, inactive_text;

    Button(){}
    Button(DisplayShape display, Label label, ButtonAction action){
        this->display = display;
        this->label = label;
        this->action = action;

        this->initialized = true;
    }
    Button(DisplayShape display, Label label, MenuState navigateTarget){
        this->display = display;
        this->label = label;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
        this->action = NAVIGATE;
    }
    Button(DisplayShape display, Label label, boolean *affectedBoolean, String active_text, String inactive_text){
        this->display = display;
        this->label = label;
        this->affectedBoolean = affectedBoolean;

        this->initialized = true;

        this->active_color = GREEN;
        this->inactive_color = RED;
        this->action = UPDATE_VALUE;

        this->active_text = active_text;
        this->inactive_text = inactive_text;
    }
    Button(DisplayShape display, Label label, boolean *affectedBoolean, ButtonAction action, MenuState navigateTarget){
        this->display = display;
        this->label = label;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
    }

    boolean is_pressed(int px, int py){
      return display.is_pressed(px, py);
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

#endif