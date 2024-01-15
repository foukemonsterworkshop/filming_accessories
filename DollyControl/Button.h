#ifndef BUTTON
#define BUTTON

#include "DisplayShape.h"

class Button{
  public:
    ButtonAction action;
    MenuState navigateTarget;

    char* name; 
    String value;

    boolean *affectedBoolean;
    boolean initialized = false;

    int x,y,x1,y1;

    Button(){}
    Button(DisplayShape display, ButtonAction action, char* name){
        this->action = action;

        this->name = name;

        this->initialized = true;
    }
    Button(DisplayShape display, MenuState navigateTarget, char* name){
        this->navigateTarget = navigateTarget;

        this->name = name;

        this->initialized = true;
        this->action = NAVIGATE;
    }
    Button(DisplayShape display, boolean *affectedBoolean, char* name){
        this->affectedBoolean = affectedBoolean;

        this->name = name;

        this->initialized = true;
        this->action = UPDATE_VALUE;
    }
    Button(DisplayShape display, boolean *affectedBoolean, ButtonAction action, MenuState navigateTarget, char* name){
        this->affectedBoolean = affectedBoolean;
        this->action = action;
        this->navigateTarget = navigateTarget;

        this->name = name;

        this->initialized = true;
    }

    boolean is_pressed(int px, int py){
      return px > x && px < x1 && py > y && py < y1;
    }

};
#endif
