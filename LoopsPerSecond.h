/* 
 Loops Per Second
 
 For the Arduino.
 
 Compute the number of milliseconds each loop takes and keep statistics.
 Produce a count of the number of loops being run per second.
 This is always measuring the completion of the previous loop not the current
 loop's execution time.
 
 NOTE: By running this code it will reduce the time each loop takes to run and
       reduce the overall number of Loops Per Second an Arduino can process.

 This code is for debugging and diagnostics.  It is not intended to run in a
 production environment.

 created 28 Nov 2014
 modified 28 Nov 2014
 by Gregg Ubben
 
 This code is in the public domain.
 
 https://github.com/greggubben/LoopsPerSecond
 */

#ifndef LoopsPerSecond_h
#define LoopsPerSecond_h

#include "Arduino.h"

class LoopsPerSecond
{
public:
  LoopsPerSecond();
  void setupStart();                   // Call at begining of setup()
  void loopStart();                    // Call at begining of loop()
  unsigned long getSetupStart();       // Return setup() start time
  unsigned long getLoops();            // Return number of loops performed
  unsigned long getSetupTime();        // Return how long setup() took
  unsigned long getLastLoopDuration(); // Return how long the last loop() took
  unsigned long getMinLoopDuration();  // Return fastest loop() duration
  unsigned long getAveLoopDuration();  // Return average loop() duration
  unsigned long getMaxLoopDuration();  // Return slowest loop() duration
  unsigned long getLoopsPerSecond();   // Return average Loops run Per Second
private:
  // Start time in Millis when setup() was run.
  unsigned long setupStartMillis;

  // Start time in Millis when the first loop() was run.
  unsigned long loopStartMillis;

  // Start time in Millis when the last loop() was run.
  unsigned long lastLoopStartMillis;

  // Time in Millis of the last loop() run.
  unsigned long lastLoopDur;

  // Number of time loop() was run.
  unsigned long loops;

  // Time in Millis of the minimum loop() run.
  unsigned long minLoopDur;

  // Time in Millis of the maximum loop() run.
  unsigned long maxLoopDur;
};

#endif
