
#include <Stepper.h>  // stepper motor library in arduino
 
Stepper stepMoto(4,7,6,2,1); // refers to the stepper motor 

const int VR = A3;  // variable resistor were attached to analog pin in arduino
const int sw = 10; // the switch attached to a digital pin of arduino

void setup(){
  pinMode(sw,INPUT_PULLUP); } // declare the switch as an input signal

int v = 0;  // inital value of speed

void loop(){ 
  if (digitalRead(sw) == 1) { // if the button wasn't pressed
   int val = analogRead(VR); // read the value of the variable resistor 
   if ( v != map(val, 0, 1023, 5, 100) ) { // convert from potentiometer into speed ranges and compare it to current value of speed, if not the same
    v = map(val, 0, 1023, 5, 100); // then make a new value of speed inside the range
    stepMoto.setSpeed(v); } // speed of the motor (rotation per minute
    stepMoto.step(1); } // move the motor 1 step per loop
   
  else stepMoto.step(0); } // if the button pressed the motor stop
