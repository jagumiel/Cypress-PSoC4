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

_Bool sleep = 0;

CY_ISR(Pin_SW2_Handler){
    sleep=(!sleep);
    if(sleep==0){
        UART_UartPutString("Awake!\r\n");
    }
    Pin_SW2_ClearInterrupt();
}

int main (void)
{
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    UART_Start();
    
    Pin_SW2_Int_StartEx(Pin_SW2_Handler);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
        if(sleep==1){
            UART_UartPutString("Sleeping...\r\n");
            CySysPmSleep();
        }
    }
}
