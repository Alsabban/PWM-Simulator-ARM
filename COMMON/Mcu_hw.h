/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_hw.h
 *       Module:  Mcu_hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define 	ENABLE			1
#define 	DISABLE			0

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
/****************** SYSCTL *****************************/
 typedef struct
{
	uint32 MOSCDIS			:1;
	uint32 				:3;
	uint32 OSCSRC			:2;
	uint32 XTAL			:5;
	uint32 BYPASS			:1;
	uint32 				:1;
	uint32 PWRDN			:1;
	uint32					:3;
	uint32 PWMDIV			:3;
	uint32 USEPWMDIV		:1;
	uint32 				:1;
	uint32 USESYSDIV		:1;
	uint32 SYSDIV			:4;
	uint32 ACG				:1;
	uint32 				:4;
}RCC_BF;
typedef union
{
	uint32 	R;
	RCC_BF  B;
}RCC_Tag;

typedef struct
{
	uint32 				:4;
	uint32 OSCSRC2			:3;
	uint32 				:4;
	uint32 BYPASS2			:1;
	uint32 				:1;
	uint32 PWRDN2			:1;
	uint32 USBPWRDN		:1;
	uint32					:7;
	uint32 SYSDIV2LSB		:1;
	uint32 SYSDIV2			:6;
	uint32 				:1;
	uint32 DIV400			:1;
	uint32 USERCC2			:1;
}RCC2_BF;
typedef union
{
	uint32 	R;
	RCC2_BF  B;
}RCC2_Tag;

typedef struct 
{
	uint32 GPIOA		:1;
	uint32 GPIOB		:1;
	uint32 GPIOC		:1;
	uint32 GPIOD		:1;
	uint32 GPIOE		:1;
	uint32 GPIOF		:1;
	uint32 			:7;
	uint32 UDMA		:1;
	uint32				:2;
	uint32	USB0		:1;
	uint32				:15;
}RCGC2_BF;
typedef union 
{
	uint32 R;
	RCGC2_BF B;
}RCGC2_Tag;


 typedef struct
{
	uint32				:31;
	uint32 LOCK		:1;
}PLLSTAT_BF;
typedef union
{
	PLLSTAT_BF  B;
}PLLSTAT_Tag;

typedef struct
{
	uint32		R0			:1;
	uint32		R1			:1;
	uint32		R2			:1;
	uint32		R3			:1;
	uint32		R4			:1;
	uint32		R5			:1;
	uint32 				:26;
}RCGCGPIO_BF;
typedef union 
{
	uint32 R;
	RCGCGPIO_BF B;
}RCGCGPIO_Tag;

 
/****************** GPIO *****************************/
typedef struct
{
	uint32	PMC0	:4;
	uint32	PMC1	:4;
	uint32	PMC2	:4;
	uint32	PMC3	:4;
	uint32	PMC4	:4;
	uint32	PMC5	:4;
	uint32	PMC6	:4;
	uint32	PMC7	:4;
}GPIO_PCTL_BF;

typedef union
{
	uint32 R;
	GPIO_PCTL_BF B;
} GPIO_PCTL_Tag;



typedef union 
{
	uint32 R;
}uint32_Tag;


/****************** NVIC *****************************/
typedef struct 
{
	
	uint32 VECACT			:8;
	uint32					:3;
	uint32 RETBASE			:1;
	uint32 VECPEND			:8;
	uint32 				:2;
	uint32 ISRPEND			:1;
	uint32 ISRPRE			:1;
	uint32 				:1;
	uint32 PENDSTCLR		:1;
	uint32 PENDSTSET		:1;
	uint32 UNPENDSV		:1;
	uint32 PENDSV			:1;
	uint32 reserved		:2;
	uint32 NMISET			:1;
	
} INTCTRL_BF;


typedef union 
{
	uint32 R;
	INTCTRL_BF B;
}INTCTRL_Tag;


typedef struct 
{
	uint32 				:5;
	uint32 MEM				:3;
	uint32 				:5;
	uint32 BUS				:3;
	uint32 				:5;
	uint32 USAGE			:3;
	uint32 				:8;
	
} SYSPRI1_BF;

