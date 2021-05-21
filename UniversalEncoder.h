/*
  UniversalEncoder.cpp - Library allowing any arduino with interrupt pins to utilise a rotary, quadrature encoder. Specifically for closd loop motor control.
  Created by Dr. Benjamin Bird, May, 2021
  Released into the public domain using MIT license
  API style reference - https://www.arduino.cc/en/Hacking/libraryTutorial
*/
#ifndef UniversalEncoder_h
#define UniversalEncoder_h

#include "Arduino.h"

class UniversalEncoder
{
  public:
    UniversalEncoder(int pin1, int pin2);
    void dot();
    void dash();
  private:
    int _pin1;
    int _pin2;
    char state = 0;
    static char i_1_previous = 0;
    static char i_2_previous = 0;
};

#endif