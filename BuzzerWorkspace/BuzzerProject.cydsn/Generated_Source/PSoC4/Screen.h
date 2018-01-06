/*******************************************************************************
* File Name: Screen.h
* Version 2.20
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_Screen_H)
#define CY_CHARLCD_Screen_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Screen_CONVERSION_ROUTINES     (1u)
#define Screen_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define Screen_NONE                     (0u)    /* No Custom Fonts      */
#define Screen_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define Screen_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define Screen_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Screen_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void Screen_Init(void) ;
void Screen_Enable(void) ;
void Screen_Start(void) ;
void Screen_Stop(void) ;
void Screen_WriteControl(uint8 cByte) ;
void Screen_WriteData(uint8 dByte) ;
void Screen_PrintString(char8 const string[]) ;
void Screen_Position(uint8 row, uint8 column) ;
void Screen_PutChar(char8 character) ;
void Screen_IsReady(void) ;
void Screen_SaveConfig(void) ;
void Screen_RestoreConfig(void) ;
void Screen_Sleep(void) ;
void Screen_Wakeup(void) ;

#if((Screen_CUSTOM_CHAR_SET == Screen_VERTICAL_BG) || \
                (Screen_CUSTOM_CHAR_SET == Screen_HORIZONTAL_BG))

    void  Screen_LoadCustomFonts(uint8 const customData[])
                        ;

    void  Screen_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void Screen_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((Screen_CUSTOM_CHAR_SET == Screen_VERTICAL_BG) */

#if(Screen_CUSTOM_CHAR_SET == Screen_USER_DEFINED)

    void Screen_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((Screen_CUSTOM_CHAR_SET == Screen_USER_DEFINED) */

#if(Screen_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void Screen_PrintInt8(uint8 value) ;
    void Screen_PrintInt16(uint16 value) ;
    void Screen_PrintInt32(uint32 value) ;
    void Screen_PrintNumber(uint16 value) ; 
    void Screen_PrintU32Number(uint32 value) ;
    
#endif /* Screen_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define Screen_ClearDisplay() Screen_WriteControl(Screen_CLEAR_DISPLAY)

/* Off Macro */
#define Screen_DisplayOff() Screen_WriteControl(Screen_DISPLAY_CURSOR_OFF)

/* On Macro */
#define Screen_DisplayOn() Screen_WriteControl(Screen_DISPLAY_ON_CURSOR_OFF)

#define Screen_PrintNumber(value) Screen_PrintU32Number((uint16) (value))


/***************************************
*           Global Variables
***************************************/

extern uint8 Screen_initVar;
extern uint8 Screen_enableState;
extern uint8 const CYCODE Screen_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define Screen_DISPLAY_8_BIT_INIT       (0x03u)
#define Screen_DISPLAY_4_BIT_INIT       (0x02u)
#define Screen_DISPLAY_CURSOR_OFF       (0x08u)
#define Screen_CLEAR_DISPLAY            (0x01u)
#define Screen_CURSOR_AUTO_INCR_ON      (0x06u)
#define Screen_DISPLAY_CURSOR_ON        (0x0Eu)
#define Screen_DISPLAY_2_LINES_5x10     (0x2Cu)
#define Screen_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define Screen_RESET_CURSOR_POSITION    (0x03u)
#define Screen_CURSOR_WINK              (0x0Du)
#define Screen_CURSOR_BLINK             (0x0Fu)
#define Screen_CURSOR_SH_LEFT           (0x10u)
#define Screen_CURSOR_SH_RIGHT          (0x14u)
#define Screen_DISPLAY_SCRL_LEFT        (0x18u)
#define Screen_DISPLAY_SCRL_RIGHT       (0x1Eu)
#define Screen_CURSOR_HOME              (0x02u)
#define Screen_CURSOR_LEFT              (0x04u)
#define Screen_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define Screen_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define Screen_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define Screen_CHARACTER_WIDTH          (0x05u)
#define Screen_CHARACTER_HEIGHT         (0x08u)

#if(Screen_CONVERSION_ROUTINES == 1u)
    #define Screen_NUMBER_OF_REMAINDERS_U32 (0x0Au)
    #define Screen_TEN                      (0x0Au)
    #define Screen_8_BIT_SHIFT              (8u)
    #define Screen_32_BIT_SHIFT             (32u)
    #define Screen_ZERO_CHAR_ASCII          (48u)
#endif /* Screen_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define Screen_NIBBLE_SHIFT             (0x04u)
#define Screen_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define Screen_ROW_0_START              (0x80u)
#define Screen_ROW_1_START              (0xC0u)
#define Screen_ROW_2_START              (0x94u)
#define Screen_ROW_3_START              (0xD4u)

/* Custom Character References */
#define Screen_CUSTOM_0                 (0x00u)
#define Screen_CUSTOM_1                 (0x01u)
#define Screen_CUSTOM_2                 (0x02u)
#define Screen_CUSTOM_3                 (0x03u)
#define Screen_CUSTOM_4                 (0x04u)
#define Screen_CUSTOM_5                 (0x05u)
#define Screen_CUSTOM_6                 (0x06u)
#define Screen_CUSTOM_7                 (0x07u)

/* Other constants */
#define Screen_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define Screen_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define Screen_U16_UPPER_BYTE_SHIFT     (0x08u)
#define Screen_U16_LOWER_BYTE_MASK      (0xFFu)
#define Screen_CUSTOM_CHAR_SET_LEN      (0x40u)

#define Screen_LONGEST_CMD_US           (0x651u)
#define Screen_WAIT_CYCLE               (0x10u)
#define Screen_READY_DELAY              ((Screen_LONGEST_CMD_US * 4u)/(Screen_WAIT_CYCLE))


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define Screen_PORT_DR_REG           (*(reg32 *) Screen_LCDPort__DR)  /* Data Output Register */
    #define Screen_PORT_DR_PTR           ( (reg32 *) Screen_LCDPort__DR)
    #define Screen_PORT_PS_REG           (*(reg32 *) Screen_LCDPort__PS)  /* Pin State Register */
    #define Screen_PORT_PS_PTR           ( (reg32 *) Screen_LCDPort__PS)
    
    #define Screen_PORT_PC_REG           (*(reg32 *) Screen_LCDPort__PC)
    #define Screen_PORT_PC_PTR           (*(reg32 *) Screen_LCDPort__PC)
    
#else

    #define Screen_PORT_DR_REG           (*(reg8 *) Screen_LCDPort__DR)  /* Data Output Register */
    #define Screen_PORT_DR_PTR           ( (reg8 *) Screen_LCDPort__DR)
    #define Screen_PORT_PS_REG           (*(reg8 *) Screen_LCDPort__PS)  /* Pin State Register */
    #define Screen_PORT_PS_PTR           ( (reg8 *) Screen_LCDPort__PS)

    #define Screen_PORT_DM0_REG          (*(reg8 *) Screen_LCDPort__DM0) /* Port Drive Mode 0 */
    #define Screen_PORT_DM0_PTR          ( (reg8 *) Screen_LCDPort__DM0)
    #define Screen_PORT_DM1_REG          (*(reg8 *) Screen_LCDPort__DM1) /* Port Drive Mode 1 */
    #define Screen_PORT_DM1_PTR          ( (reg8 *) Screen_LCDPort__DM1)
    #define Screen_PORT_DM2_REG          (*(reg8 *) Screen_LCDPort__DM2) /* Port Drive Mode 2 */
    #define Screen_PORT_DM2_PTR          ( (reg8 *) Screen_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == Screen_LCDPort__SHIFT)
    #define Screen_PORT_SHIFT               (0x00u)
#else
    #define Screen_PORT_SHIFT               (0x01u)
#endif /* (0 == Screen_LCDPort__SHIFT) */

#define Screen_PORT_MASK                ((uint32) (Screen_LCDPort__MASK))

#if (CY_PSOC4)

    #define Screen_DM_PIN_STEP              (3u)
    /* Hi-Z Digital is defined by the value of "001b" and this should be set for
    * four data pins, in this way we get - 0x00000249. A similar Strong drive
    * is defined with "110b" so we get 0x00000DB6.
    */
    #define Screen_HIGH_Z_DATA_DM           ((0x00000249ul) << (Screen_PORT_SHIFT *\
                                                                          Screen_DM_PIN_STEP))
    #define Screen_STRONG_DATA_DM           ((0x00000DB6ul) << (Screen_PORT_SHIFT *\
                                                                          Screen_DM_PIN_STEP))
    #define Screen_DATA_PINS_MASK           (0x00000FFFul)
    #define Screen_DM_DATA_MASK             ((uint32) (Screen_DATA_PINS_MASK << \
                                                      (Screen_PORT_SHIFT * Screen_DM_PIN_STEP)))

