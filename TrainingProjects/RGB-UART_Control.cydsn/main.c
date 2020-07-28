#include "project.h"
#include <stdlib.h> //Needed for atoi() function.

uint8_t red, green, blue = 0;

void getResults(char cmd, char ledValue[]){
    /* Gets the scratch buffer data (string of chars) and places it into color variables (as integers). */
    char singleValAux[3];
    int i=0;
    if(cmd=='W'){
        for(int j=0; j<3; j++){
            singleValAux[j]=ledValue[i];
            i++;
        }
        red = atoi(singleValAux);
        for(int j=0; j<3; j++){
            singleValAux[j]=ledValue[i];
            i++;
        }
        green = atoi(singleValAux);
        for(int j=0; j<3; j++){
            singleValAux[j]=ledValue[i];
            i++;
        }
        blue = atoi(singleValAux);
    }else{
        /* Does exactly the same, but in this case, it only sets 1 value instead of the three RGB values. */
        for(int j=0; j<3; j++){
            singleValAux[j]=ledValue[i];
            i++;
        }
        if(cmd=='R'){
            red = atoi(singleValAux);
        }else if(cmd=='G'){
            green = atoi(singleValAux);
        }else{
            blue = atoi(singleValAux);
        }
    }
    
    /*Numbers must be comprehended between 0-255. If they are greater than 255 are setted to the max value.*/
    if (red > 255)   red    = 255;
    if (green > 255) green  = 255;
    if (blue > 255)  blue   = 255;
}

void setLeds(){
    PWM_1_WriteCompare(red);
    PWM_2_WriteCompare(green);
    PWM_3_WriteCompare(blue);
}

void turnOffLeds(){
    PWM_1_WriteCompare(0);
    PWM_2_WriteCompare(0);
    PWM_3_WriteCompare(0);
}

_Bool getData(){
	char charCMD;
	char charData;
	char cop;
	char colorData[9];
	int8 i;
	
	charCMD = UART_UartGetChar();    // this command Gets then clears to 0u
	i = 0;
	
	if (charCMD == 'W' || charCMD == 'R' || charCMD == 'G' || charCMD == 'B'){
		if (charCMD == 'W'){
			cop = 'M';  //Multiple Data
		}else{
			cop = 'S';  //Single Data		
		}
		while (cop != 'X'){
			charData = UART_UartGetChar();
			if ((charData != 0u)){
				/* Only digits will be processed. Any other char will be omitted. */
				if( charData >= '0' && charData <= '9' ){
					colorData[i] = charData;
					i++;
				}
			}
			/* If the array is completed, then the introduced value us printed on screen and the leds are setted. */
			if ((i==9 && cop=='M') ||(i==3 && cop=='S')){
				UART_UartPutString(colorData);
				UART_UartPutChar('\r');
				UART_UartPutChar('\n');
				getResults(charCMD, colorData);
				for(int i=0; i<9; i++)
					colorData[i] = 0u;
				//setLeds();
				cop = 'X';//X means Undefined. Breaks loop condition.
			}
		}
		return 1;
	}
    return 0;
}

int main(){
    
    /*Initialization*/
    UART_Start();
    
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    
    turnOffLeds();
    /****************/
    
    UART_UartPutString("Introduce the values for the RGB colors using this pattern: Wrrrgggbbb.\n\r Example: W255090030\n\r");
    UART_UartPutString("It is also possible to change just one value using the following pattern: (R/G/B)xxx.\n\r Example: R124\n\r");

    for (;;){
        if(getData()==1){
            setLeds();
        }
	}
}