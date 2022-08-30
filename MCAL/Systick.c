/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick.h
 *       Module:  Systick 
 *
 *  Description:  Source file for the Systick Module Driver in TM4C123GH6PM Microcontrollers  
 *  
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 #include "Std_Types.h"
 #include "Systick.h"
 #include "Systick_cfg.h"
 #include "Mcu_hw.h"
 
 /**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
 static void (*g_SYSTICK_callBackPtr)(void)= NULL_PTR;
 
 /**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Systick_Start(void)        
* \Description     : Starts the Systick timer with the given reload value from configuration                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
 void Systick_Start(void){
	 SYSTICK_CTRL.R = 0;	 
	 SYSTICK_RELOAD=DELAY_TIME;
         SYSTICK_CURRENT=0;
	 SYSTICK_CTRL.R = CLOCK_SOURCE|ENABLE_INTERRUPTS | INT_EN |1;
 }
 
 /******************************************************************************
* \Syntax          : void Systick_Start(void)        
* \Description     : Sets the given function address as the ISR callback function
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : *FunctionPtr, the function address                    
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
 void Systick_SetCallback(void (*FunctionPtr)(void)){
	 g_SYSTICK_callBackPtr=FunctionPtr;
 }
 
 /**********************************************************************************************************************
 *  ISR DEFINITION
 *********************************************************************************************************************/
 void SysTick_Handler(void){
	 if(g_SYSTICK_callBackPtr!=NULL_PTR){
		 g_SYSTICK_callBackPtr();
	 }
 }
 /**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
