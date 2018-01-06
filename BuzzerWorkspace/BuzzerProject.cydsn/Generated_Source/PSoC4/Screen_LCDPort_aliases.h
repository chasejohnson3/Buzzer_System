/*******************************************************************************
* File Name: Screen_LCDPort.h  
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

#if !defined(CY_PINS_Screen_LCDPort_ALIASES_H) /* Pins Screen_LCDPort_ALIASES_H */
#define CY_PINS_Screen_LCDPort_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Screen_LCDPort_0			(Screen_LCDPort__0__PC)
#define Screen_LCDPort_0_PS		(Screen_LCDPort__0__PS)
#define Screen_LCDPort_0_PC		(Screen_LCDPort__0__PC)
#define Screen_LCDPort_0_DR		(Screen_LCDPort__0__DR)
#define Screen_LCDPort_0_SHIFT	(Screen_LCDPort__0__SHIFT)
#define Screen_LCDPort_0_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__0__SHIFT*2u)))

#define Screen_LCDPort_1			(Screen_LCDPort__1__PC)
#define Screen_LCDPort_1_PS		(Screen_LCDPort__1__PS)
#define Screen_LCDPort_1_PC		(Screen_LCDPort__1__PC)
#define Screen_LCDPort_1_DR		(Screen_LCDPort__1__DR)
#define Screen_LCDPort_1_SHIFT	(Screen_LCDPort__1__SHIFT)
#define Screen_LCDPort_1_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__1__SHIFT*2u)))

#define Screen_LCDPort_2			(Screen_LCDPort__2__PC)
#define Screen_LCDPort_2_PS		(Screen_LCDPort__2__PS)
#define Screen_LCDPort_2_PC		(Screen_LCDPort__2__PC)
#define Screen_LCDPort_2_DR		(Screen_LCDPort__2__DR)
#define Screen_LCDPort_2_SHIFT	(Screen_LCDPort__2__SHIFT)
#define Screen_LCDPort_2_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__2__SHIFT*2u)))

#define Screen_LCDPort_3			(Screen_LCDPort__3__PC)
#define Screen_LCDPort_3_PS		(Screen_LCDPort__3__PS)
#define Screen_LCDPort_3_PC		(Screen_LCDPort__3__PC)
#define Screen_LCDPort_3_DR		(Screen_LCDPort__3__DR)
#define Screen_LCDPort_3_SHIFT	(Screen_LCDPort__3__SHIFT)
#define Screen_LCDPort_3_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__3__SHIFT*2u)))

#define Screen_LCDPort_4			(Screen_LCDPort__4__PC)
#define Screen_LCDPort_4_PS		(Screen_LCDPort__4__PS)
#define Screen_LCDPort_4_PC		(Screen_LCDPort__4__PC)
#define Screen_LCDPort_4_DR		(Screen_LCDPort__4__DR)
#define Screen_LCDPort_4_SHIFT	(Screen_LCDPort__4__SHIFT)
#define Screen_LCDPort_4_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__4__SHIFT*2u)))

#define Screen_LCDPort_5			(Screen_LCDPort__5__PC)
#define Screen_LCDPort_5_PS		(Screen_LCDPort__5__PS)
#define Screen_LCDPort_5_PC		(Screen_LCDPort__5__PC)
#define Screen_LCDPort_5_DR		(Screen_LCDPort__5__DR)
#define Screen_LCDPort_5_SHIFT	(Screen_LCDPort__5__SHIFT)
#define Screen_LCDPort_5_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__5__SHIFT*2u)))

#define Screen_LCDPort_6			(Screen_LCDPort__6__PC)
#define Screen_LCDPort_6_PS		(Screen_LCDPort__6__PS)
#define Screen_LCDPort_6_PC		(Screen_LCDPort__6__PC)
#define Screen_LCDPort_6_DR		(Screen_LCDPort__6__DR)
#define Screen_LCDPort_6_SHIFT	(Screen_LCDPort__6__SHIFT)
#define Screen_LCDPort_6_INTR	((uint16)((uint16)0x0003u << (Screen_LCDPort__6__SHIFT*2u)))

#define Screen_LCDPort_INTR_ALL	 ((uint16)(Screen_LCDPort_0_INTR| Screen_LCDPort_1_INTR| Screen_LCDPort_2_INTR| Screen_LCDPort_3_INTR| Screen_LCDPort_4_INTR| Screen_LCDPort_5_INTR| Screen_LCDPort_6_INTR))


#endif /* End Pins Screen_LCDPort_ALIASES_H */


/* [] END OF FILE */