typedef union
{
	uint32 R;
	SYSPRI1_BF B;
} SYSPRI1_Tag;

typedef struct 
{
	uint32 				:29;
	uint32 SVC				:3;
	
} SYSPRI2_BF;

typedef union
{
	uint32 R;
	SYSPRI2_BF B;
} SYSPRI2_Tag;

typedef struct 
{
	uint32 				:5;
	uint32 DEBUG			:3;
	uint32 				:13;
	uint32 PENDSV			:3;
	uint32 				:5;
	uint32 TICK			:3;
	
} SYSPRI3_BF;
typedef union
{
	uint32 R;
	SYSPRI3_BF B;
} SYSPRI3_Tag;

typedef struct
{
	uint32 MEMA			:1;
	uint32 BUSA 			:1;
	uint32 					:1; 
	uint32 USGA 			:1;
	uint32	  				:3;
	uint32 SVCA 			:1;
	uint32 MON 			:1;
	uint32 			   	:1;
	uint32 PNDSV 			:1;
	uint32 TICK 			:1;
	uint32 USAGEP 			:1;
	uint32 MEMP			:1; 
	uint32 BUSP			:1;
	uint32 SVC				:1;
	uint32 MEM 			:1; 
	uint32 BUS				:1;
	uint32 USAGE			:1;
	uint32						:13;
} SYSHNDCTRL_BF;

typedef union 
{
	uint32 R;
	SYSHNDCTRL_BF B;
} SYSHNDCTRL_Tag;
	
typedef struct 
{
	uint32 VECTRESET		:1;
	uint32	VECTCLRACT	:1;
	uint32 SYSRESREQ		:1;
	uint32							:5;
	uint32 PRIGROUP		:3;
	uint32 						:4;
	uint32 ENDIANESS		:1;
	uint32 VECTKEY			:16;
} APINT_BF;

typedef union 
{     
	uint32 R;
	APINT_BF B;
} APINT_Tag;

typedef struct
{
	uint32				:5;
	uint32 INTA		:3;
	uint32				:5;
	uint32 INTB		:3;
	uint32				:5;
	uint32 INTC		:3;
	uint32				:5;
	uint32 INTD		:3;
} PRIx_BF;

typedef union
{
	uint32 R;
	PRIx_BF B;
} PRIx_Tag ;


typedef struct
{
	uint32 B0    	:1;
	uint32 B1    	:1;
	uint32 B2    	:1;
	uint32 B3    	:1;
	uint32 B4    	:1;
	uint32 B5    	:1;
	uint32 B6    	:1;
	uint32 B7    	:1;
	uint32 B8    	:1;
	uint32 B9    	:1;
	uint32 B10    	:1;
	uint32 B11    	:1;
	uint32 B12    	:1;
	uint32 B13    	:1;
	uint32 B14    	:1;
	uint32 B15    	:1;
	uint32 B16    	:1;
	uint32 B17    	:1;
	uint32 B18    	:1;
	uint32 B19    	:1;
	uint32 B20    	:1;
	uint32 B21    	:1;
	uint32 B22    	:1;
	uint32 B23    	:1;
	uint32 B24    	:1;
	uint32 B25    	:1;
	uint32 B26    	:1;
	uint32 B27    	:1;
	uint32 B28    	:1;
	uint32 B29    	:1;
	uint32 B30    	:1;
	uint32 B31    	:1;	
} uint32_BF;



typedef struct
{
	uint8		B0			:1;
	uint8		B1			:1;
	uint8		B2			:1;
	uint8		B3			:1;
	uint8		B4			:1;
	uint8		B5			:1;
	uint8		B6			:1;
	uint8		B7			:1;
}uint8_BF;

typedef union 
{
	uint8 R;
	uint8_BF B;
}uint8_Tag;

