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

CY_ISR(Counter_Int_Handler){
    Pin_Green_Write(~Pin_Green_Read());   
    Counter_ClearInterrupt(Counter_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Counter_Start();
    Counter_Int_StartEx(Counter_Int_Handler);
    

    for(;;)
    {
        /*No Code!*/
    }
}

/* [] END OF FILE */
