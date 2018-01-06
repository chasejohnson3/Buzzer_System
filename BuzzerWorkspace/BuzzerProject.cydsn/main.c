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
    Buzzer_1_Write(0);
    Buzzer_2_Write(0);
    for (;;)
    {
        readBuzzers();
        if(!Reset_Read())
        {
            LCD_Char_1_ClearDisplay();
            testBuzzers();
            
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_PrintString("Ready to Play");
            while (1==1)
            {
            }
//            LCD_Char_1_32_BIT_SHIFT;
//            LCD_Char_1_CLEAR_DISPLAY;
//            LED_1_Write(1);
////            buttonOn = 1;
//            Buzzer_1_Write(1);
//            CyDelay(400);
//            Buzzer_1_Write(0);
        }
       
        /*if (Button_Read())
        {
            LED_Write(1);
        }
        else
        {
            LED_Write(0);
        }*/
//        if (!Button_1_Read() && !buttonOn)
//        {
//            LED_1_Write(1);
//            buttonOn = 1;
//            Buzzer_1_Write(1);
//            CyDelay(400);
//            Buzzer_1_Write(0);
//        }
//        if (!Button_2_Read() && !buttonOn)
//        {
//            LED_2_Write(1);
//            buttonOn = 1;
//            Buzzer_1_Write(1);
//            CyDelay(400);
//            Buzzer_1_Write(0);
//        }
//        if (!Button_3_Read() && !buttonOn)
//        {
//            LED_3_Write(1);
//            buttonOn = 1;
//            Buzzer_2_Write(1);
//            CyDelay(400);
//            Buzzer_2_Write(0);
//        }
//        if (!Button_4_Read() && !buttonOn)
//        {
//            LED_4_Write(1);
//            buttonOn = 1;
//            Buzzer_2_Write(1);
//            CyDelay(400);
//            Buzzer_2_Write(0);
//        }
//        
//        if (!Reset_Read())
//        {
//            LED_1_Write(0);
//            LED_2_Write(0);
//            LED_3_Write(0);
//            LED_4_Write(0);
//            buttonOn = 0;
//        }
            
            
        
//        LED_1_Write(!Button_1_Read());
//        LED_2_Write(!Button_2_Read());
//        LED_3_Write(!Button_3_Read());
//        LED_4_Write(!Button_4_Read());
        
//        LED_Write(0);
//        if (!Button_Read())
//        {
//            LED_Write(1);
//        }
//        else
//        {
//            LED_Write(0);
//        }
//        if (Button_Read())
//        {
//            turnedOff = 1;
//        }
//        if (turnedOff)
//        {
//            
//            if (!Button_Read())
//            {
//                counter ++;
//                turnedOff = 0;
//            }
//            
//            if (counter == 2)
//            {
//                LED_Write(1);
//                counter = 0;
//            }
//            else
//            {
//                LED_Write(0);
//            }
//        }
        
        
        /*LED_Write(1);
        CyDelay(1000);
        LED_Write(0);
        CyDelay(1000);*/
    }
}

/* [] END OF FILE */
