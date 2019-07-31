#ifndef FilterDerivative_h
#define FilterDerivative_h

// returns the derivative
struct FilterDerivative {
  long LastUS;
  float LastInput;
  float fs =-1;
  
  float Derivative;
  FilterDerivative(float fsam =-1);
  float input( float inVal );
  
  float output();
};

void testFilterDerivative();

#endif