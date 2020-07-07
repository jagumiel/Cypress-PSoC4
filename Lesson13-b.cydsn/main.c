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
#include <stdio.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    int buttonsVal[5]={0,0,0,0,0};
    int buttonsLastVal[5]={0,0,0,0,0};
    char msg[10];
    
    UART_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets();


    for(;;)
    {
        if(!CapSense_IsBusy()){
            buttonsVal[0]=CapSense_CheckIsWidgetActive(CapSense_SENSOR_5_IS_ACTIVE);
            buttonsVal[1]=CapSense_CheckIsWidgetActive(CapSense_SENSOR_1_IS_ACTIVE); 
            buttonsVal[2]=CapSense_CheckIsWidgetActive(CapSense_SENSOR_2_IS_ACTIVE);
            buttonsVal[3]=CapSense_CheckIsWidgetActive(CapSense_SENSOR_3_IS_ACTIVE);
            buttonsVal[4]=CapSense_CheckIsWidgetActive(CapSense_SENSOR_4_IS_ACTIVE);
            
            if (memcmp(buttonsVal, buttonsLastVal, sizeof(buttonsVal))!=0){
                for(int i=0; i<5; i++){
                    if(buttonsVal[i]==1){
                        sprintf(msg, "Button %d pressed.\r\n", i);
                        UART_UartPutString(msg);
                    }
                }
                memcpy(buttonsLastVal, buttonsVal, sizeof(buttonsLastVal));
            }
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
    }
}

/* [] END OF FILE */
