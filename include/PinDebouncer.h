#ifndef PinDebouncer_h
#define PinDebouncer_h

#include "Arduino.h"

class PinDebouncer
{
  private:
    const unsigned long DEBOUNCE_TIME = 180;
    unsigned long previousPressTimeMillis = 0;
    int previousInput = LOW;
    int pin = 0;
    void (*fn)();
      
  public:
    void setup(int pin, void (*fn)());
    void run();
};

#endif
