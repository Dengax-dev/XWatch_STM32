#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "OLED.h"
#include "key.h"
#include "menu.h"
//#include "oled_pic.h"

#define LED_ON   0; //led开启
#define LED_OFF  1; //led关闭

void (*current_operation_index)();\
unsigned char key;
unsigned char func_index = 0; //主程序此时所在程序的索引值
unsigned char last_index = 127;

int main(void)
{	
    delay_init();
    LED_Init();
	OLED_Init();
	KEY_Init();
	
	OLED_Fill_Fast(0xff); //填充白色
	delay_ms(200);
	OLED_Fill_Fast(0x00); //清屏
	
//	unsigned char key;
//	unsigned char func_index = 0; //主程序此时所在程序的索引值

    while(1){
		key = KEY_Scan(0);
		Menu_Show(key);
		
//		LED0 = LED_ON;
//		LED1 = LED_ON;
//		delay_ms(500);
//		
//		LED0 = LED_OFF;
//		LED1 = LED_OFF;
//		delay_ms(500);
    }

}
