/***************************************************************************//**
* \file SCB_EZI2C.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the SCB Component in
*  the EZI2C mode.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_EZI2C_SCB_H)
#define CY_SCB_EZI2C_SCB_H

#include "SCB.h"


/***************************************
*   Initial Parameter Constants
****************************************/

#define SCB_EZI2C_CLOCK_STRETCHING         (1u)
#define SCB_EZI2C_MEDIAN_FILTER_ENABLE     (1u)
#define SCB_EZI2C_NUMBER_OF_ADDRESSES      (0u)
#define SCB_EZI2C_PRIMARY_SLAVE_ADDRESS    (0x8u)
#define SCB_EZI2C_SECONDARY_SLAVE_ADDRESS  (0x9u)
#define SCB_EZI2C_SUB_ADDRESS_SIZE         (1u)
#define SCB_EZI2C_WAKE_ENABLE              (0u)
#define SCB_EZI2C_DATA_RATE                (100u)
#define SCB_EZI2C_SLAVE_ADDRESS_MASK       (0xFEu)
#define SCB_EZI2C_BYTE_MODE_ENABLE         (0u)


/***************************************
*  Conditional Compilation Parameters
****************************************/

#if(SCB_SCB_MODE_UNCONFIG_CONST_CFG)

    #define SCB_SUB_ADDRESS_SIZE16             (0u != SCB_subAddrSize)
    #define SCB_SECONDARY_ADDRESS_ENABLE       (0u != SCB_numberOfAddr)

    #define SCB_EZI2C_EC_AM_ENABLE         (0u != (SCB_CTRL_REG & \
                                                                SCB_CTRL_EC_AM_MODE))
    #define SCB_EZI2C_SCL_STRETCH_ENABLE   (0u != (SCB_GetSlaveInterruptMode() & \
                                                                SCB_INTR_SLAVE_I2C_ADDR_MATCH))
    #define SCB_EZI2C_SCL_STRETCH_DISABLE       (!SCB_EZI2C_SCL_STRETCH_ENABLE)

    #define SCB_SECONDARY_ADDRESS_ENABLE_CONST  (1u)
    #define SCB_SUB_ADDRESS_SIZE16_CONST        (1u)
    #define SCB_EZI2C_SCL_STRETCH_ENABLE_CONST  (1u)
    #define SCB_EZI2C_SCL_STRETCH_DISABLE_CONST (1u)
    #define SCB_EZI2C_WAKE_ENABLE_CONST         (1u)

    #if (SCB_CY_SCBIP_V0 || SCB_CY_SCBIP_V1)
        #define SCB_EZI2C_FIFO_SIZE    (SCB_FIFO_SIZE)
    #else
        #define SCB_EZI2C_FIFO_SIZE    (SCB_GET_FIFO_SIZE(SCB_CTRL_REG & \
                                                                                    SCB_CTRL_BYTE_MODE))
    #endif /* (SCB_CY_SCBIP_V0 || SCB_CY_SCBIP_V1) */

#else

    #define SCB_SUB_ADDRESS_SIZE16         (0u != SCB_EZI2C_SUB_ADDRESS_SIZE)
    #define SCB_SUB_ADDRESS_SIZE16_CONST   (SCB_SUB_ADDRESS_SIZE16)

    #define SCB_SECONDARY_ADDRESS_ENABLE        (0u != SCB_EZI2C_NUMBER_OF_ADDRESSES)
    #define SCB_SECONDARY_ADDRESS_ENABLE_CONST  (SCB_SECONDARY_ADDRESS_ENABLE)

    #define SCB_EZI2C_SCL_STRETCH_ENABLE        (0u != SCB_EZI2C_CLOCK_STRETCHING)
    #define SCB_EZI2C_SCL_STRETCH_DISABLE       (!SCB_EZI2C_SCL_STRETCH_ENABLE)
    #define SCB_EZI2C_SCL_STRETCH_ENABLE_CONST  (SCB_EZI2C_SCL_STRETCH_ENABLE)
    #define SCB_EZI2C_SCL_STRETCH_DISABLE_CONST (SCB_EZI2C_SCL_STRETCH_DISABLE)

    #define SCB_EZI2C_WAKE_ENABLE_CONST         (0u != SCB_EZI2C_WAKE_ENABLE)
    #define SCB_EZI2C_EC_AM_ENABLE              (0u != SCB_EZI2C_WAKE_ENABLE)

    #define SCB_EZI2C_FIFO_SIZE SCB_GET_FIFO_SIZE(SCB_EZI2C_BYTE_MODE_ENABLE)

