/*******************************************************************************
* File Name: STB.h  
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

#if !defined(CY_PINS_STB_ALIASES_H) /* Pins STB_ALIASES_H */
#define CY_PINS_STB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STB_0			(STB__0__PC)
#define STB_0_PS		(STB__0__PS)
#define STB_0_PC		(STB__0__PC)
#define STB_0_DR		(STB__0__DR)
#define STB_0_SHIFT	(STB__0__SHIFT)
#define STB_0_INTR	((uint16)((uint16)0x0003u << (STB__0__SHIFT*2u)))

#define STB_INTR_ALL	 ((uint16)(STB_0_INTR))


#endif /* End Pins STB_ALIASES_H */


/* [] END OF FILE */
