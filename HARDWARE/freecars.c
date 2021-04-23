#include "Freecars.h"
#include "includes.h"
u8 uSendBuf[UartDataNum*2]={0};
u8 FreeCarsDataNum=UartDataNum*2;//����ͨ���� UartDataNum*2(��Ϊ������Int16�͵�)
double UartData[9] = {0};

SerialPortType SerialPortRx;
//��ʾFreecars��λ���޸�����



void UartDebug(void)
{
  if(UartData[0]!=0)
  {
     K[0] = (float)UartData[0];
  }
  if(UartData[1]!=0)
  {
     K[1] = (float)UartData[1];
  }
  if(UartData[2]!=0)
  {
     K[2] = (float)UartData[2];
  }
  if(UartData[3]!=0)
  {
    inner_p = (float)UartData[3];
    
  }
  
  if(UartData[4]!=0)
  {
    inner_d  = (float)UartData[4];
  }
  if(UartData[5]!=0)
  {
    speed_p =  (float)UartData[5];
  }
  if(UartData[6]!=0)
  {
    speed_i = (float)UartData[6];
  }
  if(UartData[7]!=0)
  {
    rol = (float)UartData[7];
    roll_setoff = rol;
  }
  if(UartData[8]!=0)
  {
//    pit = (float)UartData[8];
//    pitch_setoff = pit;
//    TIM5->CCR4 = (int)UartData[8];
//    PFout(11)=0;
//    PFout(12)=1;
//    speed_set= (int)UartData[8];
  }
}
/*
������պ���
CmdNum��0~255������
DATA  ��0~255����������Ӧ��������
*/
void UartCmd(u8 CmdNum,u8 Data)
{
  if(CmdNum==2&&Data==102)//page up
  {
    start_flag=!start_flag;
//    if(!start_flag)
//      TIM5->CCR4 = 0;
//    speed_inter=0;
  }
  if(CmdNum==2&&Data==103)//page down
  {
//    roll_setoff = roll;
//    pitch_setoff = pitch;
    follow_flag =!follow_flag;
    
  }
  
  if(CmdNum==2&&Data==104)//End
  {
    
  }
}
/*��ѯ������һ֡����
����ʱ�������ݳ����й�
�����Է����ж����������Ե���
����ʱ����㿴�����ĵ�
*/
void sendDataToScope(void)
{
  u8 i,sum=0;
  //ʹ����ѯ�ķ�ʽ�������ݣ�������δ���ͣ�����ͣ�ڴ˴�ֱ���������
  USART_SendData(USART1,251); 
  USART_SendData(USART1,109); 
  USART_SendData(USART1,37); 
  sum+=(251); //ȫ�����ݼ���У��
  sum+=(109);
  sum+=(37);
  for(i=0;i<FreeCarsDataNum;i++)
  {
    USART_SendData(USART1,uSendBuf[i]);
    sum+=uSendBuf[i]; //ȫ�����ݼ���У��
  }
  USART_SendData(USART1,sum);
}
/*
��ʾ����ĳ��ͨ���������������
chanel��ͨ��
data ������-32768~32767
push ��������������䵽���������棬��Ȼdate��16λ�ģ����������8λ�������档
*/
void push(u8 chanel,u16 data)
{
  uSendBuf[chanel*2]=data/256;
  uSendBuf[chanel*2+1]=data%256;
}
//�����жϻص�����
void USART1_IRQHandler(void)  //�жϴ�����
{
  static u8 get=10;
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
    get = USART_ReceiveData(USART1); 
//    static u8 qidong_flag=0;
    if(get=='8') 
    {
      LED_Fill(0);
      LED_P6x8Str(20,0,"unicycle robot");
      LED_P6x8Str(30,2,"=");LED_P6x8Str(80,2,"=");
      LED_P6x8Str(35,3,"=");LED_P6x8Str(75,3,"=");
      LED_P6x8Str(40,4,"=");LED_P6x8Str(70,4,"=");
      LED_P6x8Str(50,6,"---");
      
      go_line_flag=0;
      follow_flag=0;
    }
    else if(get=='1')
    {
      LED_Fill(0);LED_P6x8Str(20,0,"unicycle robot");
        LED_P6x8Str(25,2,"===");LED_P6x8Str(75,2,"===");
  LED_P6x8Str(25,3,"===");LED_P6x8Str(75,3,"===");
  LED_P6x8Str(54,5,"--");
  
      start_flag=1;
      go_line_flag=0;
      follow_flag=0;
    }
      else if(get=='2')
    {
      LED_Fill(0);LED_P6x8Str(20,0,"unicycle robot");
        LED_P6x8Str(25,2,"===");LED_P6x8Str(75,2,"===");
  LED_P6x8Str(25,3,"===");LED_P6x8Str(75,3,"===");
  LED_P6x8Str(54,5,"--");
      start_flag=1;
      go_line_flag=0;
      follow_flag=1;
    }
      else if(get=='3')
      {
        LED_Fill(0);LED_P6x8Str(20,0,"unicycle robot");
          LED_P6x8Str(25,2,"===");LED_P6x8Str(75,2,"===");
  LED_P6x8Str(25,3,"===");LED_P6x8Str(75,3,"===");
  LED_P6x8Str(54,5,"--");
        start_flag=1;
        go_line_flag=1;
        follow_flag=0;
      }
       else if((get=='4'||get=='5')&&start_flag)
      {
        LED_Fill(0);LED_P6x8Str(20,0,"unicycle robot");
          LED_P6x8Str(25,2,"===");LED_P6x8Str(75,2,"===");
  LED_P6x8Str(25,3,"===");LED_P6x8Str(75,3,"===");
  LED_P6x8Str(54,5,"--");
        go_line_flag=0;
        start_flag=0;
        follow_flag=0;
      }
  }



}
//{
//  int i,b,d1;
//  u32 d;
//  //��������жϺ���
//  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
//  {
//    SerialPortRx.Data = USART_ReceiveData(USART1);  
//    if(SerialPortRx.Stack < UartRxBufferLen)
//    {
//      SerialPortRx.Buffer[SerialPortRx.Stack++] = SerialPortRx.Data;
//      if(SerialPortRx.Stack >= UartRxDataLen//UartRxDataLen����Ϊһ֡
//         && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxDataLen]  ==0xff//У����ͷ
//           && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxDataLen+1]==0x55
//             && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxDataLen+2]==0xaa
//               && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxDataLen+3]==0x10)
//      {//double data 9��ͨ������У��
//        SerialPortRx.Check = 0;
//        b = SerialPortRx.Stack - UartRxDataLen;//��ʼλ
//        for(i=b;i<SerialPortRx.Stack-1;i++)//��У��λ���λ����У��
//        {
//          SerialPortRx.Check += SerialPortRx.Buffer[i];//У��
//        }
//        if(SerialPortRx.Check == SerialPortRx.Buffer[SerialPortRx.Stack-1])
//        {//У��ɹ����������ݽ���
//          for(i = 0;i<9;i++)
//          {
//            d = SerialPortRx.Buffer[b+i*4+4]*0x1000000L + SerialPortRx.Buffer[b+i*4+5]*0x10000L + SerialPortRx.Buffer[b+i*4+6]*0x100L + SerialPortRx.Buffer[b+i*4+7];
//            if(d>0x7FFFFFFF)
//            {
//              d1 = 0x7FFFFFFF - d;
//            }
//            else
//            {
//              d1 = d;
//            }
//            UartData[i]=d1;
//            UartData[i]/=65536.0;
//          }
//          UartDebug();  //תȥ�������ܵ������ݸ�������
//        }
//        SerialPortRx.Stack = 0;
//      }
//      else if(SerialPortRx.Stack >= UartRxCmdLen//UartRxDataLen����Ϊһ֡
//              && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxCmdLen]  ==0xff
//                && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxCmdLen+1]==0x55
//                  && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxCmdLen+2]==0xaa
//                    && SerialPortRx.Buffer[SerialPortRx.Stack - UartRxCmdLen+3]==0x77)//cmd
//      {
//        SerialPortRx.Check = 0;
//        b = SerialPortRx.Stack - UartRxCmdLen;//��ʼλ
//        for(i=b; i<SerialPortRx.Stack-1; i++)//��У��λ���λ����У��
//        {
//          SerialPortRx.Check += SerialPortRx.Buffer[i];//У��
//        }
//        if(SerialPortRx.Check == SerialPortRx.Buffer[SerialPortRx.Stack-1])
//        {//У��ɹ�
//          UartCmd(UartCmdNum,UartCmdData);//������յ����������MCU�������
//        }
//        SerialPortRx.Stack = 0;
//      }
//    }
//    else
//    {
//      SerialPortRx.Stack = 0;
//    } 
//}
//}


