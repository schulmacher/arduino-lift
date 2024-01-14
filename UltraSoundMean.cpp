// UltraSoundMean.cpp
#include "UltraSoundMean.h"

UltraSoundMean::UltraSoundMean(int echoPin, int triggerPin) {
  _echoPin = echoPin;
  _triggerPin = triggerPin;

  pinMode(_triggerPin, OUTPUT);  
	pinMode(_echoPin, INPUT);

  duration = 0.0;
  distance1 = 0.0;
  prevDistance = 0.0;
  // gatheredDistance[5] = {0.0};
}

// // qsort requires you to create a sort function
// int sort_desc(const void *cmp1, const void *cmp2)
// {
//   // Need to cast the void * to int *
//   int a = *((float *)cmp1);
//   int b = *((float *)cmp2);
//   // The comparison
//   return a > b ? -1 : (a < b ? 1 : 0);
//   // A simpler, probably faster way:
//   //return b - a;
// }

void UltraSoundMean::measure() {
  prevDistance = distance1;
  // int distance1 = readDistance();
  // int distance2 = readDistance();
  // int distance3 = readDistance();
  // int distance4 = readDistance();

  // Serial.print("distances: ");
  // Serial.print(distance1);
  // Serial.print(" ");
  // for (int i = 0; i < 5; i++) {
  //   gatheredDistance[i] = readDistance();
  // }
  // qsort(gatheredDistance, 5, 5, sort_desc);

  distance1 = readDistance();
  // distance2 = readDistance();
  // distance3 = readDistance();
}

float UltraSoundMean::readDistance() {
  digitalWrite(_triggerPin, LOW);  
	delayMicroseconds(2);
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_triggerPin, LOW);  
  duration = pulseIn(_echoPin, HIGH);

  return (duration*.0343)/2;
}

float UltraSoundMean::getDistance() {
  return distance1;
  // if (distance1 > distance2 && distance1 < distance3) {
  //   return distance1;
  // } else if (distance2 > distance1 && distance2 < distance3) {
  //   return distance2;
  // } else {
  //   return distance3;
  // }
}
