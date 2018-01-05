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

void gamePlay()
{
        if (!Button_1_Read() && !buttonOn)
        {
            LED_1_Write(1);
            buttonOn = 1;
            Buzzer_1_Write(1);
            CyDelay(400);
            Buzzer_1_Write(0);
        }
        if (!Button_2_Read() && !buttonOn)
        {
            LED_2_Write(1);
            buttonOn = 1;
            Buzzer_1_Write(1);
            CyDelay(400);
            Buzzer_1_Write(0);
        }
        if (!Button_3_Read() && !buttonOn)
        {
            LED_3_Write(1);
            buttonOn = 1;
            Buzzer_2_Write(1);
            CyDelay(400);
            Buzzer_2_Write(0);
        }
        if (!Button_4_Read() && !buttonOn)
        {
            LED_4_Write(1);
            buttonOn = 1;
            Buzzer_2_Write(1);
            CyDelay(400);
            Buzzer_2_Write(0);
        }
        
        if (!Reset_Read())
        {
            LED_1_Write(0);
            LED_2_Write(0);
            LED_3_Write(0);
            LED_4_Write(0);
            buttonOn = 0;
        }    
}

/* [] END OF FILE */
