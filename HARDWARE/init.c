#include "init.h"
#include "includes.h"
/*--------PID��ʼ��------*/
void parameter_Init(void)
{
//  
//  K[0] = 0;
//  K[1] = 0;
//  K[2] = 0;
//  
//  pitch_P = 0;
//  pitch_D = 0;
//  encoder_P = 0;
//  encoder_I=0;
  
  
  
  K[0] = 6581.3;
  K[1] = 592.2085;
  K[2] = 6.3246;
  
  
  inner_p = 1400;
  inner_d = 1.69;
  speed_p=1.6;
  speed_i=0.015;
  
//  pitch_P = 1080;
//  pitch_D = 1.2;
//  encoder_P = 30;
//  encoder_I=0.1;
//  
}
/*-------��ʼ����� TIM3-------*/
//TIM3->CCR1 = xxx;
void Tim3_init(u16 arr,u16 psc)
{
  /*��ʼ��IO��*/
  GPIO_InitTypeDef GPIO_InitStructure;
  //ʹ�ܵ���õ�ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOA, ENABLE); 
  //���õ��ʹ�õ��ùܽ�
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 ; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1  ; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  /*------------*/
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
  
  //��ʼ��TIM3
  TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
  TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
  
  //��ʼ��TIM3 Channel2 PWMģʽ	 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC1
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC3
  TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC4
  
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR1�ϵ�Ԥװ�ؼĴ���
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR3�ϵ�Ԥװ�ؼĴ���
  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR4�ϵ�Ԥװ�ؼĴ���
  
  
  TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
  
  TIM3->CCR1 = 0;
  TIM3->CCR2 = 0;
  TIM3->CCR3 = 0;
  TIM3->CCR4 = 0;
  
}
/*-------��ʼ����� TIM3-------*/
//TIM3->CCR1 = xxx;
void Tim5_init(u16 arr,u16 psc)
{
  /*��ʼ��IO��*/
  GPIO_InitTypeDef GPIO_InitStructure;
  //ʹ�ܵ���õ�ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOF , ENABLE); 
  //���õ��ʹ�õ��ùܽ�
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 ; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_12; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  
  /*------------*/
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
  
  //��ʼ��TIM3
  TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
  TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
  
  //��ʼ��TIM3 Channel2 PWMģʽ	 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  
  TIM_OC4Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC4
  
  TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR4�ϵ�Ԥװ�ؼĴ���
  
  
  TIM_Cmd(TIM5, ENABLE);  //ʹ��TIM3
  
  TIM5->CCR4 = 0;
  
  
}
/*-----��������ʼ�� TIM2----*/
void Encoder_Init_TIM2(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��4��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��PB�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;	//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOB
  
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // Ԥ��Ƶ�� 
  TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM���ϼ���  
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 6;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  //Reset counter  
  TIM_SetCounter(TIM2,0);
  TIM_Cmd(TIM2, ENABLE); 
}
/*-----��������ʼ�� TIM4----*/
void Encoder_Init_TIM4(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ�ܶ�ʱ��4��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��PB�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
  GPIO_Init(GPIOB, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOB
  
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // Ԥ��Ƶ�� 
  TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM���ϼ���  
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 6;
  TIM_ICInit(TIM4, &TIM_ICInitStructure);
  TIM_ClearFlag(TIM4, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
  //Reset counter
  TIM_SetCounter(TIM4,0);
  TIM_Cmd(TIM4, ENABLE); 
}

/*-----��ȡ������---*/
u16 TIM_Get_Counter(u8 TIMX)
{
  u16 Encoder_TIM;    
  switch(TIMX)
  {
  case 2:  Encoder_TIM= TIM2 -> CNT;  TIM2 -> CNT=0;break;
  case 4:  Encoder_TIM= TIM4 -> CNT;  TIM4 -> CNT=0;break;	
  default:  Encoder_TIM=0;
  }
  return Encoder_TIM;
}
/*------��ʼ����ʱ��TIM1---------*/
void TIM1_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//  NVIC_InitTypeDef NVIC_InitStructure2;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //��ʱ�� TIM1 ʹ��
  //��ʱ�� TIM1 ��ʼ��
  TIM_TimeBaseStructure.TIM_Period = arr; //�����Զ���װ�ؼĴ������ڵ�ֵ
  TIM_TimeBaseStructure.TIM_Prescaler =psc; //����ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM ���ϼ���
  TIM_TimeBaseStructure.TIM_RepetitionCounter=0; //�߼���ʱ��1���ö�ʱ��������������ſ����������ļ���Ƶ��һ��ʼ��72mhz ֵ��ע��ĵط�
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //�ڳ�ʼ�� TIM1
  TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE ); //����������ж�

//  //�ж����ȼ� NVIC ����
//  NVIC_InitStructure2.NVIC_IRQChannel = TIM1_UP_IRQn; //TIM1 �ж�
//  NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ� 1 ��
//  NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0; //�����ȼ� 3 ��
//  NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE; //IRQ ͨ����ʹ��
//  NVIC_Init(&NVIC_InitStructure2); //�ܳ�ʼ�� NVIC �Ĵ���
  
  TIM_Cmd(TIM1, ENABLE); //��ʹ�� TIM1
}
//��ʱ�� ����
void My_NVIC_Init(void)
{
  static NVIC_InitTypeDef  NVIC_InitStructure;
  /*Usart1 NVIC����*/
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;	//��ռ���ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//�����ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
  NVIC_Init(&NVIC_InitStructure);							//����ָ���Ĳ�����ʼ��VIC�Ĵ��� 
  
  static  NVIC_InitTypeDef NVIC_InitStructure2;
  //�ж����ȼ� NVIC ����
  NVIC_InitStructure2.NVIC_IRQChannel = TIM1_UP_IRQn; //TIM1 �ж�
  NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ� 1 ��
  NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0; //�����ȼ� 3 ��
  NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE; //IRQ ͨ����ʹ��
  NVIC_Init(&NVIC_InitStructure2); //�ܳ�ʼ�� NVIC �Ĵ���
  
  
}
void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC2	, ENABLE );	  //ʹ��ADC1ͨ��ʱ��
 

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

	//PA1 ��Ϊģ��ͨ����������                         
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//ģ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	ADC_DeInit(ADC2);  //��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//ģ��ת�������ڵ�ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//˳����й���ת����ADCͨ������Ŀ
	ADC_Init(ADC2, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   

  
	ADC_Cmd(ADC2, ENABLE);	//ʹ��ָ����ADC1
	
	ADC_ResetCalibration(ADC2);	//ʹ�ܸ�λУ׼  
	 
	while(ADC_GetResetCalibrationStatus(ADC2));	//�ȴ���λУ׼����
	
	ADC_StartCalibration(ADC2);	 //����ADУ׼
 
	while(ADC_GetCalibrationStatus(ADC2));	 //�ȴ�У׼����
 
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������

}				  
//���ADCֵ
u16 Get_Adc(u8 ch)   
{
  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC2, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����	  			    
  
	ADC_SoftwareStartConvCmd(ADC2, ENABLE);		//ʹ��ָ����ADC1�����ת����������	
	 
	while(!ADC_GetFlagStatus(ADC2, ADC_FLAG_EOC ));//�ȴ�ת������

	return ADC_GetConversionValue(ADC2);	//�������һ��ADC1�������ת�����
}
////���ADCֵ
//u16 Get_Adc_dis(u8 ch)   
//{
//  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
//	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����	  			    
//  
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������	
//	 
//	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������
//
//	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����
//}

void tube_init()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOC,ENABLE);//ʹ��PORTCʱ��
  
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //
  GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIO
  
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
  

}
