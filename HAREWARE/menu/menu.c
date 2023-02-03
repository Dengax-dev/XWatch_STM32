#include "stm32f10x.h"
#include "menu.h"
#include "OLED.h"

Menu_table table[30]=
{
	//第一层
	{0,1,0,0,(*Show_Watch)},
	
	//第二层
	{ 1,2,5,0,(*Show_Temp_bmp)},  //tmep humi
	{ 2,3,6,0,(*Show_Game_bmp)},  //game
	{ 3,4,7,0,(*Show_Alarm_bmp)}, //alarm
	{ 4,1,8,0,(*Show_Info_bmp)},  //show info
	
	//第三层
	{ 5,5,5,1,(*Show_Temp)},    //temp and humi
	{ 6,6,6,2,(*Game)},         //game
	{ 7,7,7,3,(*Alarm)},        //alarm
	{ 8,8,8,4,(*Show_Info)}     //info
//	{ 9,next,enter,backk,(*)},  //alarm_show
//	{10,next,enter,backk,(*)},  //alarm_add
};

void Show_Watch(void){
	OLED_ShowStr(0,0,"Watch",2);
}

void Show_Temp_bmp(void){
	OLED_ShowStr(0,0,"temp bmp",2);
}

void Show_Game_bmp(void){
	OLED_ShowStr(0,0,"game bmp",2);
}

void Show_Alarm_bmp(void){
	OLED_ShowStr(0,0,"alarm bmp",2);
}

void Show_Info_bmp(void){
	OLED_ShowStr(0,0,"info bmp",2);
}

void Show_Temp(void){
	OLED_ShowStr(0,0,"temp and humi",2);
}

void Game(void){
	OLED_ShowStr(0,0,"game start",2);
}

void Alarm(void){
	OLED_ShowStr(0,0,"alarm set",2);
}

void Show_Info(void){
	OLED_ShowStr(0,0,"all info",2);
}

//菜单显示处理
void Menu_Show(unsigned char key)
{
	extern void (*current_operation_index)();
	extern unsigned char func_index; //主程序此时所在程序的索引值
	extern unsigned char last_index;

	switch (key)
	{
	case 1:
		func_index = table[func_index].back;
		break;
	case 2:
		func_index = table[func_index].enter;
		break;
	case 3:
		func_index = table[func_index].next;
		break;
	default:
		break;
	}

	if(func_index != last_index)
	{
		current_operation_index = table[func_index].current_operation;
		OLED_Fill_Fast(0x00); //清屏
		(*current_operation_index)();
		
		last_index = func_index;
	}
}


