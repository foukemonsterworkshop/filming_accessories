#ifndef MENU_H
#define MENU_H

#include "DisplayShape.h"

class Button{
  public:
  
    DisplayShape display;
    ButtonAction action;

    String value;

    boolean *affectedBoolean;
    MenuState navigateTarget;
    
    boolean initialized = false;

    Button(){}
    Button(DisplayShape display, ButtonAction action){
        this->display = display;
        this->action = action;

        this->initialized = true;
    }
    Button(DisplayShape display, MenuState navigateTarget){
        this->display = display;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
        this->action = NAVIGATE;
    }
    Button(DisplayShape display, boolean *affectedBoolean){
        this->display = display;
        this->affectedBoolean = affectedBoolean;

        this->initialized = true;
        this->action = UPDATE_VALUE;
    }
    Button(DisplayShape display, boolean *affectedBoolean, ButtonAction action, MenuState navigateTarget){
        this->display = display;
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->navigateTarget = navigateTarget;

        this->initialized = true;
    }

    boolean is_pressed(int px, int py){
      return display.is_pressed(px, py);
    }

};
#endif