#ifndef  _Freecars_H_
#define  _Freecars_H_  
#include "includes.h"
//FreeCars��λ�� ����������ʾ�� ����ͨ������������λ�����øı�
#define UartDataNum 17//��λ������ͨ����������������λ������һ��
#define UartRxBufferLen  100
#define UartRxDataLen 41//FreeCars��λ�����͸�������MCU���գ���Ҫ��
#define UartRxCmdLen 7//FreeCars��λ�������������ݳ��ȣ���Ҫ��
#define UartCmdNum  SerialPortRx.Buffer[SerialPortRx.Stack-3]//�����
#define UartCmdData SerialPortRx.Buffer[SerialPortRx.Stack-2]//��������

typedef struct 
{
  int Stack;
  u8 Data;
  u8 PreData;
  u8 Buffer[UartRxBufferLen];
  u8 Enable;
  u8 Check;
}SerialPortType;
void push(u8 chanel,u16 data);
void sendDataToScope(void);//Freecarsʾ������ѯ������һ֡����


#endif



