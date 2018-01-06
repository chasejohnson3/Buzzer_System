/*******************************************************************************
* File Name: Screen.c
* Version 2.20
*
* Description:
*  This file provides source code for the Character LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "Screen.h"


static void Screen_WrDatNib(uint8 nibble) ;
static void Screen_WrCntrlNib(uint8 nibble) ;

/* Stores state of component. Indicates whether component is or not
* in enable state.
*/
uint8 Screen_enableState = 0u;

uint8 Screen_initVar = 0u;


/*******************************************************************************
* Function Name: Screen_Init
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables a 4-bit interface
*        Clears the display
*        Enables the auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
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
void Screen_Init(void) 
{
    /* INIT CODE */
    CyDelay(40u);                                                        /* Delay 40 ms */
    Screen_WrCntrlNib(Screen_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */
    Screen_WrCntrlNib(Screen_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(15u);                                                        /* Delay 15 ms */
    Screen_WrCntrlNib(Screen_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(1u);                                                         /* Delay 1 ms */
    Screen_WrCntrlNib(Screen_DISPLAY_4_BIT_INIT);    /* Selects 4-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */

    Screen_WriteControl(Screen_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    Screen_WriteControl(Screen_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    Screen_WriteControl(Screen_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    Screen_WriteControl(Screen_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    Screen_WriteControl(Screen_CLEAR_DISPLAY);          /* Clear LCD Screen */
    Screen_WriteControl(Screen_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    Screen_WriteControl(Screen_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(5u);

    #if(Screen_CUSTOM_CHAR_SET != Screen_NONE)
        Screen_LoadCustomFonts(Screen_customFonts);
    #endif /* Screen_CUSTOM_CHAR_SET != Screen_NONE */
}


/*******************************************************************************
* Function Name: Screen_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
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
* Theory:
*  This function has no effect when it is called the first time as
*  Screen_Init() turns on the LCD.
*
*******************************************************************************/
void Screen_Enable(void) 
{
    Screen_DisplayOn();
    Screen_enableState = 1u;
}


/*******************************************************************************
* Function Name: Screen_Start
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables 4-bit interface
*        Clears the display
*        Enables auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
*  If it was not the first call in this project, then it just turns on the
*  display
*
*
* Parameters:
*  Screen_initVar - global variable.
*
* Return:
*  Screen_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Screen_Start(void) 
{
    /* If not initialized, perform initialization */
    if(Screen_initVar == 0u)
    {
        Screen_Init();
        Screen_initVar = 1u;
    }

    /* Turn on the LCD */
    Screen_Enable();
}


/*******************************************************************************
* Function Name: Screen_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
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
void Screen_Stop(void) 
{
    /* Calls LCD Off Macro */
    Screen_DisplayOff();
    Screen_enableState = 0u;
}


/*******************************************************************************
*  Function Name: Screen_Position
********************************************************************************
*
* Summary:
*  Moves the active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:    Specific row of LCD module to be written
*  column: Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays that use the 2X40 address mode.
*  In this case Row 2 starts with a 0x28 offset from Row 1.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void Screen_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            Screen_WriteControl(Screen_ROW_0_START + column);
            break;
        case (uint8) 1:
            Screen_WriteControl(Screen_ROW_1_START + column);
            break;
        case (uint8) 2:
            Screen_WriteControl(Screen_ROW_2_START + column);
            break;
        case (uint8) 3:
            Screen_WriteControl(Screen_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: Screen_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string: Pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void Screen_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        Screen_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: Screen_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character: Character to be written to LCD
*
* Return:
*  None.
*
*******************************************************************************/
void Screen_PutChar(char8 character) 
{
    Screen_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: Screen_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the LCD module's Data Display RAM.
*
* Parameters:
*  dByte: Byte to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void Screen_WriteData(uint8 dByte) 
{
    uint8 nibble;

    Screen_IsReady();
    nibble = dByte >> Screen_NIBBLE_SHIFT;

    /* Write high nibble */
    Screen_WrDatNib(nibble);

    nibble = dByte & Screen_NIBBLE_MASK;
    /* Write low nibble */
    Screen_WrDatNib(nibble);
}


/*******************************************************************************
*  Function Name: Screen_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module.
*
* Parameters:
*  cByte:  The byte to be written to theLCD module
* 
* Return:
*  None.
*
*******************************************************************************/
void Screen_WriteControl(uint8 cByte) 
{
    uint8 nibble;

    Screen_IsReady();

    nibble = cByte >> Screen_NIBBLE_SHIFT;
    
    /* WrCntrlNib(High Nibble) */
    Screen_WrCntrlNib(nibble);
    nibble = cByte & Screen_NIBBLE_MASK;

    /* WrCntrlNib(Low Nibble) */
    Screen_WrCntrlNib(nibble);
}


/*******************************************************************************
* Function Name: Screen_IsReady
********************************************************************************
*
* Summary:
*  Polls the LCD until the ready bit is set or a timeout occurs.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes the pins to High-Z.
*
*******************************************************************************/
void Screen_IsReady(void) 
{
    uint32 value;
    uint32 timeout;
    timeout = Screen_READY_DELAY;

    /* Clear LCD port*/
    Screen_PORT_DR_REG &= ((uint32)(~Screen_PORT_MASK));

    /* PSoC4 has a little different from PSoC3/5 port/pin organization for setting Drive Modes.
  
    */
    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = Screen_PORT_PC_REG & ((uint32) (~ Screen_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        Screen_PORT_PC_REG = value | Screen_HIGH_Z_DATA_DM;

    #else
    
        /* Change Port to High-Z Status on data pins */

        /* Mask off data pins to clear old values out */
        value = Screen_PORT_DM0_REG & ((uint8)(~Screen_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        Screen_PORT_DM0_REG = value | (Screen_HIGH_Z_DM0 & Screen_DATA_MASK);

        /* Mask off data pins to clear old values out */
        value = Screen_PORT_DM1_REG & ((uint8)(~Screen_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        Screen_PORT_DM1_REG = value;

        /* Mask off data pins to clear old values out */
        value = Screen_PORT_DM2_REG & ((uint8)(~Screen_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        Screen_PORT_DM2_REG = value;
    
    #endif /* CY_PSOC4 */
    
    /* Make sure RS is low */
    Screen_PORT_DR_REG &= ((uint32)(~Screen_RS));

    /* Set R/W high to read */
    Screen_PORT_DR_REG |= Screen_RW;

    do
    {
        /* 40 ns delay required before rising Enable and 500ns between neighbour Enables */
        CyDelayUs(0u);

        /* Set E high */
        Screen_PORT_DR_REG |= Screen_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Get port state */
        value = Screen_PORT_PS_REG;

        /* Set enable low */
        Screen_PORT_DR_REG &= ((uint32)(~Screen_E));

        /* This gives true delay between disabling Enable bit and polling Ready bit */
        CyDelayUs(0u);

        /* Extract ready bit */
        value &= Screen_READY_BIT;

        /* Set E high as we in 4-bit interface we need extra operation */
        Screen_PORT_DR_REG |= Screen_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Set enable low */
        Screen_PORT_DR_REG &= ((uint32)(~Screen_E));

        /* If LCD is not ready make a delay */
        if (value == 0u)
        {
            CyDelayUs(10u);
        }

        /* Repeat until bit 4 is not zero or until timeout. */
        timeout--;

    } while ((value != 0u) && (timeout > 0u));

    /* Set R/W low to write */
    Screen_PORT_DR_REG &= ((uint32)(~Screen_RW));

    /* Clear LCD port*/
    Screen_PORT_DR_REG &= ((uint32)(~Screen_PORT_MASK));

    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = Screen_PORT_PC_REG & ((uint32)(~ Screen_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        Screen_PORT_PC_REG = value | Screen_STRONG_DATA_DM;

    #else

        /* Change Port to Output (Strong) on data pins */
        /* Mask off data pins to clear high z values out. Configure data pins 
        * to Strong Drive, others unchanged.
        */
        Screen_PORT_DM0_REG &= ((uint8)(~Screen_DATA_MASK));
        /* Mask off data pins to clear high z values out */
        value = Screen_PORT_DM1_REG & ((uint8)(~Screen_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        Screen_PORT_DM1_REG = value | (Screen_STRONG_DM1 & Screen_DATA_MASK);

        /* Mask off data pins to clear high z values out */
        value = Screen_PORT_DM2_REG & ((uint8)(~Screen_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        Screen_PORT_DM2_REG = value | (Screen_STRONG_DM2 & Screen_DATA_MASK);
    
    #endif /* CY_PSOC4 */
}


/*******************************************************************************
*  Function Name: Screen_WrDatNib
********************************************************************************
*
* Summary:
*  Writes a data nibble to the LCD module.
*
* Parameters:
*  nibble:  Byte containing nibble in the least significant nibble to be
*           written to the LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void Screen_WrDatNib(uint8 nibble) 
{
    /* RS should be low to select data register */
    Screen_PORT_DR_REG |= Screen_RS;
    /* Reset RW for write operation */
    Screen_PORT_DR_REG &= ((uint32)(~Screen_RW));

    /* Guaranteed delay between Setting RS and RW and setting E bits */
    CyDelayUs(0u);
    
    /* Clear data pins */
    Screen_PORT_DR_REG &= ((uint32)(~Screen_DATA_MASK));

    /* Write data, bring E high */
    #if(0u != Screen_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        Screen_PORT_DR_REG |= 
            (Screen_E | ((uint8)(((uint8) nibble) << Screen_PORT_SHIFT)));
    #else
        Screen_PORT_DR_REG |= (Screen_E | nibble);
    #endif /* (0u != Screen_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    Screen_PORT_DR_REG &= ((uint32)(~Screen_E));
}


/*******************************************************************************
*  Function Name: Screen_WrCntrlNib
********************************************************************************
*
* Summary:
*  Writes a control nibble to the LCD module.
*
* Parameters:
*  nibble: The byte containing a nibble in the four least significant bits.????
*
* Return:
*  None.
*
*******************************************************************************/
static void Screen_WrCntrlNib(uint8 nibble) 
{
    /* RS and RW should be low to select instruction register and  write operation respectively */
    Screen_PORT_DR_REG &= ((uint32)(~(Screen_RS | Screen_RW)));

    /* Two following lines of code will give 40ns delay */
    /* Clear data pins */
    Screen_PORT_DR_REG &= ((uint32)(~Screen_DATA_MASK));

    /* Write control data and set enable signal */
    #if(0u != Screen_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        Screen_PORT_DR_REG |= 
            (Screen_E | ((uint8)(((uint8) nibble) << Screen_PORT_SHIFT)));
    #else
        Screen_PORT_DR_REG |= (Screen_E | nibble);
    #endif /* (0u != Screen_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    Screen_PORT_DR_REG &= ((uint32)(~Screen_E));
}


#if(Screen_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: Screen_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value: The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Screen_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE Screen_hex[16u] = "0123456789ABCDEF";
        
        Screen_PutChar((char8) Screen_hex[value >> Screen_BYTE_UPPER_NIBBLE_SHIFT]);
        Screen_PutChar((char8) Screen_hex[value & Screen_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: Screen_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value: The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Screen_PrintInt16(uint16 value) 
    {
        Screen_PrintInt8((uint8)(value >> Screen_U16_UPPER_BYTE_SHIFT));
        Screen_PrintInt8((uint8)(value & Screen_U16_LOWER_BYTE_MASK));
    }

    
    /*******************************************************************************
    *  Function Name: Screen_PrintInt32
    ********************************************************************************
    *
    * Summary:
    *  Print a uint32 hexadecimal number as eight ASCII characters.
    *
    * Parameters:
    *  value: The uint32 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Screen_PrintInt32(uint32 value) 
    {
        uint8 shift = Screen_32_BIT_SHIFT;
        
        while (shift != 0u)
        {
            /* "shift" var is to be subtracted by 8 prior shifting. This implements 
            * shifting by 24, 16, 8 and 0u. 
            */
            shift -= Screen_8_BIT_SHIFT;
            
            /* Print 8 bits of uint32 hex number */
            Screen_PrintInt8((uint8) ((uint32) (value >> shift)));
        }
    }
    
    
    /*******************************************************************************
    *  Function Name: Screen_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint16 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 16-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    * Note:
    *  This function is implemented as a macro.
    *
    *******************************************************************************/

    
    /*******************************************************************************
    *  Function Name: Screen_PrintU32Number
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 32-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Screen_PrintU32Number(uint32 value) 
    {
        uint8 tmpDigit;
        char8 number[Screen_NUMBER_OF_REMAINDERS_U32 + 1u];
        uint8 digIndex = Screen_NUMBER_OF_REMAINDERS_U32;
        
        /* This API will output a decimal number as a string and that string will be 
        * filled from end to start. Set Null termination character first.
        */
        number[digIndex] = (char8) '\0';
        digIndex--;
        
        /* Load these in reverse order */
        while(value >= Screen_TEN)
        {
            /* Extract decimal digit, indexed by 'digIndex', from 'value' and
            * convert it to ASCII character.
            */
            tmpDigit = (uint8) (((uint8) (value % Screen_TEN)) + (uint8) Screen_ZERO_CHAR_ASCII);
            
            /* Temporary variable 'tmpDigit' is used to avoid Violation of MISRA rule 
            * #10.3.
            */
            number[digIndex] = (char8) tmpDigit;
            value /= Screen_TEN;
            digIndex--;
        }
        
        /* Extract last decimal digit 'digIndex', from the 'value' and convert it
        * to ASCII character.
        */
        tmpDigit = (uint8) (((uint8)(value % Screen_TEN)) + (uint8) Screen_ZERO_CHAR_ASCII);
        number[digIndex] = (char8) tmpDigit;

        /* Print out number */
        Screen_PrintString(&number[digIndex]);
    }
    
#endif /* Screen_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
