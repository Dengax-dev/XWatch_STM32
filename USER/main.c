#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "OLED.h"
#include "key.h"
#include "menu.h"
//#include "oled_pic.h"

#define LED_ON   0; //led����
#define LED_OFF  1; //led�ر�

void (*current_operation_index)();\
unsigned char key;
unsigned char func_index = 0; //�������ʱ���ڳ��������ֵ
unsigned char last_index = 127;

int main(void)
{	
    delay_init();
    LED_Init();
	OLED_Init();
	KEY_Init();
	
	OLED_Fill_Fast(0xff); //����ɫ
	delay_ms(200);
	OLED_Fill_Fast(0x00); //����
	
//	unsigned char key;
//	unsigned char func_index = 0; //�������ʱ���ڳ��������ֵ

    while(1){
		key = KEY_Scan(0);
		
		if(key == 1){
			func_index = table[func_index].back;
		}
		if(key == 2){
			func_index = table[func_index].enter;
		}
		if(key == 3){
			func_index = table[func_index].next;
		}
		
		if(func_index != last_index)
		{
			current_operation_index = table[func_index].current_operation;
			OLED_Fill_Fast(0x00); //����
			(*current_operation_index)();
			
			last_index = func_index;
		}
		
		
//		LED0 = LED_ON;
//		LED1 = LED_ON;
//		delay_ms(500);
//		
//		LED0 = LED_OFF;
//		LED1 = LED_OFF;
//		delay_ms(500);
    }

}
