/*******************************************************************************
* File Name: STR.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_STR_H) /* Pins STR_H */
#define CY_PINS_STR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "STR_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} STR_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   STR_Read(void);
void    STR_Write(uint8 value);
uint8   STR_ReadDataReg(void);
#if defined(STR__PC) || (CY_PSOC4_4200L) 
    void    STR_SetDriveMode(uint8 mode);
#endif
void    STR_SetInterruptMode(uint16 position, uint16 mode);
uint8   STR_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void STR_Sleep(void); 
void STR_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(STR__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define STR_DRIVE_MODE_BITS        (3)
    #define STR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - STR_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the STR_SetDriveMode() function.
         *  @{
         */
        #define STR_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define STR_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define STR_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define STR_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define STR_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define STR_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define STR_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define STR_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define STR_MASK               STR__MASK
#define STR_SHIFT              STR__SHIFT
#define STR_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in STR_SetInterruptMode() function.
     *  @{
     */
        #define STR_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define STR_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define STR_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define STR_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(STR__SIO)
    #define STR_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(STR__PC) && (CY_PSOC4_4200L)
    #define STR_USBIO_ENABLE               ((uint32)0x80000000u)
    #define STR_USBIO_DISABLE              ((uint32)(~STR_USBIO_ENABLE))
    #define STR_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define STR_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define STR_USBIO_ENTER_SLEEP          ((uint32)((1u << STR_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << STR_USBIO_SUSPEND_DEL_SHIFT)))
    #define STR_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << STR_USBIO_SUSPEND_SHIFT)))
    #define STR_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << STR_USBIO_SUSPEND_DEL_SHIFT)))
    #define STR_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(STR__PC)
    /* Port Configuration */
    #define STR_PC                 (* (reg32 *) STR__PC)
#endif
/* Pin State */
#define STR_PS                     (* (reg32 *) STR__PS)
/* Data Register */
#define STR_DR                     (* (reg32 *) STR__DR)
/* Input Buffer Disable Override */
#define STR_INP_DIS                (* (reg32 *) STR__PC2)

/* Interrupt configuration Registers */
#define STR_INTCFG                 (* (reg32 *) STR__INTCFG)
#define STR_INTSTAT                (* (reg32 *) STR__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define STR_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(STR__SIO)
    #define STR_SIO_REG            (* (reg32 *) STR__SIO)
#endif /* (STR__SIO_CFG) */

/* USBIO registers */
#if !defined(STR__PC) && (CY_PSOC4_4200L)
    #define STR_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define STR_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define STR_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define STR_DRIVE_MODE_SHIFT       (0x00u)
#define STR_DRIVE_MODE_MASK        (0x07u << STR_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins STR_H */


/* [] END OF FILE */