/****************** SYSTICK TIMER *****************************/
typedef struct 
{
	uint32			  				:15;
	uint32		COUNT				:1;
	uint32								:13;
	uint32		CLK_SRC			:1;
	uint32		INTEN			:1;
	uint32		EN					:1;
} SYSTICK_CTRL_BF;
typedef union 
{
	uint32 R;
	SYSTICK_CTRL_BF B;
} SYSTICK_CTRL_Tag;



/**********************************************************************************************************************
 *  CORTEX M4 PERIPHERALS BASE ADDRESS
 *********************************************************************************************************************/
#define 	SYSTEM_CONTROL_BASE				0x400FE000
#define 	CORTEXM4_PERI_BASE	                	0xE000E000


/**********************************************************************************************************************
 *	SYSTICK TIMER REGISTERS
 **********************************************************************************************************************/
#define SYSTICK_CTRL          (*((volatile SYSTICK_CTRL_Tag*)(CORTEXM4_PERI_BASE+0x10)))
#define SYSTICK_RELOAD        (*((volatile uint32 *)(CORTEXM4_PERI_BASE+0x14)))
#define SYSTICK_CURRENT       (*((volatile uint32 *)(CORTEXM4_PERI_BASE+0x18)))
#define SYSTICK_HANDLER_ADDRESS (*((volatile uint32 *)(0x03C)))


/**********************************************************************************************************************
 *  SYSCTL REGISTERS
 *********************************************************************************************************************/
#define RCC						(*(volatile RCC_Tag*)		(SYSTEM_CONTROL_BASE + 0x060) )
#define RCC2						(*(volatile RCC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x070) )
#define	RCGC2						(*(volatile RCGC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x108) )
#define PLLSTAT						(*(volatile PLLSTAT_Tag*) 	(SYSTEM_CONTROL_BASE + 0x168) )
#define RCGCGPIO					(*(volatile RCGCGPIO_Tag*)	(SYSTEM_CONTROL_BASE + 0x608) )
	
/**********************************************************************************************************************
 *  GPIO REGISTERS
 *********************************************************************************************************************/
#define 	GPIOA_APB_BASE			0x40004000
#define 	GPIOB_APB_BASE			0x40005000
#define 	GPIOC_APB_BASE			0x40006000
#define 	GPIOD_APB_BASE			0x40007000
#define 	GPIOE_APB_BASE			0x40024000
#define 	GPIOF_APB_BASE			0x40025000


#define 	BASE_ADDRESS(PORT)				(PORT<4 ? (0x40004000 + (PORT*0x1000)) : (0x40024000 + (PORT-4)*0x1000))



#define 	GPIO_LOCK(PORT)					(*( volatile uint32*)( (BASE_ADDRESS(PORT))+ 0x520 ) )
#define 	GPIO_CR(PORT)					(*( volatile uint32*) ( (BASE_ADDRESS(PORT))+ 0x524 ) )
#define 	GPIO_DEN(PORT)					(*( volatile uint32*) ( (BASE_ADDRESS(PORT))+ 0x51C ) )
#define 	GPIO_AFSEL(PORT)				(*( volatile uint32*) (  BASE_ADDRESS(PORT) + 0x420 ) )
#define 	GPIO_AMSEL(PORT)				(*( volatile uint32*) (  BASE_ADDRESS(PORT) + 0x528 ) )
#define 	GPIO_DIR(PORT)					(*( volatile uint32*)(  BASE_ADDRESS(PORT) + 0x400 ) )
#define 	GPIO_PUR(PORT)					(*( volatile uint32*)(  BASE_ADDRESS(PORT) + 0x510 ) )
#define 	GPIO_ODR(PORT)					(*( volatile uint32*)(  BASE_ADDRESS(PORT) + 0x50C ) )
#define 	GPIO_PDR(PORT)					(*( volatile uint32*)(  BASE_ADDRESS(PORT) + 0x514 ) )
#define 	GPIO_PCTL(PORT)					(*( volatile uint32*)(  BASE_ADDRESS(PORT) + 0x52C ) )
#define 	GPIO_DATA(PORT)					(*( volatile uint32_Tag*)(  BASE_ADDRESS(PORT) + 0x3FC ) )


