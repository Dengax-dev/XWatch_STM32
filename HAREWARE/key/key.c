#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

//按键初始化
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_3; //KEY0 KEY1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //下拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//按键扫描
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY3按下
//注意此函数有响应优先级,KEY0>KEY1>KEY_UP!!
unsigned char KEY_Scan(unsigned char mode)
{
	static unsigned char key_up = 1; //按键按松开标志
	if(mode) key_up = 1; //支持连按，软件松开按键
	if(key_up&&(KEY0==KEY0_Press||KEY1==KEY1_Press||KEY2==KEY2_Press))
	{
		delay_ms(10);
		key_up = 0; //有按键按下
		if(KEY0==KEY0_Press)return 1;
		else if(KEY1==KEY1_Press)return 2;
		else if(KEY2==KEY2_Press)return 3;
	}
	else if(KEY0==1&&KEY1==1&&KEY2==0)key_up=1;
	return 0;
}
