// Lift.cpp
#include "Lift.h"
#include <AccelStepper.h>
#include "UltraSoundMean.h"

// Define step constant
#define MotorInterfaceType 4

AccelStepper myStepper(MotorInterfaceType, 8, 10, 9, 11);

Lift::Lift(UltraSoundMean *usDistanceInstance) {
  myStepper.setMaxSpeed(1000.0);
	myStepper.setAcceleration(400.0);
	myStepper.setSpeed(200.0);
  usDistance = usDistanceInstance;
}

void Lift::floor1() {
  moveToUsDistance(3);
}

void Lift::floor2() {
  moveToUsDistance(7);
}

void Lift::up(int amount) {
  myStepper.moveTo(amount + myStepper.currentPosition());
  execute();
}

void Lift::down(int amount) {
  myStepper.moveTo(myStepper.currentPosition() - amount);
  execute();
}

void Lift::execute() {
  // Serial.println("Current stepper");  
  // Serial.println(myStepper.currentPosition());  

  while (myStepper.distanceToGo() != 0) {
    myStepper.run();
  }
}

void Lift::moveToUsDistance(float toDistance) {
  while (abs(toDistance - usDistance->getDistance()) > 1) {
    float distanceLeft = toDistance - usDistance->getDistance();
    float absDistanceLeft = abs(distanceLeft);
    int steps = getStepSize(300, absDistanceLeft < 1 ? 40 : 100, absDistanceLeft);

    Serial.print("Distance left from ");
    Serial.print(toDistance);
    Serial.print(" :");
    Serial.println(distanceLeft);

    if (distanceLeft > 0) {
      up(steps);
    } else {
      down(steps);
    }
    usDistance->measure();
  }
}


int Lift::getStepSize(int maxValue, int modifier, float value) {
  // max 300
  // modifier 1 = 100
  // value = 1UltraSoundMean usDistance

  return max(min(maxValue, value * modifier), 10);
}


