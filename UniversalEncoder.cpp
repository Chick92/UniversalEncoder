/*
  UniversalEncoder.cpp - Library allowing any arduino with interrupt pins to utilise a rotary, quadrature encoder. Specifically for closd loop motor control.
  Created by Dr. Benjamin Bird, May, 2021
  Released into the public domain using MIT license
  API style reference - https://www.arduino.cc/en/Hacking/libraryTutorial

          prev.A+B   cur.A+B   (prev.AB+cur.AB)  Array   Encoder State
          -------   ---------   --------------   -----   -------------
            00         00            0000          0     stop/idle
            00         01            0001          1     CW,  0x01
            00         10            0010         -1     CCW, 0x02
            00         11            0011          0     invalid state
            01         00            0100         -1     CCW, 0x04
            01         01            0101          0     stop/idle
            01         10            0110          0     invalid state
            01         11            0111          1     CW, 0x07
            10         00            1000          1     CW, 0x08
            10         01            1001          0     invalid state
            10         10            1010          0     stop/idle
            10         11            1011         -1     CCW, 0x0B
            11         00            1100          0     invalid state
            11         01            1101         -1     CCW, 0x0D 
            11         10            1110          1     CW,  0x0E
            11         11            1111          0     stop/idle
          - CW  states 0b0001, 0b0111, 0b1000, 0b1110
          - CCW states 0b0010, 0b0100, 0b1011, 0b1101
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