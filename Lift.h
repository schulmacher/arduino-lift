// Lift.h
#ifndef Lift_h
#define Lift_h

#include <Arduino.h>
// #include <AccelStepper.h>
#include "UltraSoundMean.h"

class Lift {
  private:
    // bool homePositionSet;
    // int homePosition;
    // AccelStepper myStepper;
    UltraSoundMean *usDistance;

    int getStepSize(int maxValue, int modifier, float value);
    void moveToUsDistance(float distance);
    void execute();

  public:
    Lift(UltraSoundMean *usDistance);

    void up(int amount);
    void down(int amount);
    void floor2();
    void floor1();
};

#endif