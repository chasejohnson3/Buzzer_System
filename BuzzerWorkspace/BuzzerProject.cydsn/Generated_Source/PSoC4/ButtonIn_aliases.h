/*******************************************************************************
* File Name: ButtonIn.h  
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

#if !defined(CY_PINS_ButtonIn_ALIASES_H) /* Pins ButtonIn_ALIASES_H */
#define CY_PINS_ButtonIn_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ButtonIn_0			(ButtonIn__0__PC)
#define ButtonIn_0_PS		(ButtonIn__0__PS)
#define ButtonIn_0_PC		(ButtonIn__0__PC)
#define ButtonIn_0_DR		(ButtonIn__0__DR)
#define ButtonIn_0_SHIFT	(ButtonIn__0__SHIFT)
#define ButtonIn_0_INTR	((uint16)((uint16)0x0003u << (ButtonIn__0__SHIFT*2u)))

#define ButtonIn_INTR_ALL	 ((uint16)(ButtonIn_0_INTR))


#endif /* End Pins ButtonIn_ALIASES_H */


/* [] END OF FILE */