#endif /* (SCB_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/
/**
* \addtogroup group_structures
* @{
*/
typedef struct
{
    /** When enabled the SCL is stretched as required for proper operation: 
     *  0 – disable, 1 – enable.
    */
    uint32 enableClockStretch;
    
    /** This field is left for compatibility and its value is ignored. 
     *  Median filter is disabled for EZI2C mode.
    */
    uint32 enableMedianFilter;
    
    /** Number of supported addresses: 
     *  - SCB_EZI2C_ONE_ADDRESS
     *  - SCB_EZI2C_TWO_ADDRESSES
    */
    uint32 numberOfAddresses;
    
    /** Primary 7-bit slave address.
    */
    uint32 primarySlaveAddr;
    
    /** Secondary 7-bit slave address.
    */
    uint32 secondarySlaveAddr;
    
    /** Size of sub-address.
     *  - SCB_EZI2C_SUB_ADDR8_BITS 
     *  - SCB_EZI2C_SUB_ADDR16_BITS
    */
    uint32 subAddrSize;
    
    /** When enabled the TX and RX FIFO depth is doubled and equal to 
     *  16 bytes: 0 – disable, 1 – enable.
    */
    uint32 enableWake;
    
    /** When enabled the TX and RX FIFO depth is 16 bytes: 0 – disable, 
     *  1 – enable.
     * 
     *  Ignored for all devices other than PSoC 4100 BLE / PSoC 4200 BLE / 
     *  PSoC 4100M / PSoC 4200M / PSoC 4200L / PSoC 4000S / PSoC 4100S / 
     *  PSoC Analog Coprocessor.
    */
    uint8  enableByteMode;
} SCB_EZI2C_INIT_STRUCT;
/** @} structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ezi2c
* @{
*/

#if(SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    void SCB_EzI2CInit(const SCB_EZI2C_INIT_STRUCT *config);
#endif /* (SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

uint32 SCB_EzI2CGetActivity(void);

