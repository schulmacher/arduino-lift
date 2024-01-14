// UltraSoundMean.h
#ifndef UltraSoundMean_h
#define UltraSoundMean_h

#include <Arduino.h>

class UltraSoundMean {
  private:
    int _echoPin;
    int _triggerPin;

    float duration;
    float distance1;
    float distance2;
    float distance3;
    float prevDistance;
    // float gatheredDistance[5];

    float readDistance();

  public:
    UltraSoundMean(int echoPin, int triggerPin);
    void measure();
    float getDistance();
};

#endif