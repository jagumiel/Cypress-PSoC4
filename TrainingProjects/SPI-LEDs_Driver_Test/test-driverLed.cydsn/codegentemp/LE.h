/*******************************************************************************
* File Name: LE.h  
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

#if !defined(CY_PINS_LE_H) /* Pins LE_H */
#define CY_PINS_LE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LE_aliases.h"


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
} LE_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LE_Read(void);
void    LE_Write(uint8 value);
uint8   LE_ReadDataReg(void);
#if defined(LE__PC) || (CY_PSOC4_4200L) 
    void    LE_SetDriveMode(uint8 mode);
#endif
void    LE_SetInterruptMode(uint16 position, uint16 mode);
uint8   LE_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LE_Sleep(void); 
void LE_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LE__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LE_DRIVE_MODE_BITS        (3)
    #define LE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LE_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LE_SetDriveMode() function.
         *  @{
         */
        #define LE_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LE_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LE_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LE_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LE_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LE_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LE_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LE_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LE_MASK               LE__MASK
#define LE_SHIFT              LE__SHIFT
#define LE_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LE_SetInterruptMode() function.
     *  @{
     */
        #define LE_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LE_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LE_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LE_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LE__SIO)
    #define LE_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LE__PC) && (CY_PSOC4_4200L)
    #define LE_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LE_USBIO_DISABLE              ((uint32)(~LE_USBIO_ENABLE))
    #define LE_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LE_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LE_USBIO_ENTER_SLEEP          ((uint32)((1u << LE_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LE_USBIO_SUSPEND_DEL_SHIFT)))
    #define LE_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LE_USBIO_SUSPEND_SHIFT)))
    #define LE_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LE_USBIO_SUSPEND_DEL_SHIFT)))
    #define LE_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LE__PC)
    /* Port Configuration */
    #define LE_PC                 (* (reg32 *) LE__PC)
#endif
/* Pin State */
#define LE_PS                     (* (reg32 *) LE__PS)
/* Data Register */
#define LE_DR                     (* (reg32 *) LE__DR)
/* Input Buffer Disable Override */
#define LE_INP_DIS                (* (reg32 *) LE__PC2)

/* Interrupt configuration Registers */
#define LE_INTCFG                 (* (reg32 *) LE__INTCFG)
#define LE_INTSTAT                (* (reg32 *) LE__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LE_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LE__SIO)
    #define LE_SIO_REG            (* (reg32 *) LE__SIO)
#endif /* (LE__SIO_CFG) */

/* USBIO registers */
#if !defined(LE__PC) && (CY_PSOC4_4200L)
    #define LE_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LE_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LE_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LE_DRIVE_MODE_SHIFT       (0x00u)
#define LE_DRIVE_MODE_MASK        (0x07u << LE_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LE_H */


/* [] END OF FILE */
