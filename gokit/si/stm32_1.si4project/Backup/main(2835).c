#include "stm32f10x.h"
void GpioInit(void)
{
//	GPIO_TypeDef GPIO=GPIOA;
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
}
void delay(u32 ms)
{
	u32 i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<0x0000ffff;j++);
}
int main(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GpioInit();
	while (1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		delay(10);
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		delay(50);
	}
//	return 0;
}

