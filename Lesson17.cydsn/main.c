/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main (void)
{
    uint8 i2cbuf[1];
    i2cbuf[0]=0;
    CyGlobalIntEnable;      /* Enable global interrupts */
    I2C_Start();
    I2C_EzI2CSetBuffer(1, 1, i2cbuf);
    
    for(;;)
    {
        Output_Pin_0_Write(0); CyDelay(100);
        Output_Pin_0_Write(1); CyDelay(100);
        Output_Pin_0_Write(0); CyDelay(100);
        Output_Pin_0_Write(1); CyDelay(100);
        
        I2C_Sleep();
        CySysPmDeepSleep();
        I2C_Wakeup();
        
        CyDelay(500);
    }
}
