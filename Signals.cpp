// Signals.cpp
#include "Signals.h"

Signals::Signals() {
  signalFloor1 = 1;
  signalFloor2 = 0;
}

void Signals::setSignalFloor1(int signal) {
  signalFloor1 = signal;
}

int Signals::getSignalFloor1() {
  return signalFloor1;
}

void Signals::setSignalFloor2(int signal) {
  signalFloor2 = signal;
}

int Signals::getSignalFloor2() {
  return signalFloor2;
}