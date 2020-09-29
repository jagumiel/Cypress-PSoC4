/* ===========Stepper Motor Test===========
 *
 * This program is used with the 28BYJ-48
 * stepper motor and the ULN2003A driver.
 *
 * It is a demo to control a stepper motor
 * using UART communication. User can give
 * the program a desired angle and rotation
 * speed. Control is done using ISR.
 *
 * ========================================
*/

#include "stepperFunctions.h"
#include "uartFunctions.h"

//Var Definition
int motorPosition=0;    // Which is the motor position.
int steps=0;            // How many steps are needed to reach the desired position.


CY_ISR(TC_ISR_Handler){
    uint32 IrqSource=PWM_1_GetInterruptSource();
    if(IrqSource==PWM_1_INTR_MASK_TC){
        if(motorPosition<desiredPosition){
            steps=desiredPosition-motorPosition;
            clockwise();
            motorPosition++;
        }
        if(motorPosition>desiredPosition){
            steps=motorPosition-desiredPosition;
            anticlockwise();
            motorPosition--;
        }
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
    }
    PWM_1_ClearInterrupt(IrqSource);
}

int main(void){
    CyGlobalIntEnable; /* Enable global interrupts. */
    TC_ISR_StartEx(TC_ISR_Handler);
    PWM_1_Start();
    UART_Start();
    printMenu();
    for(;;){
        if(getData()==1){
            setPosition(degreePosition);
            setSpeed(rpmSpeed);
        }
    }
}

/* [] END OF FILE */