void   SCB_EzI2CSetAddress1(uint32 address);
uint32 SCB_EzI2CGetAddress1(void);
void   SCB_EzI2CSetBuffer1(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
void   SCB_EzI2CSetReadBoundaryBuffer1(uint32 rwBoundary);

#if(SCB_SECONDARY_ADDRESS_ENABLE_CONST)
    void   SCB_EzI2CSetAddress2(uint32 address);
    uint32 SCB_EzI2CGetAddress2(void);
    void   SCB_EzI2CSetBuffer2(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
    void   SCB_EzI2CSetReadBoundaryBuffer2(uint32 rwBoundary);
#endif /* (SCB_SECONDARY_ADDRESS_ENABLE_CONST) */
/** @} ezi2c */

#if(SCB_EZI2C_SCL_STRETCH_ENABLE_CONST)
    CY_ISR_PROTO(SCB_EZI2C_STRETCH_ISR);
#endif /* (SCB_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#if(SCB_EZI2C_SCL_STRETCH_DISABLE_CONST)
    CY_ISR_PROTO(SCB_EZI2C_NO_STRETCH_ISR);
#endif /* (SCB_EZI2C_SCL_STRETCH_DISABLE) */


/***************************************
*            API Constants
***************************************/

/* Configuration structure constants */
#define SCB_EZI2C_ONE_ADDRESS      (0u)
#define SCB_EZI2C_TWO_ADDRESSES    (1u)

#define SCB_EZI2C_PRIMARY_ADDRESS  (0u)
#define SCB_EZI2C_BOTH_ADDRESSES   (1u)

#define SCB_EZI2C_SUB_ADDR8_BITS   (0u)
#define SCB_EZI2C_SUB_ADDR16_BITS  (1u)

/* SCB_EzI2CGetActivity() return constants */
#define SCB_EZI2C_STATUS_SECOND_OFFSET (1u)
#define SCB_EZI2C_STATUS_READ1     ((uint32) (SCB_INTR_SLAVE_I2C_NACK))        /* Bit [1]   */
#define SCB_EZI2C_STATUS_WRITE1    ((uint32) (SCB_INTR_SLAVE_I2C_WRITE_STOP))  /* Bit [3]   */
#define SCB_EZI2C_STATUS_READ2     ((uint32) (SCB_INTR_SLAVE_I2C_NACK >> \
                                                           SCB_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [0]   */
#define SCB_EZI2C_STATUS_WRITE2    ((uint32) (SCB_INTR_SLAVE_I2C_WRITE_STOP >> \
                                                           SCB_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [2]   */
#define SCB_EZI2C_STATUS_ERR       ((uint32) (0x10u))                                       /* Bit [4]   */
#define SCB_EZI2C_STATUS_BUSY      ((uint32) (0x20u))                                       /* Bit [5]   */
#define SCB_EZI2C_CLEAR_STATUS     ((uint32) (0x1Fu))                                       /* Bits [0-4]*/
#define SCB_EZI2C_CMPLT_INTR_MASK  ((uint32) (SCB_INTR_SLAVE_I2C_NACK | \
                                                           SCB_INTR_SLAVE_I2C_WRITE_STOP))


/***************************************
*     Vars with External Linkage
***************************************/

#if(SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const SCB_EZI2C_INIT_STRUCT SCB_configEzI2C;
#endif /* (SCB_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*           FSM states
***************************************/

/* Returns to master when there is no data to transmit */
#define SCB_EZI2C_OVFL_RETURN  (0xFFu)

/* States of EZI2C Slave FSM */
#define SCB_EZI2C_FSM_OFFSET_HI8 ((uint8) (0x02u)) /* Idle state for 1 addr: waits for high byte offset */
#define SCB_EZI2C_FSM_OFFSET_LO8 ((uint8) (0x00u)) /* Idle state for 2 addr: waits for low byte offset  */
#define SCB_EZI2C_FSM_BYTE_WRITE ((uint8) (0x01u)) /* Data byte write state: byte by byte mode          */
#define SCB_EZI2C_FSM_WAIT_STOP  ((uint8) (0x03u)) /* Discards written bytes as they do not match write
                                                                   criteria */
#define SCB_EZI2C_FSM_WRITE_MASK ((uint8) (0x01u)) /* Incorporates write states: EZI2C_FSM_BYTE_WRITE and
                                                                   EZI2C_FSM_WAIT_STOP  */

#define SCB_EZI2C_FSM_IDLE     ((SCB_SUB_ADDRESS_SIZE16) ?      \
                                                (SCB_EZI2C_FSM_OFFSET_HI8) : \
                                                (SCB_EZI2C_FSM_OFFSET_LO8))

#define SCB_EZI2C_CONTINUE_TRANSFER    (1u)
#define SCB_EZI2C_COMPLETE_TRANSFER    (0u)

#define SCB_EZI2C_NACK_RECEIVED_ADDRESS  (0u)
#define SCB_EZI2C_ACK_RECEIVED_ADDRESS   (1u)

#define SCB_EZI2C_ACTIVE_ADDRESS1  (0u)
#define SCB_EZI2C_ACTIVE_ADDRESS2  (1u)


/***************************************
*       Macro Definitions
***************************************/

