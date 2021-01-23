#include "Arduino.h"
#include "PinDebouncer.h"

void PinDebouncer::setup(int pin, void (*fn)()) 
{
  this->pin = pin;
  this->fn = fn;
  pinMode(this->pin, INPUT);
}

void PinDebouncer::run()
{
  int input = digitalRead(pin);
  unsigned long currentTime = millis();
  if(input == HIGH && previousInput == LOW && abs(currentTime - previousPressTimeMillis) > DEBOUNCE_TIME) {
    this->previousPressTimeMillis = currentTime;
    fn();
  }
  previousInput = input;
}
