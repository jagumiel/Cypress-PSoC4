/*******************************************************************************
* File Name: motorPin1.h  
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

#if !defined(CY_PINS_motorPin1_H) /* Pins motorPin1_H */
#define CY_PINS_motorPin1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "motorPin1_aliases.h"


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
} motorPin1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   motorPin1_Read(void);
void    motorPin1_Write(uint8 value);
uint8   motorPin1_ReadDataReg(void);
#if defined(motorPin1__PC) || (CY_PSOC4_4200L) 
    void    motorPin1_SetDriveMode(uint8 mode);
#endif
void    motorPin1_SetInterruptMode(uint16 position, uint16 mode);
uint8   motorPin1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void motorPin1_Sleep(void); 
void motorPin1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(motorPin1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define motorPin1_DRIVE_MODE_BITS        (3)
    #define motorPin1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - motorPin1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the motorPin1_SetDriveMode() function.
         *  @{
         */
        #define motorPin1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define motorPin1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define motorPin1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define motorPin1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define motorPin1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define motorPin1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define motorPin1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define motorPin1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define motorPin1_MASK               motorPin1__MASK
#define motorPin1_SHIFT              motorPin1__SHIFT
#define motorPin1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motorPin1_SetInterruptMode() function.
     *  @{
     */
        #define motorPin1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define motorPin1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define motorPin1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define motorPin1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(motorPin1__SIO)
    #define motorPin1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(motorPin1__PC) && (CY_PSOC4_4200L)
    #define motorPin1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define motorPin1_USBIO_DISABLE              ((uint32)(~motorPin1_USBIO_ENABLE))
    #define motorPin1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define motorPin1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define motorPin1_USBIO_ENTER_SLEEP          ((uint32)((1u << motorPin1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << motorPin1_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorPin1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << motorPin1_USBIO_SUSPEND_SHIFT)))
    #define motorPin1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << motorPin1_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorPin1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(motorPin1__PC)
    /* Port Configuration */
    #define motorPin1_PC                 (* (reg32 *) motorPin1__PC)
#endif
/* Pin State */
#define motorPin1_PS                     (* (reg32 *) motorPin1__PS)
/* Data Register */
#define motorPin1_DR                     (* (reg32 *) motorPin1__DR)
/* Input Buffer Disable Override */
#define motorPin1_INP_DIS                (* (reg32 *) motorPin1__PC2)

/* Interrupt configuration Registers */
#define motorPin1_INTCFG                 (* (reg32 *) motorPin1__INTCFG)
#define motorPin1_INTSTAT                (* (reg32 *) motorPin1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define motorPin1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(motorPin1__SIO)
    #define motorPin1_SIO_REG            (* (reg32 *) motorPin1__SIO)
#endif /* (motorPin1__SIO_CFG) */

/* USBIO registers */
#if !defined(motorPin1__PC) && (CY_PSOC4_4200L)
    #define motorPin1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define motorPin1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define motorPin1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define motorPin1_DRIVE_MODE_SHIFT       (0x00u)
#define motorPin1_DRIVE_MODE_MASK        (0x07u << motorPin1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins motorPin1_H */


/* [] END OF FILE */
