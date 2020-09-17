/*******************************************************************************
* File Name: sclk.h  
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

#if !defined(CY_PINS_sclk_ALIASES_H) /* Pins sclk_ALIASES_H */
#define CY_PINS_sclk_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define sclk_0			(sclk__0__PC)
#define sclk_0_PS		(sclk__0__PS)
#define sclk_0_PC		(sclk__0__PC)
#define sclk_0_DR		(sclk__0__DR)
#define sclk_0_SHIFT	(sclk__0__SHIFT)
#define sclk_0_INTR	((uint16)((uint16)0x0003u << (sclk__0__SHIFT*2u)))

#define sclk_INTR_ALL	 ((uint16)(sclk_0_INTR))


#endif /* End Pins sclk_ALIASES_H */


/* [] END OF FILE */
