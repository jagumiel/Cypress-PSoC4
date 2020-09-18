/*******************************************************************************
* File Name: STG.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "STG.h"

static STG_BACKUP_STRUCT  STG_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: STG_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet STG_SUT.c usage_STG_Sleep_Wakeup
*******************************************************************************/
void STG_Sleep(void)
{
    #if defined(STG__PC)
        STG_backup.pcState = STG_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            STG_backup.usbState = STG_CR1_REG;
            STG_USB_POWER_REG |= STG_USBIO_ENTER_SLEEP;
            STG_CR1_REG &= STG_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(STG__SIO)
        STG_backup.sioState = STG_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        STG_SIO_REG &= (uint32)(~STG_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: STG_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to STG_Sleep() for an example usage.
*******************************************************************************/
void STG_Wakeup(void)
{
    #if defined(STG__PC)
        STG_PC = STG_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            STG_USB_POWER_REG &= STG_USBIO_EXIT_SLEEP_PH1;
            STG_CR1_REG = STG_backup.usbState;
            STG_USB_POWER_REG &= STG_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(STG__SIO)
        STG_SIO_REG = STG_backup.sioState;
    #endif
}


/* [] END OF FILE */
