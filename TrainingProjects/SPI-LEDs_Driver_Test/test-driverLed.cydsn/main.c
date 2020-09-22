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
#include "boardStatusLEDs.h"

/* Global Variables */
static uint16_t character = 0x0000;

int dutyCMP=5;
int j=0;
char charReceived='A';
char lastCharReceived='A';

/* Capsense Buttons */
int status=0; //Which is the CapSense Status? Button 1, 2...

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
    if(j<50){
        j++;
    }else{
        j=0;
    }
}

void changeCharacterByLetter(char myCharacter){
    for(int i=0; i<50; i++){
        if(ALPHANUMR_CHAR_MATRIX[i][1]==myCharacter){
            character=ALPHANUMR_CHAR_MATRIX[i][0];
        }
    }
}

int adjustBrightness(){ //Change the PWM comparator. (aka. Duty-Cycle).
    if(dutyCMP<100){
        dutyCMP=dutyCMP+5;
    }else{
        dutyCMP=5;
    }
    return(dutyCMP);
}


CY_ISR(TC_ISR_Handler){
    uint32 IrqSource=PWM_1_GetInterruptSource();
    
    if(IrqSource==PWM_1_INTR_MASK_CC_MATCH){
        writeChar(BLANK);
        if (msCounter<50){ //50=1 second
            msCounter++;
        }else{
            msCounter=0;
            if(status==1){
                changeCharacterByLetter(lastCharReceived);
            }else{
                changeCharacter();   
            }
        }
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_CC_MATCH);
    }else if(IrqSource==PWM_1_INTR_MASK_TC){
        writeChar(character);
        if(brightnessCounter<10){//Controls time to set the fadding effect.
            brightnessCounter++;
        }else{
            brightnessCounter=0;
            PWM_1_WriteCompare(adjustBrightness());
        }
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
    }
    PWM_1_ClearInterrupt(IrqSource);
}


int main(void){
    
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    /* PWM-Timer Interrupt */
    TC_ISR_StartEx(TC_ISR_Handler);

    /* Component initialization/startup */
    Clock_1_Start();
    SPI_1_Start();
    PWM_1_Start();
    UART_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    /*Turns off board LEDs*/
    ST_OFF;

    for(;;){
        
        /************ UART: GET CHARS FROM PC TERMINAL ************/
        charReceived=UART_UartGetChar();
        if((charReceived!=_NULL) && (charReceived!=lastCharReceived) && (status==1)){
            lastCharReceived=charReceived;
            UART_UartPutString("Introduce a character!\n\r");
        }
        /**********************************************************/

        
        /************ CAPSENSE: DETECTS IF A BUTTON WAS PRESSED ************/
        if(!CapSense_IsBusy()){
            if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)){
                STR_ON;
                status=1;
    		}
    		if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)){
                STG_ON;
                status=2;
    		}
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
        /*******************************************************************/
        
        
        /************ LIN: RECEIVES COMMANDS THROUGH THE AUTOMOTIVE PROTOCOL ************/
        
    }
}

/* [] END OF FILE */
