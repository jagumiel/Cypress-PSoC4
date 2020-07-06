/*******************************************************************************
* File Name: Counter_Int.h
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
#if !defined(CY_ISR_Counter_Int_H)
#define CY_ISR_Counter_Int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Counter_Int_Start(void);
void Counter_Int_StartEx(cyisraddress address);
void Counter_Int_Stop(void);

CY_ISR_PROTO(Counter_Int_Interrupt);

void Counter_Int_SetVector(cyisraddress address);
cyisraddress Counter_Int_GetVector(void);

void Counter_Int_SetPriority(uint8 priority);
uint8 Counter_Int_GetPriority(void);

void Counter_Int_Enable(void);
uint8 Counter_Int_GetState(void);
void Counter_Int_Disable(void);

void Counter_Int_SetPending(void);
void Counter_Int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Counter_Int ISR. */
#define Counter_Int_INTC_VECTOR            ((reg32 *) Counter_Int__INTC_VECT)

/* Address of the Counter_Int ISR priority. */
#define Counter_Int_INTC_PRIOR             ((reg32 *) Counter_Int__INTC_PRIOR_REG)

/* Priority of the Counter_Int interrupt. */
#define Counter_Int_INTC_PRIOR_NUMBER      Counter_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Counter_Int interrupt. */
#define Counter_Int_INTC_SET_EN            ((reg32 *) Counter_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Counter_Int interrupt. */
#define Counter_Int_INTC_CLR_EN            ((reg32 *) Counter_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Counter_Int interrupt state to pending. */
#define Counter_Int_INTC_SET_PD            ((reg32 *) Counter_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Counter_Int interrupt. */
#define Counter_Int_INTC_CLR_PD            ((reg32 *) Counter_Int__INTC_CLR_PD_REG)



#endif /* CY_ISR_Counter_Int_H */


/* [] END OF FILE */
