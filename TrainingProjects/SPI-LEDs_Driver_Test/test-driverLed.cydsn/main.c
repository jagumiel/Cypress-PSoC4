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
    PWM_1_Start();
    
    int time=200;
    int counter=0;
    int countCharChange=0;
    int i=0;
    uint16_t character=0x0000;
    uint16_t blank= 0x0000;

    for(;;){
        counter=0;
        PWM_1_WriteCompare(time);
        while(counter<500){ //12000 = 1 second
            if(PWM_Read()==1){
                writeChar(character);
                counter++;
            }else{
                writeChar(blank);
            }
            countCharChange++;
            if(countCharChange==24000){
                character=ALPHANUMR_CHAR_TABLE[i];
                countCharChange=0;
                if(i<50){
                    i++;
                }else{
                    i=0;
                }
            }
        }
        if(time<12000){
            time=time+200;
        }else{
            time=200;
        }
    }
}

/* [] END OF FILE */
