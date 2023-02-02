#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

//������ʼ��
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_3; //KEY0 KEY1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//����ɨ��
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY3����
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY_UP!!
unsigned char KEY_Scan(unsigned char mode)
{
	static unsigned char key_up = 1; //�������ɿ���־
	if(mode) key_up = 1; //֧������������ɿ�����
	if(key_up&&(KEY0==KEY0_Press||KEY1==KEY1_Press||KEY2==KEY2_Press))
	{
		delay_ms(10);
		key_up = 0; //�а�������
		if(KEY0==KEY0_Press)return 1;
		else if(KEY1==KEY1_Press)return 2;
		else if(KEY2==KEY2_Press)return 3;
	}
	else if(KEY0==1&&KEY1==1&&KEY2==0)key_up=1;
	return 0;
}
