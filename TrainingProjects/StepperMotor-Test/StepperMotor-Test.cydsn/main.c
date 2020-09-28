/* ===========Stepper Motor Test===========
 *
 * This program is used with the 28BYJ-48
 * stepper motor and the ULN2003A driver.
 *
 * It is a demo to control a stepper motor.
 * it makes two 360 degrees movements CW
 * and CCW. It is a first example for more
 * complex future projects.
 *
 * ========================================
*/
#include "project.h"

//Var Definition
int motorSpeed  = 3;    // Variable to set the speed.
int stepCounter = 0;    // Step Counter
int stepsPerRev = 4076; // Needed step for 360 degrees turn.

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
 
int main(void){
    CyGlobalIntEnable; /* Enable global interrupts. */

    for(;;){
        for (int i = 0; i < stepsPerRev*2; i++){
            clockwise();
            CyDelay(motorSpeed);
        }
        CyDelay(500);
        for (int i = 0; i < stepsPerRev*2; i++){
            anticlockwise();
            CyDelay(motorSpeed);
        }
        CyDelay(500);
    }
}

/* [] END OF FILE */