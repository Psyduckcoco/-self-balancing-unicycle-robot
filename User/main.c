
#include "stm32f10x.h"
#include "includes.h"

void DELAY_ms(u32 time)
{
  u32 i=8000*time;
  while(i--);
}
u8 data_show=1;//1��ʾpitch 0��ʾroll�����
int main()
{
  __disable_irq();//�ر����ж�
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	  //-->����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ����
  My_NVIC_Init();
  delay_init();
  delay_ms(1000); 
  uart_init(9600);///////��������������������/����ע��Ĳ����ʣ�������������
  OLED_Init();
  LED_Fill(0);
  LED_P6x8Str(20,0,"unicycle robot");
  LED_P6x8Str(25,2,"===");LED_P6x8Str(75,2,"===");
  LED_P6x8Str(25,3,"===");LED_P6x8Str(75,3,"===");
  LED_P6x8Str(54,5,"--");
  
  KEY_Init();
  tube_init();
  parameter_Init();
  Adc_Init();//adc
  MPU_Init();//�����ǳ�ʼ��
  //�����ʼ��
  Tim3_init(7199,0); // pwmƵ�� - 10^6 / ((arr+1)*(psc+1)),��ռ�ձ�Ԥװ��ֵ��arr+1   
  Tim5_init(7199,0);
 // ��������ʼ��
  Encoder_Init_TIM2();
  Encoder_Init_TIM4();
  //��ʱ����ʼ��
  TIM1_Int_Init(7199,49);//5ms�ж�
  __enable_irq();//�������ж� 
  while(1)
  { 
    key = KEY_Scan();
    if(key==1)
    {
      DELAY_ms(1000);
    
      start_flag=1;
    }
     LED_PrintValueF(104, 0, encoder_fly,1);  
     LED_PrintValueF(90, 1, voltage,1);  
//    LED_PrintValueF(0, 0, encoder_fly,3);   LED_PrintValueF(50, 0, encoder_walk,3); LED_PrintValueF(90, 0, speed_set,3);
//    LED_PrintValueF(0, 1, voltage,2);
//    LED_PrintValueF(0, 2, K[0],2);
//    LED_PrintValueF(0, 3, K[1],2);
//    LED_PrintValueF(0, 4,  K[2],2);
//    
//    LED_PrintValueF(50, 1, inner_p,2);
//    LED_PrintValueF(50, 2, inner_d,2);
//    LED_PrintValueF(50, 3,  speed_p,2);
//    LED_PrintValueF(50, 4,  speed_i,2);
//    
//    LED_PrintValueF(0, 5,  roll_setoff,2); 
//    LED_PrintValueF(50, 5,  pitch_setoff,2);
//    LED_PrintValueF(0, 6,  roll,2);   LED_PrintValueF(50, 6,  pitch,2);
    
//    if(data_show--0)
//    {
//      push(0,(int)((roll-roll_setoff)*100));
//      push(1,(int)(atan2(accy , accz) * 180 / PI*100));
//      push(2,(int)(gryo_x_b*10));
//      push(3,(int)(PWM_out1/10));
//      
//    push(0,(int)(atan2(accy , accz) * 180 / PI*100));
//    
//    push(3,(int)(roll*100));
//    push(6,(int)(angle1*100));
//    push(9,(int)(angle2*100));
//    
//      sendDataToScope();
//    }
//    else if(data_show)
//    {
//      push(0,(int)((pitch-pitch_setoff)*100));
//      push(1,(int)(atan2(accx , accz) * 180 / PI*100));
//      push(2,(int)(gryo_y_b*10));
//      push(3,(int)(speed_inter));
//      
//     push(0,gyrox);
//      sendDataToScope();
//    }
  }		
}