#define 	GPIO_PORTA_DATA					(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x000 +0x3FC ) )
#define 	GPIO_PORTB_DATA					(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x000 +0x3FC ) )
#define 	GPIO_PORTC_DATA					(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x000 +0x3FC ) )
#define 	GPIO_PORTD_DATA					(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x000 +0x3FC ) )
#define 	GPIO_PORTE_DATA					(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x000 +0x3FC ) )
#define 	GPIO_PORTF_DATA					(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x000 +0x3FC ) )

#define 	GPIO_PORTA_LOCK					(*( volatile uint32*)(  GPIOA_APB_BASE+ 0x520 ) )
#define 	GPIO_PORTB_LOCK					(*( volatile uint32*)(  GPIOB_APB_BASE+ 0x520 ) )
#define 	GPIO_PORTC_LOCK					(*( volatile uint32*)(  GPIOC_APB_BASE+ 0x520 ) )
#define 	GPIO_PORTD_LOCK					(*( volatile uint32*)(  GPIOD_APB_BASE+ 0x520 ) )
#define 	GPIO_PORTE_LOCK					(*( volatile uint32*)(  GPIOE_APB_BASE+ 0x520 ) )
#define 	GPIO_PORTF_LOCK					(*( volatile uint32*)(  GPIOF_APB_BASE+ 0x520 ) )

#define 	GPIO_PORTA_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOA_APB_BASE+ 0x52C ) )
#define 	GPIO_PORTB_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOB_APB_BASE+ 0x52C ) )
#define 	GPIO_PORTC_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOC_APB_BASE+ 0x52C ) )
#define 	GPIO_PORTD_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOD_APB_BASE+ 0x52C ) )
#define 	GPIO_PORTE_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOE_APB_BASE+ 0x52C ) )
#define 	GPIO_PORTF_PCTL					(*( volatile GPIO_PCTL_Tag*)(  GPIOF_APB_BASE+ 0x52C ) )

#define 	GPIO_PORTA_CR					(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x524 ) )
#define 	GPIO_PORTB_CR					(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x524 ) )
#define 	GPIO_PORTC_CR					(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x524 ) )
#define 	GPIO_PORTD_CR					(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x524 ) )
#define 	GPIO_PORTE_CR					(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x524 ) )
#define 	GPIO_PORTF_CR					(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x524 ) )


#define 	GPIO_PORTA_ICR					(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x41C ) )
#define 	GPIO_PORTB_ICR					(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x41C ) )
#define 	GPIO_PORTC_ICR					(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x41C ) )
#define 	GPIO_PORTD_ICR					(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x41C ) )
#define 	GPIO_PORTE_ICR					(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x41C ) )
#define 	GPIO_PORTF_ICR					(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x41C ) )

#define 	GPIO_PORTA_AFSEL				(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x420 ) )
#define 	GPIO_PORTB_AFSEL				(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x420 ) )
#define 	GPIO_PORTC_AFSEL				(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x420 ) )
#define 	GPIO_PORTD_AFSEL				(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x420 ) )
#define 	GPIO_PORTE_AFSEL				(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x420 ) )
#define 	GPIO_PORTF_AFSEL				(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x420 ) )
	
#define 	GPIO_PORTA_AMSEL				(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x528 ) )
#define 	GPIO_PORTB_AMSEL				(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x528 ) )
#define 	GPIO_PORTC_AMSEL				(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x528 ) )
#define 	GPIO_PORTD_AMSEL				(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x528 ) )
#define 	GPIO_PORTE_AMSEL				(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x528 ) )
#define 	GPIO_PORTF_AMSEL				(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x528 ) )

#define 	GPIO_PORTA_DIR					(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x400 ) )
#define 	GPIO_PORTB_DIR					(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x400 ) )
#define 	GPIO_PORTC_DIR					(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x400 ) )
#define 	GPIO_PORTD_DIR					(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x400 ) )
#define 	GPIO_PORTE_DIR					(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x400 ) )
#define 	GPIO_PORTF_DIR					(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x400 ) )

