/* ========================================
 * ============= TEST PROJECT =============
 * This project has been developed to test
 * the Cypress 4200 Family with UART Comm
 * and SPI protocol. A LED driver is used,
 * the proposal is to apply this control to
 * generate patterns on a LED Array.
 * ========================================
*/
#include "project.h"
#include "boardStatusLEDs.h"
#include "ledDriverFunctions.h"

/* Global Variables */
char charReceived='A';
char lastCharReceived='A';
int pattern=0;

/* Capsense Buttons */
int status=0; //Which is the CapSense Status? Button 1, 2...

/* Time Counters */
int cycleCounter=0;
int brightnessCounter=0;

/************************* Timer Interrupt *************************
 * Controls the character showed in the display and the brightness.
 * Alternating between Blank and Characters, following the PWM
 * pattern, sets the brightness.
 * _________________________________________________________________
 * TC = Terminal Counter. Interrupt activates when counter reachs
 *      its last value. (In this case, it counts to 100).
 * CC = Compare Counter. Interrupt activates when counter equals
 *      the compare value. (In this case, it counts to dutyCMP).
*/
CY_ISR(CC_TC_ISR_Handler){
    uint32 IrqSource=PWM_1_GetInterruptSource();
    
    if(IrqSource==PWM_1_INTR_MASK_CC_MATCH){
        writeChar(antichar);
        if (cycleCounter<50){ //50=1 second. Check PWM_1 Module. Clock input =5kHz. Terminal Count=100. 5000/100=50Hz. If we count to 50 rising edges it is 1 second. 
            cycleCounter++;
        }else{
            cycleCounter=0;
            if(status==1){
                changeCharacterByLetter(lastCharReceived);
            }else if(status==2){
                changeCharacterByOrder();
            }else{
                changeFaddingCircle();
            }
        }
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_CC_MATCH);
        
    }else if(IrqSource==PWM_1_INTR_MASK_TC){
        writeChar(character);
        if(brightnessCounter<10){//Controls time to set the fadding effect. Counting to 10 modifies the brightness every 0,2 seconds. 10/50=0,2
            brightnessCounter++;
        }else{
            brightnessCounter=0;
            adjustBrightness(pattern);
        }
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
    }
    PWM_1_ClearInterrupt(IrqSource);
}

/********* SW Interrupt *********
 * Changes the brightness pattern.
*/
CY_ISR(Pin_SW2_Handler){
    if (pattern<3){
        pattern++;
    }else{
        pattern=0;
    }
    Pin_SW2_ClearInterrupt();
}


int main(void){
    
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    
    /* PWM-Timer and SW2 Interrups */
    TC_ISR_StartEx(CC_TC_ISR_Handler);
    Pin_SW2_Int_StartEx(Pin_SW2_Handler);

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
        //TO-DO
    }
}

/* [] END OF FILE */
