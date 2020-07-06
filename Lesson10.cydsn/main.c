/* ========================================
 *
 * The led dimmes depending on how long
 * the switch it has been pressed.
 * Faster means brighter.
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
    I2C_EzI2CSetBuffer(1, 1, i2cbuf);

    for(;;)
    {
        if(compare != i2cbuf[0]){
            compare=i2cbuf[0];
            PWM_WriteCompare(compare);
        }
    }
}

/* [] END OF FILE */
