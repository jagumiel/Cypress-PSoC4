/* ====================== *
 * LED related functions. *
 * ====================== */


#include "project.h"
#include "alphabet.h"

_Bool increase=1;
uint16_t character = 0x0000;
uint16_t antichar  = 0x0000;
int dutyCMP = 5;
int charIndex=0;
int fadeIndex=0;

/* Sets the data into the display. It sends 
the 14-segments code to the driver via SPI */
void writeChar(uint16_t myChar){
    SPI_1_SpiUartWriteTxData(myChar);
    LE_Write(1);
    LE_Write(0);
}

/* This function is expected to get the different 
values stored in the "alphabet" array. */
void changeCharacterByOrder(){
    antichar = BLANK;
    character=ALPHANUMR_CHAR_TABLE[charIndex];
    if(charIndex<50){
        charIndex++;
    }else{
        charIndex=0;
    }
}

/* This functions looks for the 14-bit representation
   of the introduced character.*/
void changeCharacterByLetter(char myCharacter){
    antichar = BLANK;
    for(int i=0; i<50; i++){
        if(ALPHANUMR_CHAR_MATRIX[i][1]==myCharacter){
            character=ALPHANUMR_CHAR_MATRIX[i][0];
        }
    }
}

void changeFaddingCircle(){
    antichar    =  FADING_CIRCLE_MATRIX[fadeIndex][1];
    character   =  FADING_CIRCLE_MATRIX[fadeIndex][0];
    if(fadeIndex<6){
        fadeIndex++;
    }else{
        fadeIndex=0;
    }
}

void adjustBrightness(int pattern){//Changes the PWM comparator. (aka. Duty-Cycle).
    switch(pattern){
    	case 1: //Breathe effect. Brightness increases and decreases.
			if(increase){
                if(dutyCMP<50){
                    dutyCMP=dutyCMP+5;
                }else{
                    increase=0;
                }
            }else{
                 if(dutyCMP>5){
                    dutyCMP=dutyCMP-5;
                }else{
                    increase=1;
                }
            }
			break;
    	case 2: //Sawtooth effect. Brightness increases constantly from 5% to 90%.
			if(dutyCMP<90){
                dutyCMP=dutyCMP+5;
            }else{
                dutyCMP=5;
            }
    		break;
    	case 3: //Reverse sawtooth effect. Brightness decreases constantly from 90% to 5%.
			if(dutyCMP>10){
                dutyCMP=dutyCMP-5;
            }else{
                dutyCMP=95;
            }
			break;
    	default: //Intermittent.
			if(increase){
                dutyCMP=95;
                increase=0;
            }else{
                dutyCMP=5;
                increase=1;
            }
			break;
    }
    PWM_1_WriteCompare(dutyCMP);
}



/* [] END OF FILE */
