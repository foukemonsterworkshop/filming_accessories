#ifndef STEPPER
#define STEPPER

#include <Stepper.h>

class StepperOperation{
  public:
    Stepper stepper;

    Unit unit;
    float duration;
    int speed;

    String name = "";


};

#endif