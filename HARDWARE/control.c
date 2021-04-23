#include "includes.h"
#include "control.h"
int fankui=0;
float voltage=0;
void LQR_control(void);//LQR������ ���Ʒ���
//void PD_control(void);
//void PI_control(void);
void Z_angle_control(void);
float yaw_inter=0;

float pit=3.95,rol=-0.2;//������Ƕ� ����Ƕ��������� -0.6
int distance=0; 
void TIM1_UP_IRQHandler(void) //TIM1 �ж�
{
  if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //��� TIM1 �����жϷ������
  {
    TIM_ClearFlag(TIM1, TIM_IT_Update ); //��� TIM1 �����жϱ�־
    
    MPU_Get_Gyroscope();//��ȡ���ٶ�
    MPU_Get_Accelerometer();//��ȡ���ٶ�
    
    kalman_filter_pitch(atan2(accx , accz) * 180 / PI,-gyroy/16.384);//pitch �������˲�
    kalman_filter_roll(atan2(accy , accz) * 180 / PI,gyrox/16.384);//roll �������˲�

//     Yijielvbo(atan2(accy , accz) * 180, gyrox/16.384);
//     Erjielvbo(atan2(accy , accz) * 180,gyrox/16.384);
       
       
       
    static u8 counter=0;//100ms������ ��ȡ������
    static u8 counter_10 = 0;
    counter++;
    counter_10++;
    if(counter_10==4)
    {
      counter_10=0;
      encoder_walk = TIM_Get_Counter(2);
      speed_loop();//�⻷�ٶȻ�
      
      static float k=19.945,b=0.15,disbuff;
      static int adc_get;
      adc_get = Get_Adc(2);
      disbuff = ((float)adc_get*3.3/4096.0-b)/k;
      distance = (int)(1/disbuff);
      distance = distance<12?12:distance;
      distance = distance>60?60:distance;
      
      /*------------������ʾ------------*/
      if(follow_flag)
        adc_pid();
      else speed_set = 0;
      /*------------Ѱ����ʾ------------*/
      if(go_line_flag)
        go_line();
      
    }
//    if(counter==10)
//    {
//      static float k=19.945,b=0.15,disbuff;
//      static int adc_get;
//      adc_get = Get_Adc(2);
//      disbuff = ((float)adc_get*3.3/4096.0-b)/k;
//      distance = (int)(1/disbuff);
//      distance = distance<12?12:distance;
//      distance = distance>60?60:distance;
//      
//      /*------------������ʾ------------*/
//      if(follow_flag)
//        adc_pid();
//      else speed_set = 0;
//      /*------------Ѱ����ʾ------------*/
//      if(go_line_flag)
//        go_line();
//    }
    
    Z_angle_control();//���Ʒ���
    
    
    if(counter==20)//100ms
    { 
      counter=0;
      
//      encoder_walk = TIM_Get_Counter(2);
//      speed_loop();//�⻷�ٶȻ�
      
      encoder_fly = -TIM_Get_Counter(4);
      voltage=(float)Get_Adc(5)*3.3/4096*6.1;
    } 
    
    roll_setoff-=encoder_fly*0.00005;
    roll_setoff = roll_setoff>(rol+1)?(rol+1):roll_setoff;
    roll_setoff = roll_setoff<(rol-1)?(rol-1):roll_setoff;
    
    
    if(start_flag==0)
    {
      roll_setoff = rol;
      pitch_setoff = pit;
    }
    
    LQR_control();//����LQR����
//    angle_loop();//���⻷ �ǶȻ�
    inner_loop();//�ڻ� ���ٻ�
    
    PWM_out1 = (int)torque ;//������ΪŤ�غ�PWM������
    PWM_out2 = (int)inner_out;
    Motor_control();
  }
}
/*
K[3] = [k1 k2 k3]

X[3]=    -   pitch    -
        |    gyroy     |        
        |    encoder1  |
         -            -
���ȷ��X�ķ��ţ�pitch����0ʱ��gryo����0��������ת�ı�������������0 ���ݾ����������ż���
*/
float K[3]={0,0,0};//�������� ��matlab��� 
float torque=0;//���Ť��
float X[3]={0,0,0};//״̬���� �о���
float roll_setoff=0;
void LQR_control(void)//LQR������ ���Ʒ���
{
  X[0] = roll-roll_setoff;
  X[1] = gryo_x_b;//�ɿ������˲��õ������Ž��ٶ�
  X[2] = encoder_fly*81.8;
  torque=- (K[0]*X[0]+K[1]*X[1]+K[2]*X[2]);
  
  if(fabs(X[0])>15) 
    start_flag=0;
}
/*===============*/
//���⻷ �ٶȻ� 
float speed_set=0,speed_p,speed_i,speed_out;
float speed_error;
float speed_inter,speed_limit=10000;
void speed_loop()
{
  speed_error = 0 - encoder_walk;
  speed_inter+=speed_error;
  
  speed_inter = speed_inter - speed_set;
  
  speed_inter = speed_inter>speed_limit?speed_limit:speed_inter;
  speed_inter = speed_inter<-speed_limit?-speed_limit:speed_inter;
   
  speed_out = speed_error*speed_p + speed_inter*speed_i;
  speed_out/=10;
  
    if(start_flag==0) 
    speed_inter=0;
  
}
/*=====�⻷ �ǶȻ�======*/
//float pitch_setoff,pitch_p,pitch_d,last_pitch,pitch_out;
//void angle_loop()
//{
//   pitch_out =(speed_out + pitch_setoff - pitch)*pitch_p + pitch_d*(pitch-last_pitch);
//   last_pitch = pitch;
//}
/*======�ڻ� �ǶȻ�=====*/
float inner_p,inner_d,last_gyro,inner_out;
float pitch_setoff;
void inner_loop()
{
  inner_out = (speed_out + pitch_setoff - pitch)*inner_p + inner_d*gyroy;
}
/*==========ADC���PID ����ı��ٶ�ֵ===========*/
int follow_flag=0;
float adc_p=2,adc_d=0;
float adc_error,adc_errorlast;;
float adc_out;
void adc_pid()
{
  adc_error = distance-18;
  if(fabs(adc_error)>30)
    adc_error=0;
  adc_out = adc_p*adc_error + adc_d*(adc_error-adc_errorlast );
  adc_errorlast = adc_error;
  adc_out = adc_out>10?10:adc_out;
  adc_out = adc_out<-10?-10:adc_out;
  speed_set = adc_out;
  
}
int direct_ro=0;

