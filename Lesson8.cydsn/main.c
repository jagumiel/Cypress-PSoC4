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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_Start();
    int i=0;

    for(;;)
    {
        PWM_WriteCompare(i);
        CyDelay(50);
        i=i+50;
        if(i==9500)
            i=0;
    }
}

/* [] END OF FILE */