#define 	GPIO_PORTA_DEN					(*( volatile uint8*)(  GPIOA_APB_BASE+ 0x51C ) )
#define 	GPIO_PORTB_DEN					(*( volatile uint8*)(  GPIOB_APB_BASE+ 0x51C ) )
#define 	GPIO_PORTC_DEN					(*( volatile uint8*)(  GPIOC_APB_BASE+ 0x51C ) )
#define 	GPIO_PORTD_DEN					(*( volatile uint8*)(  GPIOD_APB_BASE+ 0x51C ) )
#define 	GPIO_PORTE_DEN					(*( volatile uint8*)(  GPIOE_APB_BASE+ 0x51C ) )
#define 	GPIO_PORTF_DEN					(*( volatile uint8*)(  GPIOF_APB_BASE+ 0x51C ) )


/**********************************************************************************************************************
 *  NVIC REGISTERS
 *********************************************************************************************************************/
#define 	INTCTRL						( *(volatile INTCTRL_Tag*)	( CORTEXM4_PERI_BASE + 0xD04) )
#define		SYSPRI1						( *(volatile SYSPRI1_Tag*)			( CORTEXM4_PERI_BASE + 0xD18) )
#define		SYSPRI2						( *(volatile SYSPRI2_Tag*)			( CORTEXM4_PERI_BASE + 0xD1C) )
#define		SYSPRI3						( *(volatile SYSPRI3_Tag*)			( CORTEXM4_PERI_BASE + 0xD20) )
#define		SYSHNDCTRL					( *(volatile SYSHNDCTRL_Tag*)( CORTEXM4_PERI_BASE + 0xD24) )
#define		FAULTSTAT					( *(volatile uint32*)			( CORTEXM4_PERI_BASE + 0xD28) )
#define		HFAULTSTAT					( *(volatile uint32*)			( CORTEXM4_PERI_BASE + 0xD2C) )
#define		APINT						( *(volatile APINT_Tag*)	( CORTEXM4_PERI_BASE + 0xD0C) )
#define		VTABLE						( *(volatile uint32*)			( CORTEXM4_PERI_BASE + 0xD08) )
#define		SWTRIG						( *(volatile uint32*)			( CORTEXM4_PERI_BASE + 0xF00) )


#define		PRI(x)						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x400+ (x+x+x+x)) )	

/****************** PRIORITY REGISTERS *****************************/
#define		NVIC_PRI0						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x400) )	
#define		NVIC_PRI1						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x404) )
#define		NVIC_PRI2						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x408) )
#define		NVIC_PRI3						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x40C) )
#define		NVIC_PRI4						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x410) )
#define		NVIC_PRI5						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x414) )
#define		NVIC_PRI6						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x418) )
#define		NVIC_PRI7						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x41C) )
#define		NVIC_PRI8						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x420) )
#define		NVIC_PRI9						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x424) )
#define		NVIC_PRI10						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x428) )
#define		NVIC_PRI11						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x42C) )
#define		NVIC_PRI12						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x430) )
#define		NVIC_PRI13						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x434) )
#define		NVIC_PRI14						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x438) )
#define		NVIC_PRI15						(*( volatile PRIx_Tag*)		( CORTEXM4_PERI_BASE + 0x43C) )

/****************** ENABLE REGISTERS *****************************/
#define		NVIC_EN0							(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x100) )	
#define		NVIC_EN1							(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x104) )
#define		NVIC_EN2							(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x108) )
#define		NVIC_EN3							(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x10C) )
#define		NVIC_EN4							(*( volatile uint8_Tag*)		( CORTEXM4_PERI_BASE + 0x110) )

/****************** DISABLE REGISTERS *****************************/
#define		NVIC_DIS0						(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x180) )	
#define		NVIC_DIS1						(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x184) )
#define		NVIC_DIS2						(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x188) )
#define		NVIC_DIS3						(*( volatile uint32_Tag*)		( CORTEXM4_PERI_BASE + 0x18C) )
#define		NVIC_DIS4						(*( volatile uint8_Tag*)		( CORTEXM4_PERI_BASE + 0x190) )

#endif /* MCU_HW_H_ */
