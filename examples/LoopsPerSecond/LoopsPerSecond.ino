/*
  Loops Per Second example.
  
  Example code to show how the Loops Per Second works.
  
  created 28 Nov 2014
  modified 28 Nov 2014
  by Gregg Ubben
 
  This code is in the public domain.
 
  https://github.com/greggubben/LoopsPerSecond
 */
#include <LoopsPerSecond.h>

LoopsPerSecond lps;

void setup() {
    lps.setupStart();
    Serial.begin(9600);
}

void loop() {
    lps.loopStart();
    
    // Print the results every 100 loops
    if ((lps.getLoops()%100) == 9) {
        Serial.print("     Setup Started at = ");
        Serial.print(lps.getSetupStart());
        Serial.println(" millis");
        Serial.print("           Setup Took = ");
        Serial.print(lps.getSetupTime());
        Serial.println(" millis");
        Serial.print("                Loops = ");
        Serial.print(lps.getLoops());
        Serial.println();
        Serial.print("   Last Loop Duration = ");
        Serial.print(lps.getLastLoopDuration());
        Serial.println(" millis");
        Serial.print("    Min Loop Duration = ");
        Serial.print(lps.getMinLoopDuration());
        Serial.println(" millis");
        Serial.print("Average Loop Duration = ");
        Serial.print(lps.getAveLoopDuration());
        Serial.println(" millis");
        Serial.print("    Max Loop Duration = ");
        Serial.print(lps.getMaxLoopDuration());
        Serial.println(" millis");
        Serial.print("     Loops Per Second = ");
        Serial.print(lps.getLoopsPerSecond());
        Serial.println();
        Serial.println();
        
    }
    
    // Create a random delay to simulate work.
    delay(random(500));
}
