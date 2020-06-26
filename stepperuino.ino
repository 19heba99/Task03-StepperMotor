
#include <Stepper.h>  
 
Stepper stepMoto(4,7,6,2,1); //creat an instance to use the library funs

const int VR = A3;  // the analog input pin attached to the cariable resistor
const int sw = 10;

void setup(){
  pinMode(sw,INPUT_PULLUP); }

int v = 0;  // inital value of speed

void loop(){ 
  if (digitalRead(sw) == 1) {
   int val = analogRead(VR); // read the value of the variable resistor 
   if ( v != map(val, 0, 1023, 5, 100) ) { // if speed was not equal to the value after converted in specific range
    v = map(val, 0, 1023, 5, 100); // then make them equivalent 
    stepMoto.setSpeed(v); }
   stepMoto.step(1); }
   
  else stepMoto.step(0); }
