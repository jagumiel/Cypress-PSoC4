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
    uint8 status;
    uint8 oldStatus;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();

    for(;;)
    {
        status=Status_Read();
        if(status!=oldStatus){
            oldStatus=status;
            UART_UartPutChar('0' + status);
            UART_UartPutChar('\r');
        }
    }
}

/* [] END OF FILE */
