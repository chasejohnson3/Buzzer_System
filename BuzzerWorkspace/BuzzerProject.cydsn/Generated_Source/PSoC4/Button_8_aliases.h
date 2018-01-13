/*******************************************************************************
* File Name: Button_8.h  
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

#if !defined(CY_PINS_Button_8_ALIASES_H) /* Pins Button_8_ALIASES_H */
#define CY_PINS_Button_8_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Button_8_0			(Button_8__0__PC)
#define Button_8_0_PS		(Button_8__0__PS)
#define Button_8_0_PC		(Button_8__0__PC)
#define Button_8_0_DR		(Button_8__0__DR)
#define Button_8_0_SHIFT	(Button_8__0__SHIFT)
#define Button_8_0_INTR	((uint16)((uint16)0x0003u << (Button_8__0__SHIFT*2u)))

#define Button_8_INTR_ALL	 ((uint16)(Button_8_0_INTR))


#endif /* End Pins Button_8_ALIASES_H */


/* [] END OF FILE */
