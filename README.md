# Filters

**A Realtime Digital Signal Processing (DSP) Library for Arduino.**

The Filters library implements several useful digital filters for real-time signal processing in microcontrollers.  These filters are easy-to-use, programmable versions of common analog signal processing filters, such as single-pole (RC) lowpass and highpass filters.  The library also includes two-pole lowpass filters (Bessel and Butterworth), as well other "filters" to calculate running statistics, or return the time derivative of a signal.

A common usage of the Filters library is to use a lowpass filter (or cascaded set of lowpass filters) to smooth out values read continuously from an analog input pin.  The filter output values can be read as needed, and are always valid.  This is a simple way to implement the standard oversample, filter, downsample patten common with in analog-to-digital conversion (ADC).

The filters use floating point precision, and should be updated with new input values frequently and continuously (in a loop) for accuracy., but do not need to be updated at fixed intervals (updates can be asynchronous).  That is, Filters can be updated with new input values at essentially any rate, as long as they are the updated much more frequently the filter cut-off frequency.

In addition to standard analog-like (recursive) filters, the library also includes additional filters useful for statistics and signal processing.  The `Derivative` filter returns the current time derivative (`dx/dt`) of the signal.  The `RunningStatistics` keeps track of the running `mean()` as well standard deviation `sigma()` of a signal, over some user-defined time window. 

Filters can also be cascaded, and the output of one filter can be used as the input of another filter.

## Installation (Ardunio, Energia, etc.)

Make sure you have the [Arduino](https://www.arduino.cc/en/software) environment installed on your system.

To install the Filters library, simply download (or clone) the `Filters`  folder (this repository) into the Arduino libraries directory.  The libraries directory resides in the default save location for Arduino sketches.  On a Mac, this is `Documents > Arduino > libraries`.  The `Filters` should be added there.

You can then use the filters in your sketches by adding

```cpp
#include <Filters.h>
```

## Using the Filters

There are some examples in `examples` directory.

The standard pattern for using a filter is:

* Declare a filter, and set any properties.

* Update the filter value continuously in a loop, by calling `.input( newValue )` on the filter.  Updates should happen frequently, for numerical stability and accuracy, but do not have to occur at fixed time intervals.

* To retrieve the value of the filter, call `.output()` on the filter.  The output is valid at any time, and contains the most up-to-date filtered values.

## Filter Types

The `Filters` library contains four different filter classes.  Please see the `.h` files for the various filters, for a full list of functions.

---

The **one pole filter** functions like an analog RC filter, with a corner specified by `fc`.  The filter is initialized to zero, but the initial value can be specified (useful for avoid jumps at startup, if the signal contains an offset).

```cpp
// constructor for one pole filter
FilterOnePole( FILTER_TYPE ft=LOWPASS, float fc=1.0, float initialValue=0 );
```

The `FILTER_TYPE` can be `LOWPASS` or `HIGHPASS`, which function like the traditional analog RC highpass and lowpass circuits.  The `INTEGRATOR` and `DIFFERENTIATOR` filter types are experimental.

---

The **two pole filter** functions like an analog RCL lowpass filter.  The filter values are specified by the `frequency0`, the natural undampened frequency of the filter, and the `qualityFactor`.  In practice, It is often more useful to create a two pole filter with the default values, and then set the filter values by calling `setAsFilter` on the newly created filter:

```cpp
// constructor for two pole filter
FilterTwoPole( float frequency0 = 1, float qualityFactor = 1, float xInit = 0);

// member function for specifying filter type and value
void setAsFilter( OSCILLATOR_TYPE ft, float frequency3db, float initialValue=0 );
```

The `OSCILLATOR_TYPE` can be `LOWPASS_BESSEL` or `LOWPASS_BUTTERWORTH`, which have slightly different phase frequency responses.  The corner frequency (cutoff frequency) is specified by the `frequency3db` parameter.

---

The **derivative** "filter" has the standard filter interface, but returns the latest time derivative `dx/dt` of the signal.

```cpp
// constructor for derivative filter
FilterDerivative()
```

---

The **running statistics** "filter" keeps a running value calculated for the `mean()` and `sigma()` (standard deviation) of a signal, over some specified running window.  This can be useful, for instance, too see if the value on a sensor is constant, or noisy/changing.

```cpp
// constructor for running statistics filter
RunningStatistics();
  
// member function to specify the window time
void setWindowSecs( float windowSecs );
```



## Update (2021)

This code was released as an opensource project in 2015, and I have not been attending to it.  It appears that the code has become useful to the community, and gets a fair number of downloads / forks / etc.

First, I wanted to express a sincere   **Thank You** to GitHub, Arduino, and the opensource community, for keeping up interest in the project, and for the contributions.  I'll be updating the project with additional documentation and examples in the future, to extend the usefulness of the project.

The planned future work includes:

* [ ] Adding the code to the Arduino Library, to make it more widely available, and easier to install
* [x] Adding additional user information (specifics on the various filters, and how to use).
* [ ] Adding additional examples
* [ ] Addressing any pending Issues on GitHub

Progress and updates will be posted to this site, and this is the main repository for the Filters code.

