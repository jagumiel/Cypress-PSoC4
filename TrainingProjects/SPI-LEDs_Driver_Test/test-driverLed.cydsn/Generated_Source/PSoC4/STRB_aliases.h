/*******************************************************************************
* File Name: STRB.h  
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

#if !defined(CY_PINS_STRB_ALIASES_H) /* Pins STRB_ALIASES_H */
#define CY_PINS_STRB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STRB_0			(STRB__0__PC)
#define STRB_0_PS		(STRB__0__PS)
#define STRB_0_PC		(STRB__0__PC)
#define STRB_0_DR		(STRB__0__DR)
#define STRB_0_SHIFT	(STRB__0__SHIFT)
#define STRB_0_INTR	((uint16)((uint16)0x0003u << (STRB__0__SHIFT*2u)))

#define STRB_INTR_ALL	 ((uint16)(STRB_0_INTR))


#endif /* End Pins STRB_ALIASES_H */


/* [] END OF FILE */