#else

    /* Drive Mode register values for High Z */
    #define Screen_HIGH_Z_DM0               (0xFFu)
    #define Screen_HIGH_Z_DM1               (0x00u)
    #define Screen_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define Screen_HIGH_Z_A_DM0             (0x00u)
    #define Screen_HIGH_Z_A_DM1             (0x00u)
    #define Screen_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define Screen_STRONG_DM0               (0x00u)
    #define Screen_STRONG_DM1               (0xFFu)
    #define Screen_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define Screen_RS                     ((uint32) \
                                                (((uint32) 0x20u) << Screen_LCDPort__SHIFT))
#define Screen_RW                     ((uint32) \
                                                (((uint32) 0x40u) << Screen_LCDPort__SHIFT))
#define Screen_E                      ((uint32) \
                                                (((uint32) 0x10u) << Screen_LCDPort__SHIFT))
#define Screen_READY_BIT              ((uint32) \
                                                (((uint32) 0x08u) << Screen_LCDPort__SHIFT))
#define Screen_DATA_MASK              ((uint32) \
                                                (((uint32) 0x0Fu) << Screen_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define Screen_PORT_DR                  Screen_PORT_DR_REG
#define Screen_PORT_PS                  Screen_PORT_PS_REG
#define Screen_PORT_DM0                 Screen_PORT_DM0_REG
#define Screen_PORT_DM1                 Screen_PORT_DM1_REG
#define Screen_PORT_DM2                 Screen_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(Screen_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete and will be removed in future 
    * revisions of the component.
    */
    #define Screen_PrintDecUint16(x)   Screen_PrintNumber(x)  
    #define Screen_PrintHexUint8(x)    Screen_PrintInt8(x)
    #define Screen_PrintHexUint16(x)   Screen_PrintInt16(x)        

#endif /* Screen_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_Screen_H */


/* [] END OF FILE */
