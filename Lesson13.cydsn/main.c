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
    uint16 sliderVal;
    uint16 oldSliderVal=0xFFFF;
    char msg[10];
    
    UART_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(!CapSense_IsBusy()){
            sliderVal=CapSense_GetCentroidPos(CapSense_LINEAR_SLIDERS_POS_FILTERS_MASK);
            if(sliderVal!=0xFFFF && sliderVal!=oldSliderVal){
                sprintf(msg, "%3d\r\n", sliderVal);
                UART_UartPutString(msg);
                oldSliderVal=sliderVal;
            }
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
    }
}

/* [] END OF FILE */
