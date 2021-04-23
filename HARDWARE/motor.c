#include "includes.h"
#include "motor.h"

#define MaxOutput 7000          //pwm������ 
int16_t encoder_fly,encoder_walk; //1���� 2������
int PWM_out1=0;
int PWM_out2=0;

u8 start_flag=0;//1���� 0ֹͣ

/*--------------------����ٶȿ���--------------------*/
void Motor_control(void)
{
  
  PWM_out1 = PWM_out1>MaxOutput?MaxOutput:PWM_out1;
  PWM_out1 = PWM_out1<-MaxOutput?-MaxOutput:PWM_out1;//PWM�޷�
  
  PWM_out2 = PWM_out2>MaxOutput?MaxOutput:PWM_out2;
  PWM_out2 = PWM_out2<-MaxOutput?-MaxOutput:PWM_out2;//PWM�޷�
  
  
  if(PWM_out1 >= 0)
    MotorTopForward(PWM_out1);
  if(PWM_out1<0)
    MotorTopBackward(-PWM_out1);
  
  if(PWM_out2 < 0)
    MotorBottomForward(-PWM_out2);
  if(PWM_out2>=0)
    MotorBottomBackward(PWM_out2);
  
  if(start_flag==0)
  {
    MotorStop();
  }
  
}
void MotorTopForward( u16 x )
{
  TIM3->CCR1 = 0;
  TIM3->CCR2 = x;
}
void MotorTopBackward( u16 x )
{  
  TIM3->CCR1 = x;
  TIM3->CCR2 = 0;
}
void MotorBottomForward( u16 x )
{
  TIM3->CCR3 = 0;
  TIM3->CCR4 = x;
  
}
void MotorBottomBackward( u16 x )
{ 
  TIM3->CCR3 = x;
  TIM3->CCR4 = 0;
}
void MotorStop( void )
{  
  TIM3->CCR1 = 0;
  TIM3->CCR2 = 0;
  TIM3->CCR3 = 0;
  TIM3->CCR4 = 0;
}

