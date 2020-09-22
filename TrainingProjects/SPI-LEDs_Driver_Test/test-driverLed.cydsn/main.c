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
//#include <stdio.h>

/* Global Variables */
int countCharChange=0;
uint16_t character = 0x0000;
uint16_t blank = 0x0000;
int dutyCMP=5;
int j=0;

//Botones de CapSense
int buttonsVal[2]={0,0};
int buttonsLastVal[2]={0,0};

//Time Counters
int msCounter=0;
int brightnessCounter=0;


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
    character=ALPHANUMR_CHAR_TABLE[j];
    countCharChange=0;
    if(j<50){
        j++;
    }else{
        j=0;
    }
}

void changeCharacterByLetter(){
    //uint16 myLetter1='A';
    //uint16 myLetter2='B';
    for(int i=0; i<50; i++){
        if(ALPHANUMR_CHAR_MATRIX[i][1]=='A'){
            character=ALPHANUMR_CHAR_MATRIX[i][0];
        }else{
            i++;
        }
    }
}

void adjustBrightness(){ //Change the PWM comparator. (aka. Duty-Cycle).
    if(dutyCMP<100){
        dutyCMP=dutyCMP+5;
    }else{
        dutyCMP=5;
    }
    PWM_1_WriteCompare(dutyCMP);
}


CY_ISR(TC_ISR_Handler){
    uint32 IrqSource=PWM_1_GetInterruptSource();
    
    if(IrqSource==PWM_1_INTR_MASK_CC_MATCH){
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_CC_MATCH);
        writeChar(blank);
        if (msCounter<50){ //50=1 second
            msCounter++;
        }else{
            msCounter=0;
            if(STR_Read()==1){
                changeCharacterByLetter();
            }else{
                changeCharacter();   
            }
        }
    }else if(IrqSource==PWM_1_INTR_MASK_TC){
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
        writeChar(character);
        if(brightnessCounter<10){//Controls time to set the fadding effect.
            brightnessCounter++;
        }else{
            brightnessCounter=0;
            adjustBrightness();
        }
    }
    PWM_1_ClearInterrupt(IrqSource);
}


int main(void){
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    TC_ISR_StartEx(TC_ISR_Handler);
    

    /* Component initialization/startup */
    Clock_1_Start();
    SPI_1_Start();
    PWM_1_Start();
    UART_Start();
    
    CapSense_Start();
    UART_UartPutString("Hola!\n\r");
    CapSense_InitializeAllBaselines();
    //CapSense_ScanEnabledWidgets();
    
    STR_Write(1);
    STG_Write(1);
    STB_Write(1);

    for(;;){

        if(!CapSense_IsBusy()){
            buttonsVal[0]=CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN);
            buttonsVal[1]=CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN); 
            
        if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)){
            STR_Write(0);
            STG_Write(1);
            UART_UartPutString("Hola1!\n\r");
		}
		if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)){
            STG_Write(0);
            STR_Write(1);
            UART_UartPutString("Hola2!\n\r");
		}
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
    }
}

/* [] END OF FILE */
