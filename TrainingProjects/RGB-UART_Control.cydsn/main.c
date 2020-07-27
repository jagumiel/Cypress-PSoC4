#include "project.h"
#include <stdlib.h>

uint8_t red, green, blue = 0;

void getResults(char ledValue[]){
    /* Gets the scratch buffer data (string of chars) and places it into color variables (as integers). */
    char singleValAux[3];
    int i=0;
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

int main(){
    char ch;
    char ch1;
    char cop;
    char buffer[9];
    int8 tic;
    
    /*Initialization*/
    UART_Start();
    
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    
    turnOffLeds();
    /****************/
    
    UART_UartPutString("Introduce the values for the RGB colors using this pattern: Wrrrgggbbb.\n\r Example: W255090030\n\r");

    for (;;){
        ch = UART_UartGetChar();    // this command Gets then clears to 0u
        tic = 0;
        
        if (ch == 'W'){             //'W': Write.
			cop = 'Y';
            while (cop != 'X'){
				ch1 = UART_UartGetChar();
				if ((ch1 != 0u)){
                    /* Only digits will be processed. Any other char will be omitted. */
                    if( ch1 >= '0' && ch1 <= '9' ){
    					buffer[tic] = ch1;
    					tic++;
                    }
				}
                /* If the array is completed, then the introduced value us printed on screen and the leds are setted. */
                if (tic==9){
                    UART_UartPutString(buffer);
                    UART_UartPutChar('\r');
                    UART_UartPutChar('\n');
                    getResults(buffer);
                    for(int i=0; i<9; i++)
					    buffer[i] = 0u;
                    setLeds();
					cop = 'X';
				}
			}
		}
	}
}