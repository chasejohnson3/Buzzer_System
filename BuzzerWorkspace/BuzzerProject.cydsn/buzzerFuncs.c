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
#include "buzzerFuncs.h"
int buttonOn = 0;

int readBuzzers(int testMode)
{
        if (!Button_1_Read() && !buttonOn)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Player 1 Buzzed");
            LED_1_Write(1);
            buttonOn = 1;
           for (int i=0; i<400; i++)
            {
                if (!Reset_Read())
                {
                    buttonOn = 0;
                }
                if (buttonOn)
                {
                    Buzzer_1_Write(1);
                    CyDelay(1);
                }
            }
            Buzzer_1_Write(0);
            return 1;
        }
        if (!Button_2_Read() && !buttonOn)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Player 2 Buzzed");
            LED_2_Write(1);
            buttonOn = 1;
            for (int i=0; i<400; i++)
            {
                if (!Reset_Read())
                {
                    buttonOn = 0;
                }
                if (buttonOn)
                {
                    Buzzer_1_Write(1);
                    CyDelay(1);
                }
            }
            Buzzer_1_Write(0);
            return 2;
        }
        if (!Button_3_Read() && !buttonOn)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Player 3 Buzzed");
            LED_3_Write(1);
            buttonOn = 1;
            for (int i=0; i<400; i++)
            {
                if (!Reset_Read())
                {
                    buttonOn = 0;
                }
                if (buttonOn)
                {
                    Buzzer_2_Write(1);
                    CyDelay(1);
                }
            }
            Buzzer_2_Write(0);
            return 3;
        }
        if (!Button_4_Read() && !buttonOn)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Player 4 Buzzed");
            LED_4_Write(1);
            buttonOn = 1;
            for (int i=0; i<400; i++)
            {
                if (!Reset_Read())
                {
                    buttonOn = 0;
                }
                if (buttonOn)
                {
                    Buzzer_2_Write(1);
                    CyDelay(1);
                }
            }
//            CyDelay(400);
            Buzzer_2_Write(0);
            return 4;
        }
        
        if (!Reset_Read())
        {
            if (!testMode)
            {
                LCD_Char_1_ClearDisplay();
            }
            LED_1_Write(0);
            LED_2_Write(0);
            LED_3_Write(0);
            LED_4_Write(0);
            buttonOn = 0;
            return 9;
        }    
        return 0;
}

void testBuzzers()
{
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 1");
//    readBuzzers();
    int buttonPushed = readBuzzers(1);
    while (buttonPushed != 1)
    {
        if (buttonPushed != 0 && buttonPushed != 1)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Test Buzzer 1");
        }
        buttonPushed = readBuzzers(1);
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 2");
//    readBuzzers();
    buttonPushed = readBuzzers(1);
    while (buttonPushed != 2)
    {
        if (buttonPushed != 0 && buttonPushed != 2)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Test Buzzer 2");
        }
        buttonPushed = readBuzzers(1);
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 3");
    buttonPushed = readBuzzers(1);
    while (buttonPushed != 3)
    {
        if (buttonPushed != 0 && buttonPushed != 3)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Test Buzzer 3");
        }
        buttonPushed = readBuzzers(1);
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 4");
    buttonPushed = readBuzzers(1);
    while (buttonPushed != 4)
    {
        if (buttonPushed != 0 && buttonPushed != 4)
        {
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Test Buzzer 4");
        }
        buttonPushed = readBuzzers(1);
    }
    
        
   
}

/* [] END OF FILE */
