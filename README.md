# A realtime digital signal processing (DSP) library for Arduino

Filters implements digital filters, which mimic the following common
analog filters:

 * **FiltersOnePole** implement a digital “RC” type filter, both
   highpass and lowpass.
 * **FiltersTwoPole** implements a digital lowpass “RLC” type of filter.
   Since an RLC filter is a just a dampened harmonic oscillator, the
   FiltersTwoPole class can be used to implement oscillators as well, by
   setting the quality factor and resonant frequency to the desired
   values.

In addition, the Filters library implements a class for keeping track of
a variable’s statistics in realtime.

 * **RunningStatistics** keeps track variable’s statistics, over a
   specified window of time (a “running window”), up to the current
   time. The class calculates variance and mean, as well as the derived
   values such as standard deviation (sigma) and coefficient of
   variation.

## Installation

Unzip the code, and place it in the Arduino/libraries directory. (If
Arduino is already started, it must be restarted to register the
library.) All of the filter classes can be added to the program by
declaring

```c++
#include <Filters.h>
```

The code can be dowloaded from [The GitHub
repository](https://github.com/JonHub/Filters).

## Usage

To use a filter, first declare an instance of the class. Various
parameters, such as the filter frequency, can be set by additional calls
to the filter class.

The filters are updated by continually calling the `input( newValue )`
function on the filter, and passing in a new value. For more
information, see the documentation (below) as well as the code examples
in the library.

The following code implements a simple one pole (RC type) lowpass
filter, which can be used for smoothing an analog input. This is
extremely useful if the input data is noisy, since the filter will
average together many reads into a single value.

```c++
// filters out changes faster that 5 Hz.
float filterFrequency = 5.0;

// create a one pole (RC) lowpass filter
FilterOnePole lowpassFilter( LOWPASS, filterFrequency );

while( true ) {
  lowpassFilter.input( analogRead( INPUT_PIN ) );
  // do something else
}
```

## Implementation Notes

The filters are implemented as IIR (infinite impulse response) filters,
which allows them to operate in real time. In a typical IIR
implementation, the time step between samples is constant, and known at
the beginning.

In this case, the time step between update can vary, and is computed
dynamically by taking the difference between the time of the current
`input()` and the last `input()` to the filter. In general, the filter
values will be more accurate if `input()` is called more frequently.

All of the filters remain stable, even if `input()` is not called
frequently enough. In the case of the single pole (RC type) filters, the
value of the filter will simply decay to it's resting value. The two
pole filters use a time-stepped simulation of a damped harmonic
oscillator. Normally, this type of simulation simulation can become
unstable if the `input()` is called infrequently.

The code prevents this by setting a maximum allowable timestep
(approximately a sixth of the resonant period of the oscillator). If the
`input()` in called less frequently that this, the time step is
throttled to this value, and the oscillator remains stable.

The filter classes use implemented using 32-bit floating point numbers
(`float`).
