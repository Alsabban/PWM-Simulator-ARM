/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.c
 *       Module:  Port Initialization
 *
 *  Description:  Source file for the Port initialization driver for TM4C123GH6PM Microcontrollers
 *  
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"
#include "Port.h"
#include "GPIO.h"
#include "Mcu_hw.h"
#include "Port_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init (void)     
* \Description     : Initializes all Pins according to the configuration file                                   
*                                                                             
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                          
*******************************************************************************/
void Port_Init (void)
{
	GPIO_PortID Port;
	GPIO_Pins Pin;
	for( Port=PORTA_ID ; Port<=PORTF_ID ; Port++)
	{
		/* Port initialization (clock gating) */
		if( Ports_cfg[Port] == ENABLE)
		{	
			uint8 i=0;
			SET_BIT(RCGCGPIO.R, Port);
			while(i<5)
			{
				i++;
			}
			/* Digital enable */
			GPIO_DEN(Port)	= 0x000000ff;
			/* Alternative Function */
			GPIO_AFSEL(Port) = 0;
			
			for(Pin=PIN0_ID ; Pin<=PIN7_ID ; Pin++)
			{	
				/* To avoid initializing the JTAG pins */
				if(Port==PORTC_ID){
					if(Pin<PIN4_ID)
						continue;
				}
				if(Pins_cfg[Port][Pin] == PIN_OUTPUT )
				{
					SET_BIT(GPIO_DIR(Port), Pin);
					CLEAR_BIT(GPIO_DATA(Port).R, Pin);
				}
				else if (Pins_cfg[Port][Pin] == PIN_INPUT_OPEN_DRAIN )
				{
					/* Unlock Port to access ODR register */
					GPIO_LOCK(Port) = 0x4C4F434B ;
					GPIO_CR(Port) 	= 0x000000ff;
					CLEAR_BIT(GPIO_DIR(Port), Pin);
					SET_BIT(GPIO_ODR(Port), Pin);

				}
				else if (Pins_cfg[Port][Pin] == PIN_INPUT_PULL_UP_RES )
				{
					/* Unlock Port to access PUR register */
					CLEAR_BIT(GPIO_DIR(Port), Pin);
					GPIO_LOCK(Port) = 0x4C4F434B ;
					GPIO_CR(Port) 	= 0x000000ff;
					SET_BIT(GPIO_PUR(Port), Pin);
				}
				else if (Pins_cfg[Port][Pin] == PIN_INPUT_PULL_DOWN_RES )
				{
					/* Unlock Port to access PDR register */
					CLEAR_BIT(GPIO_DIR(Port), Pin);
					GPIO_LOCK(Port) = 0x4C4F434B ;
					GPIO_CR(Port) 	= 0x000000ff;
					SET_BIT(GPIO_PDR(Port), Pin);
				}		
			}
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
