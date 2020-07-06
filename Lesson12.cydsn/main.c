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

/*Detects if a letter is capitalized or not.*/
int isUpper(char ch){
    if(ch >= 'a' && ch <= 'z'){
            return 1;
    }else{
            return 0;
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    char received;
    char capitalized;
    
    UART_Start();
    UART_UartPutString("Hello World!");

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        received=UART_UartGetChar();
        if(isUpper(received)){
            capitalized=toupper(received); //Converts the character to capital letter (uppercase).
            UART_UartPutChar(capitalized);
        }
    }
}

/* [] END OF FILE */
