#include "includes.h"
#include "kalman.h"

float gryo_y_b;//������y����ٶ�
void kalman_filter_pitch(float angle_m,float gyro_m)//������� �����ĽǶ� �� �����Ľ��ٶ�  ����kalman_filter_pitch(atan2(accx , accz) * 180 / PI,-gyroy/16.384);
{
  float Q_angle = 0.001;
  float Q_gyroBias = 0.003;
  float R_measure = 0.03;
  static float P[2][2];
  float K[2];//����������
  float y,s;//�в�  �� �в�Э����
  static float bias;//���ٶ�ƫ�� Ư�����
  float P00_temp,P01_temp;
  float dt = 0.005;//�˲�������ʱ�� ����Ϊ�Ƕ�ʱ��ʱ��
  pitch+=dt*(float)(gyro_m - bias);//��ʱ��Ԥ��ֵ
  
  P[0][0] += dt*(dt*P[1][1]-P[1][0]-P[0][1]+Q_angle);//�������Э������� ��Ե�ǰԤ��״̬�����ζ�
  P[0][1] -= dt*P[1][1]; 
  P[1][0] -= dt*P[1][1];
  P[1][1] += dt*Q_gyroBias;
  
  y = angle_m - pitch;//����в� �����ֵ��Ԥ��ֵ��ƫ��̶�
  
  s = P[0][0]+R_measure;//����в�Э���� Խ���ʾ����Խ�� ���ܹ������β���ֵ
  
  K[0] = P[0][0]/s;//���㿨�������� ��ʾ�Բв�����γ̶� ���γ̶�Խ�� �Ե�ǰ״̬������ֵ�����ζ�ԽС
  K[1] = P[1][0]/s;
  
  pitch+=K[0]*y;//���µ�ǰ״̬�������
  bias+=K[1]*y;
  gryo_y_b=gyro_m-bias;//���Ž��ٶ�
  
  P00_temp=P[0][0];//����Э�������
  P01_temp=P[0][1];
  P[0][0]-=K[0]*P00_temp;
  P[0][1]-=K[0]*P01_temp;
  P[1][0]-=K[1]*P00_temp;
  P[1][1]-=K[1]*P01_temp;
  
}
//roll���˲� ͬ��
float gryo_x_b;//������x����ٶ�
void kalman_filter_roll(float angle_m,float gyro_m)
{
  float Q_angle = 0.001;
  float Q_gyroBias = 0.003;
  float R_measure = 0.03;
  static float P[2][2];
  float K[2];//����������
  float y,s;//�в�  �� �в�Э����
  static float bias;//���ٶ�ƫ�� Ư�����
  float P00_temp,P01_temp;
  float dt = 0.005;//�˲�������ʱ�� ����Ϊ�Ƕ�ʱ��ʱ��
  roll+=dt*(float)(gyro_m - bias);//��ʱ��Ԥ��ֵ
  
  P[0][0] += dt*(dt*P[1][1]-P[1][0]-P[0][1]+Q_angle);//�������Э������� ��Ե�ǰԤ��״̬�����ζ�
  P[0][1] -= dt*P[1][1]; 
  P[1][0] -= dt*P[1][1];
  P[1][1] += dt*Q_gyroBias;
  
  y = angle_m - roll;//����в� �����ֵ��Ԥ��ֵ��ƫ��̶�
  
  s = P[0][0]+R_measure;//����в�Э���� Խ���ʾ����Խ�� ���ܹ������β���ֵ
  
  K[0] = P[0][0]/s;//���㿨�������� ��ʾ�Բв�����γ̶� ���γ̶�Խ�� �Ե�ǰ״̬������ֵ�����ζ�ԽС
  K[1] = P[1][0]/s;
  
  roll+=K[0]*y;//���µ�ǰ״̬�������
  bias+=K[1]*y;
  gryo_x_b=gyro_m-bias;//���Ž��ٶ�
  
  P00_temp=P[0][0];//����Э�������
  P01_temp=P[0][1];
  P[0][0]-=K[0]*P00_temp;
  P[0][1]-=K[0]*P01_temp;
  P[1][0]-=K[1]*P00_temp;
  P[1][1]-=K[1]*P01_temp;
  
}



//һ�׻����˲�
float K1 =0.05; // �Լ��ٶȼ�ȡֵ��Ȩ��
float dt=0.005;//ע�⣺dt��ȡֵΪ�˲�������ʱ��
float angle1;
void Yijielvbo(float angle_m, float gyro_m)//�ɼ������ĽǶȺͽǼ��ٶ�
{
     angle1 = K1 * angle_m+ (1-K1) * (angle1 + gyro_m * dt);
}
float K2 =0.2; // �Լ��ٶȼ�ȡֵ��Ȩ��
float x1,x2,y1;
float angle2;

void Erjielvbo(float angle_m,float gyro_m)//�ɼ������ĽǶȺͽǼ��ٶ�
{
    x1=(angle_m-angle2)*(1-K2)*(1-K2);
    y1=y1+x1*dt;
    x2=y1+2*(1-K2)*(angle_m-angle2)+gyro_m;
    angle2=angle2+ x2*dt;
}


