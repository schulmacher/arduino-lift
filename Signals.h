// Signals.h
#ifndef Signals_h
#define Signals_h

#include <Arduino.h>

class Signals {
  private:
    int signalFloor1;
    int signalFloor2;

  public:
    Signals();

    void setSignalFloor1(int signal);
    int getSignalFloor1();

    void setSignalFloor2(int signal);
    int getSignalFloor2();
};

#endif