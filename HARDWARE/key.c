#include "key.h"
#include "delay.h"
u8 key=0;
void KEY_Init(void) //IO��ʼ�� //���뿪��
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO,ENABLE);//ʹ��PORTCʱ��
  
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
  
//  PWR_BackupAccessCmd(ENABLE);//�����޸�RTC �ͺ󱸼Ĵ���
//  RCC_LSEConfig(RCC_LSE_OFF);//�ر��ⲿ�����ⲿʱ���źŹ��� ��PC13 PC14 PC15 �ſ��Ե���ͨIO�á�
//  PWR_BackupAccessCmd(DISABLE);//��ֹ�޸ĺ󱸼Ĵ���
}

u8 KEY_Scan(void)
{
   if(KEY1==0)
   {
     delay_ms(50);//ȥ���� 
     if(KEY1==0) return 1;
     else return 0;
   }
   
   return 0;
   
}


