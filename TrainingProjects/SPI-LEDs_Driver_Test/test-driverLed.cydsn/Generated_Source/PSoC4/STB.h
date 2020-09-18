/*******************************************************************************
* File Name: STB.h  
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

#if !defined(CY_PINS_STB_H) /* Pins STB_H */
#define CY_PINS_STB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "STB_aliases.h"


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
} STB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   STB_Read(void);
void    STB_Write(uint8 value);
uint8   STB_ReadDataReg(void);
#if defined(STB__PC) || (CY_PSOC4_4200L) 
    void    STB_SetDriveMode(uint8 mode);
#endif
void    STB_SetInterruptMode(uint16 position, uint16 mode);
uint8   STB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void STB_Sleep(void); 
void STB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(STB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define STB_DRIVE_MODE_BITS        (3)
    #define STB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - STB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the STB_SetDriveMode() function.
         *  @{
         */
        #define STB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define STB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define STB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define STB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define STB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define STB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define STB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define STB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define STB_MASK               STB__MASK
#define STB_SHIFT              STB__SHIFT
#define STB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in STB_SetInterruptMode() function.
     *  @{
     */
        #define STB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define STB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define STB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define STB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(STB__SIO)
    #define STB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(STB__PC) && (CY_PSOC4_4200L)
    #define STB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define STB_USBIO_DISABLE              ((uint32)(~STB_USBIO_ENABLE))
    #define STB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define STB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define STB_USBIO_ENTER_SLEEP          ((uint32)((1u << STB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << STB_USBIO_SUSPEND_DEL_SHIFT)))
    #define STB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << STB_USBIO_SUSPEND_SHIFT)))
    #define STB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << STB_USBIO_SUSPEND_DEL_SHIFT)))
    #define STB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(STB__PC)
    /* Port Configuration */
    #define STB_PC                 (* (reg32 *) STB__PC)
#endif
/* Pin State */
#define STB_PS                     (* (reg32 *) STB__PS)
/* Data Register */
#define STB_DR                     (* (reg32 *) STB__DR)
/* Input Buffer Disable Override */
#define STB_INP_DIS                (* (reg32 *) STB__PC2)

/* Interrupt configuration Registers */
#define STB_INTCFG                 (* (reg32 *) STB__INTCFG)
#define STB_INTSTAT                (* (reg32 *) STB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define STB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(STB__SIO)
    #define STB_SIO_REG            (* (reg32 *) STB__SIO)
#endif /* (STB__SIO_CFG) */

/* USBIO registers */
#if !defined(STB__PC) && (CY_PSOC4_4200L)
    #define STB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define STB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define STB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define STB_DRIVE_MODE_SHIFT       (0x00u)
#define STB_DRIVE_MODE_MASK        (0x07u << STB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins STB_H */


/* [] END OF FILE */
