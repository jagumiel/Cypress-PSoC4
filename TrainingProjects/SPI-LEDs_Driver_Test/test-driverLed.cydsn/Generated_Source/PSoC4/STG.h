/*******************************************************************************
* File Name: STG.h  
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

#if !defined(CY_PINS_STG_H) /* Pins STG_H */
#define CY_PINS_STG_H

#include "cytypes.h"
#include "cyfitter.h"
#include "STG_aliases.h"


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
} STG_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   STG_Read(void);
void    STG_Write(uint8 value);
uint8   STG_ReadDataReg(void);
#if defined(STG__PC) || (CY_PSOC4_4200L) 
    void    STG_SetDriveMode(uint8 mode);
#endif
void    STG_SetInterruptMode(uint16 position, uint16 mode);
uint8   STG_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void STG_Sleep(void); 
void STG_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(STG__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define STG_DRIVE_MODE_BITS        (3)
    #define STG_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - STG_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the STG_SetDriveMode() function.
         *  @{
         */
        #define STG_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define STG_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define STG_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define STG_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define STG_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define STG_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define STG_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define STG_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define STG_MASK               STG__MASK
#define STG_SHIFT              STG__SHIFT
#define STG_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in STG_SetInterruptMode() function.
     *  @{
     */
        #define STG_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define STG_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define STG_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define STG_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(STG__SIO)
    #define STG_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(STG__PC) && (CY_PSOC4_4200L)
    #define STG_USBIO_ENABLE               ((uint32)0x80000000u)
    #define STG_USBIO_DISABLE              ((uint32)(~STG_USBIO_ENABLE))
    #define STG_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define STG_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define STG_USBIO_ENTER_SLEEP          ((uint32)((1u << STG_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << STG_USBIO_SUSPEND_DEL_SHIFT)))
    #define STG_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << STG_USBIO_SUSPEND_SHIFT)))
    #define STG_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << STG_USBIO_SUSPEND_DEL_SHIFT)))
    #define STG_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(STG__PC)
    /* Port Configuration */
    #define STG_PC                 (* (reg32 *) STG__PC)
#endif
/* Pin State */
#define STG_PS                     (* (reg32 *) STG__PS)
/* Data Register */
#define STG_DR                     (* (reg32 *) STG__DR)
/* Input Buffer Disable Override */
#define STG_INP_DIS                (* (reg32 *) STG__PC2)

/* Interrupt configuration Registers */
#define STG_INTCFG                 (* (reg32 *) STG__INTCFG)
#define STG_INTSTAT                (* (reg32 *) STG__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define STG_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(STG__SIO)
    #define STG_SIO_REG            (* (reg32 *) STG__SIO)
#endif /* (STG__SIO_CFG) */

/* USBIO registers */
#if !defined(STG__PC) && (CY_PSOC4_4200L)
    #define STG_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define STG_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define STG_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define STG_DRIVE_MODE_SHIFT       (0x00u)
#define STG_DRIVE_MODE_MASK        (0x07u << STG_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins STG_H */


/* [] END OF FILE */
