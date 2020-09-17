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

/* Global Variables */
int countCharChange=0;
uint16_t character = 0x0000;
uint16_t blank = 0x0000;
int dutyCMP=200;
int i=0;


/* Sets the data into the display. It sends 
the 14-segments code to the driver via SPI */
void writeChar(uint16_t myChar){
    SPI_1_SpiUartWriteTxData(myChar);
    LE_Write(1);
    LE_Write(0);
}

/* This function is expected to get the different 
values stored in the "alphabet" array. */
void changeCharacter(){
    countCharChange++;
    if(countCharChange==24000){//When? 250ms.
        character=ALPHANUMR_CHAR_TABLE[i];
        countCharChange=0;
        if(i<50){
            i++;
        }else{
            i=0;
        }
    }   
}

void adjustBrightness(){ //Change the PWM comparator. (aka. Duty-Cycle).
    if(dutyCMP<12000){
        dutyCMP=dutyCMP+200;
    }else{
        dutyCMP=200;
    }   
}

int main(void){
    /* Enable global interrupts. */
    CyGlobalIntEnable;

    /* Component initialization/startup */
    Clock_1_Start();
    SPI_1_Start();
    PWM_1_Start();
    
    int counter=0;

    for(;;){
        counter=0;
        PWM_1_WriteCompare(dutyCMP);//Changes PWM comparator value (aka. Duty-Cycle)
        while(counter<500){ //12000 = 1 second
            if(PWM_Read()==1){
                writeChar(character);
                counter++;
            }else{
                writeChar(blank);
            }
            changeCharacter();
        }
        adjustBrightness();
    }
}

/* [] END OF FILE */
