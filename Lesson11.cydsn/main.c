/* ========================================
 *
 * Led brightness is adjusted via I2C.
 *
 * ========================================
*/
#include "project.h"


int main(void)
{
    uint8 compare=0;
    uint8 i2cbuf[1];
    i2cbuf[0]=0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_Start();
    I2C_Start();
    I2C_EzI2CSetBuffer(1, 0, i2cbuf);

    for(;;)
    {
        i2cbuf[0]=PWM_ReadCounter();
    }
}

/* [] END OF FILE */
