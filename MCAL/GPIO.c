/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.c
 *       Module:  GPIO
 *
 *  Description:  Source file for the GPIO module driver for TM4C123GH6PM Microcontrollers
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "GPIO.h"
#include "GPIO.h"
#include "Mcu_hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void GPIO_WritePin (GPIO_PinType PinId, GPIO_LevelType Level)        
* \Description     : Sets a specific Output Pin value as desired                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PinId   Indicates which pin to write over                    
*					 Level		 Indicated the desired value to be written
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
void GPIO_WritePin (GPIO_PinType PinId, GPIO_LevelType Level)
{
	GPIO_PortID PORT = (uint8) (PinId / 10);
	GPIO_Pins	  PIN	= PinId % 10;
	
	SET_BIT(GPIO_DIR(PORT), PinId);
	GPIO_DATA(PORT).R |=(uint32) Level << PIN;
}


/******************************************************************************
* \Syntax          : void GPIO_WritePort (GPIO_PortType PortId, GPIO_PortLevelType data)
        
* \Description     : Changes the port direction to output and writes the passed value to the DATA register
*										 (NOT TO BE USED WITH PORTC)
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId		Indicates which port to write over
*					 Level		Indicated the desired value to be written
* \Parameters (out): None                                                      
* \Return value:   : None
*                                    
*******************************************************************************/
void GPIO_WritePort (GPIO_PortID PortId, uint8 Data)
{
	if(PortId==PORTC_ID) return;
	else{
		GPIO_DIR(PortId) = (GPIO_PortDirType)PORT_OUTPUT;
		GPIO_DATA(PortId).R = Data;
	}
}


/******************************************************************************
* \Syntax          : GPIO_PortLevelType GPIO_ReadPort (GPIO_PortType PortId)
* \Description     : Reads the value of a specific port data register                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId		Indicates the desired port 
* \Parameters (out): None                                                      
* \Return value:   : uint32
*                                                                  
*******************************************************************************/
uint32 GPIO_ReadPort (GPIO_PortID PortId)
{
	return (GPIO_DATA(PortId).R);
}


/******************************************************************************
* \Syntax          : GPIO_LevelType GPIO_ReadPin (GPIO_PinType PinId)      
* \Description     : Reads the level of a specific pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PinId  	: the ID number of the pin (defined as enum) 
* \Parameters (out): None                                                      
* \Return value:   : GPIO_LevelType		LOW
*						HIGH
*                                                          
*******************************************************************************/
GPIO_LevelType GPIO_ReadPin (GPIO_PinType PinId)
{
	GPIO_PortID PORT = (uint8) (PinId / 10);
	GPIO_Pins	  PIN	= PinId % 10;
	GPIO_LevelType val = GET_BIT(GPIO_DATA(PORT).R ,PIN);
	return val;
}


/******************************************************************************
* \Syntax          : void GPIO_TogglePin (GPIO_PinType PinId)
* \Description     : Toggles Given pin value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PinId   Indicates the desired Pin (Pins PC0 -> PC3 not included to avoid conflicts with JTAG)
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
void GPIO_TogglePin (GPIO_PinType PinId)
{
	/* Take the left digit as the port number */
	GPIO_PortID PORT = (uint8) (PinId / 10);
	/* Take the right digit as the pin number */
	GPIO_Pins	PIN	= PinId % 10;
	
	TOGGLE_BIT(GPIO_DATA(PORT).R ,PIN) ;
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
