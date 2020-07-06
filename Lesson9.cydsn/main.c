/* ========================================
 *
 * The led dimmes depending on how long
 * the switch it has been pressed.
 * Faster means brighter.
 *
 * ========================================
*/
#include "project.h"

CY_ISR (Timer_Int_Handler){
    uint16 counter = Timer_ReadCapture();
    if(counter>10000){
        counter = 10000;   
    }
    PWM_WriteCompare(counter);
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    //To-do. Catch the time between 2 switch touches to adjust the brightness.
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_Start();
    Timer_Start();
    
    Timer_Int_StartEx(Timer_Int_Handler);

    for(;;)
    {
        
    }
}

/* [] END OF FILE */
