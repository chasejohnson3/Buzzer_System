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

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for (;;)
    {
        /*if (Button_Read())
        {
            LED_Write(1);
        }
        else
        {
            LED_Write(0);
        }*/
        LED_Write(!Button_Read());
        
        
        /*LED_Write(1);
        CyDelay(1000);
        LED_Write(0);
        CyDelay(1000);*/
    }
}

/* [] END OF FILE */
