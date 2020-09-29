#include "project.h"
#include <stdlib.h> //Needed for atoi() function.

int degreePosition = 0;
int rpmSpeed = 6;

void printMenu(){
    UART_UartPutString("=========Motor Control Terminal=========\n\r");
    UART_UartPutString("*************** Commands ***************\n\r");
    UART_UartPutString("\tSX: \tSets the speed.\n\r");
    UART_UartPutString("\t\tX must be comprehended\n\r");
    UART_UartPutString("\t\tbetween 1 and 6 rpms.\n\r");
    UART_UartPutString("\n\tMX: \tSets the position.\n\r");
    UART_UartPutString("\t\tX must be comprehended\n\r");
    UART_UartPutString("\t\tbetween 0º and 999º.\n\r");
    UART_UartPutString("========================================\n\r");
}

_Bool getData(){
	char charCMD;
	char charData;
	char cop;
	char arrayData[3];
	int i;
	
	charCMD = UART_UartGetChar();    // this command Gets then clears to 0u
	i = 0;
	
	if (charCMD == 'M' || charCMD == 'S'){
		if (charCMD == 'M'){
			cop = 'M';  //Movement
		}else{
			cop = 'S';  //Speed		
		}
		while (cop != 'X'){
			charData = UART_UartGetChar();
			if ((charData != 0u)){
				/* Only digits will be processed. Any other char will be omitted. */
				if( charData >= '0' && charData <= '9' ){
					arrayData[i] = charData;
					i++;
				}
			}
			/* If the array is completed, then the introduced value us printed on screen and the leds are setted. */
			if ((i==3 && cop=='M') ||(i==1 && cop=='S')){
                if(cop=='M'){
                    UART_UartPutString("The position is: ");
    				UART_UartPutString(arrayData);
    				UART_UartPutChar('\n');
    				UART_UartPutChar('\r');
                    degreePosition=atoi(arrayData);
                }else if (cop=='S'){
                    rpmSpeed=atoi(arrayData);
                    if(rpmSpeed>6){
                        rpmSpeed=6;
                        UART_UartPutString("Invalid speed. Setted to 6rpm.\r\n");
                    }else if(rpmSpeed<1){
                        rpmSpeed=1;
                        UART_UartPutString("Invalid speed. Setted to 1rpm.\r\n");
                    }else{
                        UART_UartPutString("The speed is: ");
        				UART_UartPutString(arrayData);
        				UART_UartPutChar('\n');
        				UART_UartPutChar('\r');
                    }
                
                }
				for(int i=0; i<3; i++)
					arrayData[i] = 0u;
				cop = 'X';//X means Undefined. Breaks loop condition.
			}
		}
		return 1;
	}
    return 0;
}
/* [] END OF FILE */
