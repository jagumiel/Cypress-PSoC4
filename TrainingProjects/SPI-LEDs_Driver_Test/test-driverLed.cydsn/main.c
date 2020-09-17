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
#include "alphabet.h"

void writeChar(uint16_t myChar){
    SPI_1_SpiUartWriteTxData(myChar);
    LE_Write(1);
    LE_Write(0);
}

int main(void){
    /* Enable global interrupts. */
    CyGlobalIntEnable;

    /* Component initialization/startup */
    Clock_1_Start();
    SPI_1_Start();
    

    for(;;){
        for(int i=0; i<10; i++){
            CyDelay(500);
            writeChar(ALPHANUMR_CHAR_TABLE[i]);
        }
    }
}

/* [] END OF FILE */
