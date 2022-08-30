#include "Systick.h"
#include "GPIO.h"
#include "Port.h"
#include "Mcu_hw.h"

uint32 timeCnt=0;
uint32 On_Time;
 uint32 Off_Time;

/* Project Function (Used as ISR callback function) */
void BlinkingLed(void){
	timeCnt++;
	if(timeCnt==On_Time){
		GPIO_WritePin(PF1,LOW);
	}
	else if(timeCnt==(On_Time+Off_Time)){
		GPIO_WritePin(PF1,HIGH);
		timeCnt=0;
	}
}

int main(){
        __asm("CPSIE I");
	Systick_SetCallback(BlinkingLed);
	Port_Init();
	GPIO_WritePin(PF1,HIGH);
        On_Time=3;
        Off_Time=2;
	Systick_Start();
	while(1){}
}
