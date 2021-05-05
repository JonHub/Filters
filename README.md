# Filters

**A realtime digital signal processing (DSP) library for Arduino.**

The Filters library implements several useful digital filters for real-time signal processing in microcontrollers.  These filters are easy-to-use, programmable versions of common analog signal processing filters, such as single-pole (RC) lowpass and highpass filters.  The library also includes two-pole filters  (Bessel and Butterworth), as well other "filters" to calculate running statistics, or return the time derivative of a signal.

A common usage of the Filters library to use a `LowPass` filter to smooth out values read continuously from an analog input pin, removing high-frequency noise and impoving the sampling resolution by averaging many samples.

The filters use floating point precision, and should be updated with new input values frequently and continuously (in a loop) for accuracy, but do not need to be updated at fixed intervals (updates can be asynchronous).  That is, Filters can be updated with new input values at essentially any rate, as long as they are the update frequency is much faster than the filter cut-off frequency.

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

* Update the filter value in a loop, by calling `.input( newValue )` on the filter.  Updates should happen frequently, for numerical stability and accuracy, but do not have to occur at fixed time intervals.

* To retrieve the value of the filter, call `.output()` on the filter.  The output is valid at any time, and contains the most up-to-date filtered values.

## Update (2021)

This code was released as an opensource project in 2015, and I have not been attending to it.  It appears that the code has become useful to the community, and gets a fair number of downloads / forks / etc.

First, I wanted to express a sincere   **Thank You** to GitHub, Arduino, and the opensource community, for keeping up interest in the project, and for the contributions.  I'll be updating the project with additional documentation and examples in the future.

The planned future work includes:

* [ ] Adding the code to the Arduino Library, to make it more widely available, and easier to install
* [ ] Adding additional user information (specifics on the various filters, and how to use).
* [ ] Adding additional examples
* [ ] Addressing any pending Issues on GitHub

Please be patient with progress and updates.

