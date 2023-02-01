#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "OLED.h"

#define LED_ON   0; //led����
#define LED_OFF  1; //led�ر�

int main(void)
{	
    delay_init();
    LED_Init();
	OLED_Init();

    while(1){
		OLED_Fill_Fast(0xff); //����ɫ
//		delay_ms(500);
		OLED_Fill_Fast(0x00); //����
		
//		LED0 = LED_ON;
//		LED1 = LED_ON;
//		delay_ms(500);
//		
//		LED0 = LED_OFF;
//		LED1 = LED_OFF;
//		delay_ms(500);
    }

}
