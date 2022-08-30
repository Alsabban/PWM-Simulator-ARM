/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  GPIO 
 *
 *  Description:  Header file for the GPIO Module in TM4C123GH6PM Microcontrollers  
 *  
 *********************************************************************************************************************/
#ifndef		GPIO_H_
#define 	GPIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define  DISABLE		0
#define  ENABLE 		1


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID
} GPIO_Pins;


/* The leftmost digit enumerates the port and the rightmost enumerates the pin */
typedef enum
{
	PA0=00, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
	PB0=10, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
	PC4=24, PC5, PC6, PC7,											/* PC0-PC3 are not included since these pins are reserved for the JTAG debugger */
	PD0=30, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
	PE0=40, PE1, PE2, PE3, PE4, PE5, 	
	PF0=50, PF1, PF2, PF3, PF4 
} GPIO_PinType;

typedef enum
{
	PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID, PORTE_ID, PORTF_ID
} GPIO_PortID;

typedef enum
{
	LOW, HIGH
} GPIO_LevelType;

typedef enum
{
	PORT_INPUT=0, PORT_OUTPUT=0xff
} GPIO_PortDirType;




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

GPIO_LevelType GPIO_ReadPin (GPIO_PinType PinId);
uint32 GPIO_ReadPort (GPIO_PortID PortId);
void GPIO_WritePin (GPIO_PinType PinId, GPIO_LevelType Level);
void GPIO_WritePort (GPIO_PortID PortId, uint8 Data);
void GPIO_TogglePin (GPIO_PinType PinId);


#endif		/* GPIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
