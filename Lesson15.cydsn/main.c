/* ========================================
 *
 * In this lesson there is a counter.
 * It counts down from 2 to 0. So to make
 * the led change it is needed to push the
 * switch 3 times.
 *
 * ========================================
*/
#include "project.h"

#define NUM_CHANNELS (4)

int main(void)
{
    uint8 ctlval=0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_Start();

    for(;;)
    {
        Control_Write(ctlval);
        ctlval++;
        if(ctlval>=NUM_CHANNELS){
            ctlval=0;
        }
        CyDelay(500);
    }
}

/* [] END OF FILE */
