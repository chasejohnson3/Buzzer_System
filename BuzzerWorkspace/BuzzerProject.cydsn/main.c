/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Char_1_Start();
//    int turnedOff = 1;
//    int counter = 0;
//    int buttonOn = 0;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Char_1_Position(0u, 0u);
//    LCD_Char_1_
    LCD_Char_1_PrintString("Science Bowl!"); 
    LCD_Char_1_Position(1u,0u);
    LCD_Char_1_PrintString("Press Reset"); 
//    LCD_Char_1_PrintString("I love Momma J");
    LED_1_Write(0);
    LED_2_Write(0);
    LED_3_Write(0);
    LED_4_Write(0);
    LED_5_Write(0);
    LED_6_Write(0);
    LED_7_Write(0);
    LED_8_Write(0);
    Buzzer_1_Write(0);
    Buzzer_2_Write(0);
    for (;;)
    {
        while(Reset_Read())
        {
            // Wait until user presses reset
        }
        
        {
            testBuzzers();
            
        }
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_PrintString("Ready to play");
        while(1==1)
        {
            readBuzzers(0);
        }
        
    }
}

/* [] END OF FILE */
