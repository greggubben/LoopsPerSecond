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
#include "LoopsPerSecond.h"
#include "Arduino.h"

LoopsPerSecond::LoopsPerSecond() {
    setupStartMillis = 0;
    loopStartMillis = 0;
    lastLoopStartMillis = 0;
    lastLoopDur = 0;
    loops = 0;
    minLoopDur = 0;
    maxLoopDur = 0;
}

/*
  Called when the setup routine starts.
  This records when the program is started.
 */
void LoopsPerSecond::setupStart() {
    setupStartMillis = millis();
}

/*
  Called when the loop routine starts.
  This records when the loop is started.
 */
void LoopsPerSecond::loopStart() {
    unsigned long thisLoopMillis = millis();
    if (loopStartMillis == 0) {
        loopStartMillis = thisLoopMillis;
    }
    else if (lastLoopStartMillis == 0) {
        lastLoopStartMillis = thisLoopMillis;
        lastLoopDur = lastLoopStartMillis - loopStartMillis;
        minLoopDur = lastLoopDur;
        maxLoopDur = lastLoopDur;
        loops++;
    }
    else {
        lastLoopDur = thisLoopMillis - lastLoopStartMillis;
        lastLoopStartMillis = thisLoopMillis;
        if (lastLoopDur < minLoopDur) minLoopDur = lastLoopDur;
        if (lastLoopDur > maxLoopDur) maxLoopDur = lastLoopDur;
        loops++;
    }
}

/*
  Return the time in millis when setup was started.
 */
unsigned long LoopsPerSecond::getSetupStart() {
    return setupStartMillis;
}

/*
  Return the number of loops performed.
 */
unsigned long LoopsPerSecond::getLoops() {
    return loops;
}

/*
  Return the time in millis the setup function took to execute.
 */
unsigned long LoopsPerSecond::getSetupTime() {
    if (setupStartMillis != 0 && loopStartMillis != 0) {
        return loopStartMillis - setupStartMillis;
    }
    else {
        return 0;
    }
}

/*
  Return the time in millis the last loop function took to execute.
 */
unsigned long LoopsPerSecond::getLastLoopDuration() {
    return lastLoopDur;
}

/*
  Return the time in millis the fastest loop function took to execute.
 */
unsigned long LoopsPerSecond::getMinLoopDuration() {
    return minLoopDur;
}

/*
  Return the time in millis the slowest loop function took to execute.
 */
unsigned long LoopsPerSecond::getMaxLoopDuration() {
    return maxLoopDur;
}

/*
  Return the time in millis the average loop function took to execute.
 */
unsigned long LoopsPerSecond::getAveLoopDuration() {
    if (loops != 0) {
        return (lastLoopStartMillis - loopStartMillis)/loops;
    }
    else {
        return 0;
    }
}

/*
  Return the calculated average loops run in a second.
 */
unsigned long LoopsPerSecond::getLoopsPerSecond() {
    unsigned long aveLoopTime = getAveLoopDuration();
    if (aveLoopTime != 0) {
        return 1000ul / aveLoopTime;
    }
    else {
        return 0;
    }
}


