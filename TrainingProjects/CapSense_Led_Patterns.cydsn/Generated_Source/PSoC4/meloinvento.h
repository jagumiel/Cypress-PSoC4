/*******************************************************************************
* File Name: meloinvento.h  
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

#if !defined(CY_PINS_meloinvento_H) /* Pins meloinvento_H */
#define CY_PINS_meloinvento_H

#include "cytypes.h"
#include "cyfitter.h"
#include "meloinvento_aliases.h"


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
} meloinvento_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   meloinvento_Read(void);
void    meloinvento_Write(uint8 value);
uint8   meloinvento_ReadDataReg(void);
#if defined(meloinvento__PC) || (CY_PSOC4_4200L) 
    void    meloinvento_SetDriveMode(uint8 mode);
#endif
void    meloinvento_SetInterruptMode(uint16 position, uint16 mode);
uint8   meloinvento_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void meloinvento_Sleep(void); 
void meloinvento_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(meloinvento__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define meloinvento_DRIVE_MODE_BITS        (3)
    #define meloinvento_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - meloinvento_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the meloinvento_SetDriveMode() function.
         *  @{
         */
        #define meloinvento_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define meloinvento_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define meloinvento_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define meloinvento_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define meloinvento_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define meloinvento_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define meloinvento_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define meloinvento_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define meloinvento_MASK               meloinvento__MASK
#define meloinvento_SHIFT              meloinvento__SHIFT
#define meloinvento_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in meloinvento_SetInterruptMode() function.
     *  @{
     */
        #define meloinvento_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define meloinvento_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define meloinvento_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define meloinvento_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(meloinvento__SIO)
    #define meloinvento_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(meloinvento__PC) && (CY_PSOC4_4200L)
    #define meloinvento_USBIO_ENABLE               ((uint32)0x80000000u)
    #define meloinvento_USBIO_DISABLE              ((uint32)(~meloinvento_USBIO_ENABLE))
    #define meloinvento_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define meloinvento_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define meloinvento_USBIO_ENTER_SLEEP          ((uint32)((1u << meloinvento_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << meloinvento_USBIO_SUSPEND_DEL_SHIFT)))
    #define meloinvento_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << meloinvento_USBIO_SUSPEND_SHIFT)))
    #define meloinvento_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << meloinvento_USBIO_SUSPEND_DEL_SHIFT)))
    #define meloinvento_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(meloinvento__PC)
    /* Port Configuration */
    #define meloinvento_PC                 (* (reg32 *) meloinvento__PC)
#endif
/* Pin State */
#define meloinvento_PS                     (* (reg32 *) meloinvento__PS)
/* Data Register */
#define meloinvento_DR                     (* (reg32 *) meloinvento__DR)
/* Input Buffer Disable Override */
#define meloinvento_INP_DIS                (* (reg32 *) meloinvento__PC2)

/* Interrupt configuration Registers */
#define meloinvento_INTCFG                 (* (reg32 *) meloinvento__INTCFG)
#define meloinvento_INTSTAT                (* (reg32 *) meloinvento__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define meloinvento_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(meloinvento__SIO)
    #define meloinvento_SIO_REG            (* (reg32 *) meloinvento__SIO)
#endif /* (meloinvento__SIO_CFG) */

/* USBIO registers */
#if !defined(meloinvento__PC) && (CY_PSOC4_4200L)
    #define meloinvento_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define meloinvento_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define meloinvento_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define meloinvento_DRIVE_MODE_SHIFT       (0x00u)
#define meloinvento_DRIVE_MODE_MASK        (0x07u << meloinvento_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins meloinvento_H */


/* [] END OF FILE */
