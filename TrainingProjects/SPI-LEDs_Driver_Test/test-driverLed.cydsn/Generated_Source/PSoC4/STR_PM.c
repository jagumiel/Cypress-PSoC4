/*******************************************************************************
* File Name: STR.c  
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
#include "STR.h"

static STR_BACKUP_STRUCT  STR_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: STR_Sleep
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
*  \snippet STR_SUT.c usage_STR_Sleep_Wakeup
*******************************************************************************/
void STR_Sleep(void)
{
    #if defined(STR__PC)
        STR_backup.pcState = STR_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            STR_backup.usbState = STR_CR1_REG;
            STR_USB_POWER_REG |= STR_USBIO_ENTER_SLEEP;
            STR_CR1_REG &= STR_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(STR__SIO)
        STR_backup.sioState = STR_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        STR_SIO_REG &= (uint32)(~STR_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: STR_Wakeup
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
*  Refer to STR_Sleep() for an example usage.
*******************************************************************************/
void STR_Wakeup(void)
{
    #if defined(STR__PC)
        STR_PC = STR_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            STR_USB_POWER_REG &= STR_USBIO_EXIT_SLEEP_PH1;
            STR_CR1_REG = STR_backup.usbState;
            STR_USB_POWER_REG &= STR_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(STR__SIO)
        STR_SIO_REG = STR_backup.sioState;
    #endif
}


/* [] END OF FILE */
