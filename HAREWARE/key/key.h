#ifndef __KEY_H
#define __KEY_H

#define KEY0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //读取按键0
#define KEY1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) //读取按键1
#define KEY2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) //读取按键2

#define KEY0_Press 0
#define KEY1_Press 0
#define KEY2_Press 1

void KEY_Init(void);
unsigned char KEY_Scan(unsigned char mode);

#endif
