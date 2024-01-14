// Fork.cpp
#include "Fork.h"
#include "UltraSoundMean.h"


int motor1pin1 = 4;
int motor1pin2 = 5;


Fork::Fork(UltraSoundMean *usDistanceInstance) {
  usDistance = usDistanceInstance;
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
}

void Fork::forward(int amount) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(amount);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  
}

void Fork::inward(int amount) {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(amount);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
}

