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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_0_Start();
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    
    uint8 sliderVal;
    uint8 oldSliderVal=0xFF;
    
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(!CapSense_IsBusy()){
            sliderVal=CapSense_GetCentroidPos(CapSense_LINEAR_SLIDERS_POS_FILTERS_MASK);
            if(sliderVal!=0xFF && sliderVal!=oldSliderVal){
                oldSliderVal=sliderVal;
            }
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
        
        if(oldSliderVal<64){
            PWM_0_WriteCompare(oldSliderVal*4);
            PWM_1_WriteCompare(0);
            PWM_2_WriteCompare(0);
            PWM_3_WriteCompare(0);
        }else if(oldSliderVal>63 && oldSliderVal<128){
            PWM_0_WriteCompare(255);
            PWM_1_WriteCompare(oldSliderVal*2);
            PWM_2_WriteCompare(0);
            PWM_3_WriteCompare(0);
        }else if(oldSliderVal>127 && oldSliderVal<192){
            PWM_0_WriteCompare(255);
            PWM_1_WriteCompare(255);
            PWM_2_WriteCompare((oldSliderVal/4)*3);
            PWM_3_WriteCompare(0);
        }else {
            PWM_0_WriteCompare(255);
            PWM_1_WriteCompare(255);
            PWM_2_WriteCompare(255);
            PWM_3_WriteCompare(oldSliderVal);
        }
            
        
        
        //PWM_3_WriteCompare(oldSliderVal);
        
        /* Place your application code here.
        Led_A_Write(1);
        CyDelay(100);
        Led_A_Write(0);
        Led_B_Write(1);
        CyDelay(100);
        Led_B_Write(0);
        Led_C_Write(1);
        CyDelay(100);
        Led_C_Write(0);
        Led_D_Write(1);
        CyDelay(100);
        Led_D_Write(0);
        CyDelay(500);*/
    }
}

/* [] END OF FILE */
