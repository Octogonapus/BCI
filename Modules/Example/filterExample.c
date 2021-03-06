/**
 * This is a tuorial for how to use the basic features of filter. For
 * extra reference, see BCI\Modules\Core\filter.h
 */

//We will have a quadrature encoder for the filter to filter
#pragma config(Sensor, dgtl7,  myQuad,  sensorQuadEncoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "..\..\BCI.h"

EMAFilter myFilter; //Make an exponential moving average filter

task main()
{
  //Initialize our filter
  filter_Init_EMA(&myFilter);

  //Print the filtered output of myQuad to the debug stream
  writeDebugStreamLine("Filtered Value: %d",
                       filter_EMA(&myFilter, SensorValue[myQuad], 0.1));
}
