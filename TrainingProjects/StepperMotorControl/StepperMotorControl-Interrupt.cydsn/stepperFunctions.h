#include "project.h"


static int stepCounter = 0;    // Step Counter
int stepsPerRev = 4096; // Needed steps for 360 degrees turn.
int motorSpeed=2;       // Variable to set the speed.
int desiredPosition=0;  // Which is the position wanted for the motor.

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

void setSpeed(int speedRPMs){
    int actualSpeed=PWM_1_ReadCounter();
    _Bool speedUpdated=0;
    motorSpeed=((6*2)/speedRPMs);
    while(speedUpdated==0){
        if(actualSpeed<motorSpeed){
            PWM_1_WritePeriod(motorSpeed);
            speedUpdated=1;
        }
        actualSpeed=PWM_1_ReadCounter();
    }
}

void setPosition(int posDegrees){
    desiredPosition=(posDegrees*stepsPerRev)/360;
}
/* [] END OF FILE */
