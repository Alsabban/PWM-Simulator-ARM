/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port Initialization
 *
 *  Description:  Header file for the Port initialization driver for TM4C123GH6PM Microcontrollers 
 *  
 *********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_



/**********************************************************************************************************************
 *  CONFIGURATIONS
 *********************************************************************************************************************/
/*******	Ports *********/
#define	 NO_INIT													0
#define  INIT															1


/********* Pins *********/
#define		PIN_OUTPUT											20
#define		PIN_INPUT_PULL_UP_RES						21
#define		PIN_INPUT_PULL_DOWN_RES					22
#define		PIN_INPUT_OPEN_DRAIN						23
#define		NO_PIN													100

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 void Port_Init (void);
 
#endif

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
 
