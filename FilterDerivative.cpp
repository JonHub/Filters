#include "FilterDerivative.h"
#include "Arduino.h"

float FilterDerivative::FilterDerivative( float fsam ) {
  fs = fsam;
}
float FilterDerivative::input( float inVal ) {
  if (fs < 0.0) {
  long thisUS = micros();
  float dt = 1e-6*float(thisUS - LastUS);   // cast to float here, for math
  LastUS = thisUS;                          // update this now

  Derivative = (inVal-LastInput) / dt;
  }
  else{Derivative = (inVal-LastInput) * fs;}

  LastInput = inVal;
  return output();
}
  
float FilterDerivative::output() { return Derivative; }
  
void testFilterDerivative() {
  FilterDerivative der;
  
  while(true) {
    float t = 1e-6 * float( micros() );
    float value = 100*sin(TWO_PI*t);
    
    der.input(value);
    
    Serial.print( "\n" );
    Serial.print( value ); Serial.print( "\t");
    Serial.print( der.output() );
    
    delay(10);
  }
}