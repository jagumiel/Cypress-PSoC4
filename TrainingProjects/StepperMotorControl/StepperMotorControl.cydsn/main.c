/* ===========Stepper Motor Test===========
 *
 * This program is used with the 28BYJ-48
 * stepper motor and the ULN2003A driver.
 *
 * It is a demo to control a stepper motor
 * using UART communication. User can give
 * the program a desired angle and rotation
 * speed.
 *
 * ========================================
*/

#include "stepperFunctions.h"
#include "uartFunctions.h"


//Var Definition
int motorSpeed=2;       // Variable to set the speed.
int motorPosition=0;    // Which is the motor position.
int desiredPosition=0;  // Which is the position wanted for the motor.
int steps=0;            // How many steps are needed to reach the desired position.

void setPosition(int posDegrees){
    desiredPosition=(posDegrees*stepsPerRev)/360;
}

void setSpeed(int speedRPMs){
    motorSpeed=((6*2)/speedRPMs);
}
 
int main(void){
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    printMenu();
    for(;;){
        if(getData()==1){
            setPosition(degreePosition);
            setSpeed(rpmSpeed);
            /*Probably the following code could be replaced by an ISR.*/
            if(motorPosition<desiredPosition){
                steps=desiredPosition-motorPosition;
                for (int i=0; i<steps; i++){
                    clockwise();
                    CyDelay(motorSpeed);
                    motorPosition++;
                }
            }
            if(motorPosition>desiredPosition){
                steps=motorPosition-desiredPosition;
                for (int i = 0; i < steps; i++){
                    anticlockwise();
                    CyDelay(motorSpeed);
                    motorPosition--;
                }
            }
        }
        CyDelay(500);
    }
}

/* [] END OF FILE */