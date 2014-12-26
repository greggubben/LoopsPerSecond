Simple Arduino program to calculate how many loops are being performed.

Created by: Gregg Ubben<br>
Created on: 28-Nov-2014<br>

The following functions gather the information about the loops:
```
setupStart()		// Called at the begining of setup()
loopStart()		// Called at the begining of each loop()
```

The following functions will return information about the loops:
```
getSetupStart()		// Return the setup() start time - usually 0
getSetupTime()		// How long setup() took to run
getLoops()		// Number of loops performed so far
getLastLoopDuration()	// Return how long the last loop() took
getMinLoopDuration()	// Return the fastest loop() duration
getAveLoopDuration()	// Return the average duration for all the loops()
getMaxLoopDuration()	// Return the slowest loop() duration
getLoopsPerSecond()	// Using average duration, compute how many loops()
			// can be performed in a second
```
