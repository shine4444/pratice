
#include "stm32f10x.h"

void GpioInit( void )
{
	//	GPIO_TypeDef GPIO=GPIOA;
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOB, &GPIO_InitStruct );
}

void delay( u32 ms )
{
	u32 i, j;

	for( i = 0; i < ms; i++ )
		for( j = 0; j < 0x0000ffff; j++ );
}

int main( void )
{
	TIM_TimeBaseInitTypeDef time2InitType;
	NVIC_InitTypeDef NVIC_InitStructure;

	SystemInit();
	//RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_2);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	GpioInit();

	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );
	TIM_TimeBaseStructInit( &time2InitType );
	time2InitType.TIM_Prescaler = 7199;
	time2InitType.TIM_Period = 10000;
	TIM_TimeBaseInit( TIM2, &time2InitType );		//1S;

	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_1 );
	TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE );
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init( &NVIC_InitStructure );
	TIM_Cmd( TIM2, ENABLE );

	while( 1 )
	{
		//		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		//		delay(10);
		//		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		//		delay(50);
	}
	//	return 0;
}

