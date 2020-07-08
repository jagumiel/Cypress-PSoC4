/*******************************************************************************
* File Name: meloinvento.h  
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

#if !defined(CY_PINS_meloinvento_ALIASES_H) /* Pins meloinvento_ALIASES_H */
#define CY_PINS_meloinvento_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define meloinvento_0			(meloinvento__0__PC)
#define meloinvento_0_PS		(meloinvento__0__PS)
#define meloinvento_0_PC		(meloinvento__0__PC)
#define meloinvento_0_DR		(meloinvento__0__DR)
#define meloinvento_0_SHIFT	(meloinvento__0__SHIFT)
#define meloinvento_0_INTR	((uint16)((uint16)0x0003u << (meloinvento__0__SHIFT*2u)))

#define meloinvento_INTR_ALL	 ((uint16)(meloinvento_0_INTR))


#endif /* End Pins meloinvento_ALIASES_H */


/* [] END OF FILE */
