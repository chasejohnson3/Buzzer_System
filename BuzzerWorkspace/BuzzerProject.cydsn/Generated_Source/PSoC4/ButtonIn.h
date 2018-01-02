/*******************************************************************************
* File Name: ButtonIn.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ButtonIn_H) /* Pins ButtonIn_H */
#define CY_PINS_ButtonIn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ButtonIn_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} ButtonIn_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ButtonIn_Read(void);
void    ButtonIn_Write(uint8 value);
uint8   ButtonIn_ReadDataReg(void);
#if defined(ButtonIn__PC) || (CY_PSOC4_4200L) 
    void    ButtonIn_SetDriveMode(uint8 mode);
#endif
void    ButtonIn_SetInterruptMode(uint16 position, uint16 mode);
uint8   ButtonIn_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ButtonIn_Sleep(void); 
void ButtonIn_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ButtonIn__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ButtonIn_DRIVE_MODE_BITS        (3)
    #define ButtonIn_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ButtonIn_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ButtonIn_SetDriveMode() function.
         *  @{
         */
        #define ButtonIn_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ButtonIn_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ButtonIn_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ButtonIn_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ButtonIn_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ButtonIn_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ButtonIn_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ButtonIn_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ButtonIn_MASK               ButtonIn__MASK
#define ButtonIn_SHIFT              ButtonIn__SHIFT
#define ButtonIn_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ButtonIn_SetInterruptMode() function.
     *  @{
     */
        #define ButtonIn_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ButtonIn_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ButtonIn_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ButtonIn_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ButtonIn__SIO)
    #define ButtonIn_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ButtonIn__PC) && (CY_PSOC4_4200L)
    #define ButtonIn_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ButtonIn_USBIO_DISABLE              ((uint32)(~ButtonIn_USBIO_ENABLE))
    #define ButtonIn_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ButtonIn_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ButtonIn_USBIO_ENTER_SLEEP          ((uint32)((1u << ButtonIn_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ButtonIn_USBIO_SUSPEND_DEL_SHIFT)))
    #define ButtonIn_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ButtonIn_USBIO_SUSPEND_SHIFT)))
    #define ButtonIn_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ButtonIn_USBIO_SUSPEND_DEL_SHIFT)))
    #define ButtonIn_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ButtonIn__PC)
    /* Port Configuration */
    #define ButtonIn_PC                 (* (reg32 *) ButtonIn__PC)
#endif
/* Pin State */
#define ButtonIn_PS                     (* (reg32 *) ButtonIn__PS)
/* Data Register */
#define ButtonIn_DR                     (* (reg32 *) ButtonIn__DR)
/* Input Buffer Disable Override */
#define ButtonIn_INP_DIS                (* (reg32 *) ButtonIn__PC2)

/* Interrupt configuration Registers */
#define ButtonIn_INTCFG                 (* (reg32 *) ButtonIn__INTCFG)
#define ButtonIn_INTSTAT                (* (reg32 *) ButtonIn__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ButtonIn_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ButtonIn__SIO)
    #define ButtonIn_SIO_REG            (* (reg32 *) ButtonIn__SIO)
#endif /* (ButtonIn__SIO_CFG) */

/* USBIO registers */
#if !defined(ButtonIn__PC) && (CY_PSOC4_4200L)
    #define ButtonIn_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ButtonIn_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ButtonIn_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ButtonIn_DRIVE_MODE_SHIFT       (0x00u)
#define ButtonIn_DRIVE_MODE_MASK        (0x07u << ButtonIn_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ButtonIn_H */


/* [] END OF FILE */
