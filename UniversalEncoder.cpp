/*
  UniversalEncoder.cpp - Library allowing any arduino with interrupt pins to utilise a rotary, quadrature encoder. Specifically for closd loop motor control.
  Created by Dr. Benjamin Bird, May, 2021
  Released into the public domain using MIT license
  API style reference - https://www.arduino.cc/en/Hacking/libraryTutorial
*/

#include "Arduino.h"
#include "UniversalEncoder.h"

UniversalEncoder::UniversalEncoder(int interrupt_1, int interrupt_2, int debug_led)
{
  pinMode(debug_led, OUTPUT);
  pinMode(interrupt_1, INPUT_PULLUP);
  pinMode(interrupt_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_1), counter, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interrupt_2), counter, CHANGE);

}

void UniversalEncoder::counter(){
  digitalWrite(debug_led, state);
  state = !state;
  char i_1_current, i_2_current;

  i_1_current = digitalRead(interrupt_1); 
  i_2_current = digitalRead(interrupt_2);

  // work out logic here 
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}