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

CY_ISR(Timer_Int_Handler){
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}

int main (void)
{
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    UART_Start();
    
    Timer_Int_StartEx(Timer_Int_Handler);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
        CyDelay(5000);
        UART_UartPutString("Sleeping... <Wake up in 10 seconds>\r\n");
        Timer_Start();
        CySysPmSleep();
        UART_UartPutString("Awake!\r\n");
    }
}
