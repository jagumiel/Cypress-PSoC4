#include "project.h"


static int stepCounter = 0;    // Step Counter
int stepsPerRev = 4076; // Needed steps for 360 degrees turn.

//Half-Phase Sequence
const int numSteps = 8;
const _Bool stepsLookup[8][4] = {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,1},{1,0,0,1}}; 
 

void setOutput(int step){
    motorPin1_Write(stepsLookup[step][0]);
    motorPin2_Write(stepsLookup[step][1]);
    motorPin3_Write(stepsLookup[step][2]);
    motorPin4_Write(stepsLookup[step][3]);
}

void clockwise(){
    stepCounter++;
    if (stepCounter >= numSteps){
        stepCounter = 0;
    }
    setOutput(stepCounter);
}
 
void anticlockwise(){
    stepCounter--;
    if (stepCounter < 0){
        stepCounter = numSteps - 1;
    }
    setOutput(stepCounter);
}
/* [] END OF FILE */
