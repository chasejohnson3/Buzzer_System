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

int readBuzzers()
{
        if (!Button_1_Read() && !buttonOn)
        {
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
        if (Button_2_Read() && !buttonOn)
        {
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
    while (readBuzzers() != 1)
    {
        // Wait for the user to press buzzer 1
       
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 2");
//    readBuzzers();
    while (readBuzzers() != 2)
    {
        // Wait for the user to press buzzer 2
      
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 3");
    
    while (readBuzzers() != 3)
    {
        // Wait for the user to press buzzer 3
        
    }
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("Test Buzzer 4");
//    readBuzzers();
    while (readBuzzers() != 4)
    {
        // Wait for the user to press buzzer 4
        
    }
    
        
   
}

/* [] END OF FILE */
