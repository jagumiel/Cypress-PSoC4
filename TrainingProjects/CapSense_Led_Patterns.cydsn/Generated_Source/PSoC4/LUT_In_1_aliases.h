/*******************************************************************************
* File Name: LUT_In_1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LUT_In_1_ALIASES_H) /* Pins LUT_In_1_ALIASES_H */
#define CY_PINS_LUT_In_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LUT_In_1_0			(LUT_In_1__0__PC)
#define LUT_In_1_0_PS		(LUT_In_1__0__PS)
#define LUT_In_1_0_PC		(LUT_In_1__0__PC)
#define LUT_In_1_0_DR		(LUT_In_1__0__DR)
#define LUT_In_1_0_SHIFT	(LUT_In_1__0__SHIFT)
#define LUT_In_1_0_INTR	((uint16)((uint16)0x0003u << (LUT_In_1__0__SHIFT*2u)))

#define LUT_In_1_INTR_ALL	 ((uint16)(LUT_In_1_0_INTR))


#endif /* End Pins LUT_In_1_ALIASES_H */


/* [] END OF FILE */
