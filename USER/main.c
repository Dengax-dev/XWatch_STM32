#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

#define LED_ON   0; //led¿ªÆô
#define LED_OFF  1; //led¹Ø±Õ

int main(void)
{	
    delay_init();
    LED_Init();

    while(1){
		LED0 = LED_ON;
		LED1 = LED_ON;
		delay_ms(500);
		
		LED0 = LED_OFF;
		LED1 = LED_OFF;
		delay_ms(500);
    }

}
