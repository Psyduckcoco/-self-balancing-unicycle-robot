#ifndef __KEY_H
#define __KEY_H	 
#include "includes.h"
 
#define KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//��ȡ����1

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(void);				 

extern u8 key;

#endif
