#include "project.h"
#include <stdlib.h>

uint8_t red, green, blue = 0;
char redChar [3];char greenChar [3];char blueChar [3];

void getResults(char ledValue[]){
    redChar[0]  = ledValue[0]; redChar[1]   = ledValue[1]; redChar[2]   = ledValue[2];
    greenChar[0]= ledValue[3]; greenChar[1] = ledValue[4]; greenChar[2] = ledValue[5];
    blueChar[0] = ledValue[6]; blueChar[1]  = ledValue[7]; blueChar[2]  = ledValue[8];
    
    red     = atoi(redChar);
    green   = atoi(greenChar);
    blue    = atoi(blueChar);
    
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
    
    UART_Start();
    
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    
    turnOffLeds();

    for (;;){
        ch = UART_UartGetChar();    // this command Gets then clears to 0u
        tic = 0;
        
        if (ch == 'W'){             //'W': Write.
			cop = 'Y';
            while (cop != 'X'){
				ch1 = UART_UartGetChar();
				if ((ch1 != 0u) && (ch1 != 'B')){
					buffer[tic] = ch1;
					tic++;
				}
				if (ch1 == 'B'){
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