/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_cfg.h
 *       Module:  Port Initialization
 *
 *  Description:  Header File for port initialization driver configuration for TM4C123GH6PM Microcontroller
 *  
 *********************************************************************************************************************/
 #include "Port.h"
 #include "Std_Types.h"
 
 #ifndef		PORT_CFG_H_
#define 	PORT_CFG_H_

/**********************************************************************************************************************
 *  PORTS CONFIGURATION 
 *********************************************************************************************************************/
#define INIT_PORTA			NO_INIT
#define INIT_PORTB			NO_INIT
#define INIT_PORTC			NO_INIT
#define INIT_PORTD			NO_INIT
#define INIT_PORTE			NO_INIT
#define INIT_PORTF			INIT			


/******* PINS ********/
 
#define		PA0_CFG			PIN_OUTPUT
#define		PA1_CFG			PIN_OUTPUT
#define		PA2_CFG			PIN_OUTPUT
#define		PA3_CFG			PIN_OUTPUT
#define		PA4_CFG			PIN_OUTPUT
#define		PA5_CFG			PIN_OUTPUT
#define		PA6_CFG			PIN_OUTPUT
#define		PA7_CFG			PIN_OUTPUT
#define		PB0_CFG			PIN_OUTPUT
#define		PB1_CFG			PIN_OUTPUT
#define		PB2_CFG			PIN_OUTPUT
#define		PB3_CFG			PIN_OUTPUT
#define		PB4_CFG			PIN_OUTPUT
#define		PB5_CFG			PIN_OUTPUT
#define		PB6_CFG			PIN_OUTPUT
#define		PB7_CFG			PIN_OUTPUT



#define		PC4_CFG			PIN_OUTPUT
#define		PC5_CFG			PIN_OUTPUT
#define		PC6_CFG			PIN_OUTPUT
#define		PC7_CFG			PIN_OUTPUT


#define		PD0_CFG			PIN_OUTPUT
#define		PD1_CFG			PIN_OUTPUT
#define		PD2_CFG			PIN_OUTPUT
#define		PD3_CFG			PIN_OUTPUT
#define		PD4_CFG			PIN_OUTPUT
#define		PD5_CFG			PIN_OUTPUT
#define		PD6_CFG			PIN_OUTPUT
#define		PD7_CFG 		PIN_OUTPUT


#define		PE0_CFG			PIN_OUTPUT
#define		PE1_CFG			PIN_OUTPUT
#define		PE2_CFG			PIN_OUTPUT
#define		PE3_CFG			PIN_OUTPUT
#define		PE4_CFG			PIN_OUTPUT
#define		PE5_CFG			PIN_OUTPUT


#define		PF0_CFG			PIN_INPUT_PULL_UP_RES
#define		PF1_CFG			PIN_OUTPUT
#define		PF2_CFG			PIN_OUTPUT
#define		PF3_CFG			PIN_OUTPUT
#define		PF4_CFG			PIN_INPUT_PULL_UP_RES


static const uint8 Ports_cfg[6] = {
	INIT_PORTA,INIT_PORTB,INIT_PORTC,INIT_PORTD,INIT_PORTE,INIT_PORTF
	};

static const uint8 Pins_cfg[6][8] = {
	{PA0_CFG	, PA1_CFG	 , PA2_CFG	, PA3_CFG	, PA4_CFG	, PA5_CFG	, PA6_CFG	, PA7_CFG	},
	{PB0_CFG	, PB1_CFG	 , PB2_CFG	, PB3_CFG	, PB4_CFG	, PB5_CFG	, PB6_CFG	, PB7_CFG	},
	{NO_PIN, NO_PIN, NO_PIN, NO_PIN, PC4_CFG	, PC5_CFG	, PC6_CFG	, PC7_CFG	},
	{PD0_CFG	, PD1_CFG	 , PD2_CFG , PD3_CFG	, PD4_CFG	, PD5_CFG	, PD6_CFG	, PD7_CFG	},
	{PE0_CFG	, PE1_CFG	 , PE2_CFG	, PE3_CFG	, PE4_CFG	, PE5_CFG	, NO_PIN		, NO_PIN		 },
	{PF0_CFG	, PF1_CFG	 , PF2_CFG	, PF3_CFG	, PF4_CFG	, NO_PIN		, NO_PIN		, NO_PIN		 }
	};


#endif
