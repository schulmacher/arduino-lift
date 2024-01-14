// Fork.h
#ifndef Fork_h
#define Fork_h

#include <Arduino.h>
#include "UltraSoundMean.h"

class Fork {
  private:
    UltraSoundMean *usDistance;

  public:
    Fork(UltraSoundMean *usDistance);

    void forward(int amount);
    void inward(int amount);
};

#endif