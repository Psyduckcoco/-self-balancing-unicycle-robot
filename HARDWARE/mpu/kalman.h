#ifndef _kalman_H
#define _kalman_H
#include "includes.h"

void kalman_filter_pitch(float angle_m,float gryo_m);
void kalman_filter_roll(float angle_m,float gyro_m);

extern float gryo_y_b;//���Ž��ٶ�
extern float gryo_x_b;//���Ž��ٶ�
void Yijielvbo(float angle_m, float gyro_m);//�ɼ������ĽǶȺͽǼ��ٶ�
void Erjielvbo(float angle_m,float gyro_m);//�ɼ������ĽǶȺͽǼ��ٶ�
extern float angle1;extern float angle2;

#endif