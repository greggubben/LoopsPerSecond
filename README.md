Simple Arduino program to calculate how many loops are being performed. It is intended to be used for dianostics and debugging. Keep in mind anything under test will have modified results and for that reason it is recommended not to use this code in a production environment.

To install this code follow the instructions at: http://arduino.cc/en/Guide/Libraries

Alternately you can manually place this code in the libraries directory where you store your sketches. The directory should look like the following:
```
<sketches location>/libaries/
    LoopsPerSecond/
        LoopsPerSecond.cpp
        LoopsPerSecond.h
        examples/LoopsPerSecond/
            LoopsPerSecond.ino
```
If you use the zip file from the right menu, I would suggest renaming the directory after it is installed to remove the "-master" that is added by GitHub.

If you prefer not to install the libraries you can place the *LoopsPerSecond.cpp* and *LoopsPerSecond.h* files in your sketch directory.

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
