#ifndef MENU_H
#define MENU_H

#include "DisplayShape.h"

class Label{
  public:
    int x,y;
    int textColor, bgTextColor;
    int textSize;
    uint8_t *content;
    boolean mode;

    boolean initialized = false;

    Label(){}
    Label(char str[], int x, int y, uint8_t csize, uint16_t frontTextColor, uint16_t backTextColor, boolean mode){
        this->x = x;
        this->y = y;
        this->textSize = csize;
        this->textColor = textColor;
        this->bgTextColor = backTextColor;
        this->content = str;
        this->mode = mode;

        this->initialized = true;
    }

    void set_content(char content[]){
      this->content = content;
    }
};

class Button{
  public:
    MenuState navigateTarget;

    DisplayShape *display;

    ButtonAction action;

    Label label;
    uint8_t *value;

    boolean *affectedBoolean;
    
    boolean initialized = false;

    int active_color, inactive_color;
    uint8_t *active_text, *inactive_text;

    Button(){}
    //minimal button
    Button(DisplayShape *display, Label label, ButtonAction action){
        this->display = display;
        this->label = label;
        this->action = action;

        this->initialized = true;
    }
    //navigation button
    Button(DisplayShape *display, Label label, MenuState navigateTarget){
        this->display = display;
        this->label = label;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
        
        this->action = NAVIGATE;
    }
    //Boolean state swap button
    Button(DisplayShape *display, Label label, boolean *affectedBoolean, uint8_t *active_text, uint8_t *inactive_text){
        this->display = display;
        this->label = label;
        this->affectedBoolean = affectedBoolean;
        
        this->initialized = true;

        this->active_color = GREEN;
        this->inactive_color = RED;

        this->active_text = active_text;
        this->inactive_text = inactive_text;

        this->action = UPDATE_VALUE;
    }

    boolean is_pressed(int px, int py){
      return this->display->is_pressed(px, py);
    }
};

class Menu{
  public:
    Button *buttons;
    Label *labels;
    //input field

    int button_size = 0;
    int label_size = 0;

    uint8_t *name;

    boolean test;

    Menu(){}
    Menu(Button buttons[], int button_size, Label labels[], int label_size, char name[]){
        this->buttons = buttons;
        this->labels = labels;
        
        this->name = name;

        this->button_size = sizeof(buttons);
        this->label_size = sizeof(labels);
    }

    Menu(Button buttons[], int button_size, char name[]){
        this->buttons = buttons;
        
        this->name = name;

        this->button_size = button_size;
        this->label_size = 0;
    }
};

#endif