/* Access to global variables */
#if(SCB_SECONDARY_ADDRESS_ENABLE_CONST)

    #define SCB_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus) \
            do{ \
                (locStatus) >>= (activeAddress); \
            }while(0)

    #define SCB_EZI2C_GET_INDEX(activeAddress) \
            ((SCB_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) SCB_indexBuf1) :                    \
                ((uint32) SCB_indexBuf2))

    #define SCB_EZI2C_GET_OFFSET(activeAddress) \
            ((SCB_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) SCB_offsetBuf1) :                   \
                ((uint32) SCB_offsetBuf2))

    #define SCB_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                if(SCB_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    SCB_indexBuf1 = (uint16) (locIndex); \
                }    \
                else \
                {    \
                    SCB_indexBuf2 = (uint16) (locIndex); \
                }    \
            }while(0)

    #define SCB_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                if(SCB_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    SCB_offsetBuf1 = (uint16) (locOffset); \
                }    \
                else \
                {    \
                    SCB_offsetBuf2 = (uint16) (locOffset); \
                }    \
            }while(0)
#else
    #define SCB_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus)  do{ /* Empty*/ }while(0)

    #define SCB_EZI2C_GET_INDEX(activeAddress)  ((uint32) (SCB_indexBuf1))

    #define SCB_EZI2C_GET_OFFSET(activeAddress) ((uint32) (SCB_offsetBuf1))

    #define SCB_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                SCB_indexBuf1 = (uint16) (locIndex); \
            }while(0)

    #define SCB_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                SCB_offsetBuf1 = (uint16) (locOffset); \
            }while(0)

#endif  /* (SCB_SUB_ADDRESS_SIZE16_CONST) */


/* This macro only applicable for EZI2C slave without clock stretching.
* It should not be used for other pusposes. */
#define SCB_EZI2C_TX_FIFO_CTRL_SET   (SCB_EZI2C_TX_FIFO_CTRL | \
                                                   SCB_TX_FIFO_CTRL_CLEAR)
#define SCB_EZI2C_TX_FIFO_CTRL_CLEAR (SCB_EZI2C_TX_FIFO_CTRL)
#define SCB_FAST_CLEAR_TX_FIFO \
                            do{             \
                                SCB_TX_FIFO_CTRL_REG = SCB_EZI2C_TX_FIFO_CTRL_SET;   \
                                SCB_TX_FIFO_CTRL_REG = SCB_EZI2C_TX_FIFO_CTRL_CLEAR; \
                            }while(0)


/***************************************
*      Common Register Settings
***************************************/

#define SCB_CTRL_EZI2C     (SCB_CTRL_MODE_I2C)

#define SCB_EZI2C_CTRL     (SCB_I2C_CTRL_S_GENERAL_IGNORE | \
                                         SCB_I2C_CTRL_SLAVE_MODE)

#define SCB_EZI2C_CTRL_AUTO    (SCB_I2C_CTRL_S_READY_ADDR_ACK      | \
                                             SCB_I2C_CTRL_S_READY_DATA_ACK      | \
                                             SCB_I2C_CTRL_S_NOT_READY_ADDR_NACK | \
                                             SCB_I2C_CTRL_S_NOT_READY_DATA_NACK)

#define SCB_EZI2C_RX_CTRL  ((SCB_FIFO_SIZE - 1u)   | \
                                          SCB_RX_CTRL_MSB_FIRST | \
                                          SCB_RX_CTRL_ENABLED)

#define SCB_EZI2C_TX_FIFO_CTRL (2u)
#define SCB_TX_LOAD_SIZE       (2u)

#define SCB_EZI2C_TX_CTRL  ((SCB_ONE_BYTE_WIDTH - 1u) | \
                                          SCB_TX_CTRL_MSB_FIRST    | \
                                          SCB_TX_CTRL_ENABLED)

