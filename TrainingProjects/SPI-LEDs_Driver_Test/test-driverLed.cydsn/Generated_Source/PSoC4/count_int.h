/*******************************************************************************
* File Name: count_int.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_count_int_H)
#define CY_ISR_count_int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void count_int_Start(void);
void count_int_StartEx(cyisraddress address);
void count_int_Stop(void);

CY_ISR_PROTO(count_int_Interrupt);

void count_int_SetVector(cyisraddress address);
cyisraddress count_int_GetVector(void);

void count_int_SetPriority(uint8 priority);
uint8 count_int_GetPriority(void);

void count_int_Enable(void);
uint8 count_int_GetState(void);
void count_int_Disable(void);

void count_int_SetPending(void);
void count_int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the count_int ISR. */
#define count_int_INTC_VECTOR            ((reg32 *) count_int__INTC_VECT)

/* Address of the count_int ISR priority. */
#define count_int_INTC_PRIOR             ((reg32 *) count_int__INTC_PRIOR_REG)

/* Priority of the count_int interrupt. */
#define count_int_INTC_PRIOR_NUMBER      count_int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable count_int interrupt. */
#define count_int_INTC_SET_EN            ((reg32 *) count_int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the count_int interrupt. */
#define count_int_INTC_CLR_EN            ((reg32 *) count_int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the count_int interrupt state to pending. */
#define count_int_INTC_SET_PD            ((reg32 *) count_int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the count_int interrupt. */
#define count_int_INTC_CLR_PD            ((reg32 *) count_int__INTC_CLR_PD_REG)



#endif /* CY_ISR_count_int_H */


/* [] END OF FILE */
