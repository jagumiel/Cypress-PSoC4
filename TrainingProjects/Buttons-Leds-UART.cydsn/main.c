/*******************************************************************************
* File Name: main.c
*
* Version: 1.00
*
* Description:
*  This example tries to emulate the interior car lightning when a door is
*  opened. It turns on and off the leds depending on the door status, and it
*  uses a fading effect. It also inform through the UART about the status, as
*  if it was the car console screen.
*
*******************************************************************************/


#include <project.h>

/******************************************************************************
* Function Name: XDoorOpened
*******************************************************************************
*
* Summary:
*  Does something when the door has been opened. In this case, turns on a led.
*
******************************************************************************/
void leftDoorOpened(){
    if(Button_Left_Read()==1){
        UART_UartPutString("Left Door Opened.\r\n");
        for(int i=255; i>2; i--){
            PWM_Left_WriteCompare(i);
            CyDelay(5);
        }
    }else{
        UART_UartPutString("Left Door Closed.\r\n");
        for(int i=1; i<256; i++){
            PWM_Left_WriteCompare(i);
            CyDelay(5);
        }
    }
}

void rightDoorOpened(){
    if(Button_Right_Read()==1){
        UART_UartPutString("Right Door Opened.\r\n");
        for(int i=255; i>2; i--){
            PWM_Right_WriteCompare(i);
            CyDelay(5);
        }
    }else{
        UART_UartPutString("Right Door Closed.\r\n");
        for(int i=1; i<256; i++){
            PWM_Right_WriteCompare(i);
            CyDelay(5);
        }
    }
}


/******************************************************************************
* Function Name: Button_X_ISR_Handler
*******************************************************************************
*
* Summary:
*  Interrupt Service Routine. Check the Button (L/R) status and sets the flags.
*
******************************************************************************/
CY_ISR(Button_Left_ISR_Handler){
    leftDoorOpened();
    Button_Left_ClearInterrupt();
}

CY_ISR(Button_Right_ISR_Handler){
    rightDoorOpened();
    Button_Right_ClearInterrupt();
}


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Performs the following tasks:
*  - Start the components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{    
    /* Start the Components */
    UART_Start();
    PWM_Left_Start();
    PWM_Right_Start();
    
    /* Start ISRs */
    Button_Left_ISR_StartEx(Button_Left_ISR_Handler);
    Button_Right_ISR_StartEx(Button_Right_ISR_Handler);
    
    /* Enable global interrupts */
    CyGlobalIntEnable;

    
    for(;;)
    {
        /*No Code*/
    }
}