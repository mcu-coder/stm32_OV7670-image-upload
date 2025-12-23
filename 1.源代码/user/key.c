#include "stm32f10x.h"
#include "key.h"
#include "delay.h"

void Key_init(void)	//初始化 KEY1
{	
	GPIO_InitTypeDef gpio_init_struct;//结构体

	RCC_APB2PeriphClockCmd(KEY1_RCC, ENABLE);//初始化时钟 

	gpio_init_struct.GPIO_Mode = GPIO_Mode_IPU;//输入上拉
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init_struct.GPIO_Pin = KEY1_PIN|KEY2_PIN;

	GPIO_Init(KEY1_PORT, &gpio_init_struct);
}

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY1==0||KEY2==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
	}else if(KEY1==1&&KEY2==1)key_up=1; 	    
 	return 0;// 无按键按下
}