#define SCB_EZI2C_INTR_SLAVE_MASK  (SCB_INTR_SLAVE_I2C_BUS_ERROR | \
                                                 SCB_INTR_SLAVE_I2C_ARB_LOST  | \
                                                 SCB_INTR_SLAVE_I2C_STOP)

#define SCB_INTR_SLAVE_COMPLETE    (SCB_INTR_SLAVE_I2C_STOP | \
                                                 SCB_INTR_SLAVE_I2C_NACK | \
                                                 SCB_INTR_SLAVE_I2C_WRITE_STOP)


/***************************************
*    Initialization Register Settings
***************************************/

#if(SCB_SCB_MODE_EZI2C_CONST_CFG)

    #define SCB_EZI2C_DEFAULT_CTRL \
                                (SCB_GET_CTRL_BYTE_MODE  (SCB_EZI2C_BYTE_MODE_ENABLE)    | \
                                 SCB_GET_CTRL_ADDR_ACCEPT(SCB_EZI2C_NUMBER_OF_ADDRESSES) | \
                                 SCB_GET_CTRL_EC_AM_MODE (SCB_EZI2C_WAKE_ENABLE))

    #if(SCB_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define SCB_EZI2C_DEFAULT_I2C_CTRL (SCB_EZI2C_CTRL)
    #else
        #define SCB_EZI2C_DEFAULT_I2C_CTRL (SCB_EZI2C_CTRL_AUTO | SCB_EZI2C_CTRL)
    #endif /* (SCB_EZI2C_SCL_STRETCH_ENABLE_CONST) */


    #define SCB_EZI2C_DEFAULT_RX_MATCH \
                                (SCB_GET_I2C_8BIT_ADDRESS(SCB_EZI2C_PRIMARY_SLAVE_ADDRESS) | \
                                 SCB_GET_RX_MATCH_MASK   (SCB_EZI2C_SLAVE_ADDRESS_MASK))

    #define SCB_EZI2C_DEFAULT_RX_CTRL  (SCB_EZI2C_RX_CTRL)
    #define SCB_EZI2C_DEFAULT_TX_CTRL  (SCB_EZI2C_TX_CTRL)

    #define SCB_EZI2C_DEFAULT_RX_FIFO_CTRL (0u)
    #if(SCB_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define SCB_EZI2C_DEFAULT_TX_FIFO_CTRL (0u)
    #else
        #define SCB_EZI2C_DEFAULT_TX_FIFO_CTRL (2u)
    #endif /* (SCB_EZI2C_SCL_STRETCH_ENABLE_CONST) */

    /* Interrupt sources */
    #define SCB_EZI2C_DEFAULT_INTR_I2C_EC_MASK (SCB_NO_INTR_SOURCES)
    #define SCB_EZI2C_DEFAULT_INTR_SPI_EC_MASK (SCB_NO_INTR_SOURCES)
    #define SCB_EZI2C_DEFAULT_INTR_MASTER_MASK (SCB_NO_INTR_SOURCES)
    #define SCB_EZI2C_DEFAULT_INTR_TX_MASK     (SCB_NO_INTR_SOURCES)

    #if(SCB_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define SCB_EZI2C_DEFAULT_INTR_RX_MASK     (SCB_NO_INTR_SOURCES)
        #define SCB_EZI2C_DEFAULT_INTR_SLAVE_MASK  (SCB_INTR_SLAVE_I2C_ADDR_MATCH | \
                                                                 SCB_EZI2C_INTR_SLAVE_MASK)
    #else
        #define SCB_EZI2C_DEFAULT_INTR_RX_MASK     (SCB_INTR_RX_NOT_EMPTY)
        #define SCB_EZI2C_DEFAULT_INTR_SLAVE_MASK  (SCB_INTR_SLAVE_I2C_START | \
                                                                 SCB_EZI2C_INTR_SLAVE_MASK)
    #endif /* (SCB_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#endif /* (SCB_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* (CY_SCB_EZI2C_SCB_H) */


/* [] END OF FILE */