int go_line_flag=0;//�ǵøĻ�������������������������������
u8 L1,L2,L3,R1,R2,R3;
void go_line()//���ڹ��Թ�ֻ�м򵥵�����0 1 �����Կ����޷�̫׼ȷ
{
  L1 = L1_READ;
  L2 = L2_READ;
  L3 = L3_READ;
  
  R1 = R1_READ;
  R2 = R2_READ;
  R3 = R3_READ;
  if(L1==1)//��������� ����ת ͬʱ�ٶȽ���
  {
    fankui=1;
    direct_ro=1;
    speed_set=3;
  }
   else if(R1==1)//
  {
    fankui=-1;
    direct_ro=2;
    speed_set=3;
  }
  //////////////////////////////////////////
   else if(L2==1)//
  {
    fankui=2;
     direct_ro=3;
    speed_set=0;
  }
     else if(R2==1)//
  {
    fankui=-2;
     direct_ro=4;
    speed_set=0;
  }
  ////////////////////////////////////////////
     else if(L3==1)//
     {
       fankui=3;
       direct_ro=5;
       speed_set=-1;
     }
     else if(R3==1)//
     {
       fankui=-3;
       direct_ro=6;
       speed_set=-1;
     }
  else if(L1==0&&L2==0&&L3==0&&R1==0&&R2==0&&R3==0)
  {
    fankui=0;
    z_tar=0;
    speed_set=4;
    direct_ro=0;
  }
  

}
/*-------------��ת����  z_tarΪ0  ����ֱ��--------------------*/
int last_gyroz;
int z_con_out;
float z_p=30,z_d=0;
int z_tar=0;
void Z_angle_control(void)
{
  
  z_con_out = (int)(z_p*(gyroz-z_tar)+z_d*(gyroz-last_gyroz));
  last_gyroz= gyroz;
  z_con_out=z_con_out>7000?7000:z_con_out;
  z_con_out=z_con_out<-7000?-7000:z_con_out;
  
  switch( direct_ro)
  {
  case 1:z_con_out = -5000;break;
  case 2:z_con_out = 5000;break;
  case 3:z_con_out = -6000;break;
  case 4:z_con_out = 6000;break;
  case 5:z_con_out = -7000;break;
  case 6:z_con_out = 7000;break;
  }
  
  if(z_con_out>=0)
  {
    TIM5->CCR4 = z_con_out;
    PFout(11)=1;
    PFout(12)=0;
  }
  if(z_con_out<0)
  {
    TIM5->CCR4 = -z_con_out;
    PFout(11)=0;
    PFout(12)=1;
  }
    
  if(start_flag==0) 
  {
    TIM5->CCR4 = 0;
    PFout(11)=0;
    PFout(12)=0;
  }
  
  if(z_con_out>0)//����û���ٶȷ��������Գ�����PWM���������̬
    z_con_out-=10;
  if(z_con_out<0)
    z_con_out+=10;
  
  
}