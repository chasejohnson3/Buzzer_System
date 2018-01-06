/*******************************************************************************
* File Name: Screen_PM.c
* Version 2.20
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Screen.h"


static Screen_BACKUP_STRUCT Screen_backup;


/*******************************************************************************
* Function Name: Screen_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Screen_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: Screen_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Screen_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: Screen_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Screen_Sleep(void) 
{
    Screen_backup.enableState = Screen_enableState;
    Screen_SaveConfig();
    Screen_Stop();
}


/*******************************************************************************
* Function Name: Screen_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  Screen_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Screen_Wakeup(void) 
{
    Screen_RestoreConfig();

    if(Screen_backup.enableState == 1u)
    {
        Screen_Enable();
    }
}


/* [] END OF FILE */
