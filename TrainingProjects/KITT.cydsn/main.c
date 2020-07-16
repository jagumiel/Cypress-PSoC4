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
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        Led_A_Write(1);
        CyDelay(100);
        Led_A_Write(0);
        Led_B_Write(1);
        CyDelay(100);
        Led_B_Write(0);
        Led_C_Write(1);
        CyDelay(100);
        Led_C_Write(0);
        Led_D_Write(1);
        CyDelay(100);
        Led_D_Write(0);
        CyDelay(500);
    }
}

/* [] END OF FILE */
