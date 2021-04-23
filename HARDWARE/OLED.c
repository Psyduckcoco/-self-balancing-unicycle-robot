#include "includes.h"

const unsigned char F6x8[][6] =
{
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
  { 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
  { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
  { 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
  { 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
  { 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 },   // %
  { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
  { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
  { 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
  { 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
  { 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
  { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
  { 0x00, 0x00, 0x00, 0xA0, 0x60, 0x00 },   // ,
  { 0x00, 0x08, 0x08, 0x08, 0x08, 0x08 },   // -
  { 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
  { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 },   // /
  { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
  { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
  { 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
  { 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
  { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
  { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
  { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
  { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
  { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
  { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9
  { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
  { 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
  { 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 },   // <
  { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
  { 0x00, 0x00, 0x41, 0x22, 0x14, 0x08 },   // >
  { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
  { 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E },   // @
  { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C },   // A
  { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
  { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
  { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
  { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
  { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
  { 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
  { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
  { 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
  { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
  { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
  { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
  { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
  { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
  { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
  { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
  { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
  { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
  { 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
  { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
  { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
  { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
  { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
  { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
  { 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
  { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z
  { 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [ 91
  { 0x00, 0x02, 0x04 ,0x08, 0x10, 0x20 },    // \92
  { 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
  { 0x00, 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^
  { 0x00, 0x40, 0x40, 0x40, 0x40, 0x40 },   // _
  { 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 },   // '
  { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
  { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
  { 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
  { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
  { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
  { 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
  { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C },   // g
  { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
  { 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
  { 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 },   // j
  { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
  { 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
  { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
  { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
  { 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
  { 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 },   // p
  { 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC },   // q
  { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
  { 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
  { 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
  { 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
  { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
  { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
  { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
  { 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },   // y
  { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z
  { 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 }    // horiz lines
};


void LED_Writedata(unsigned char data)
{//д���ݺ���
      u8 i = 8;
      LED_DC(1);
      asm("nop");
      LED_SCLK(0);
      asm("nop");
      while(i--)
      {
        
        if (data & 0x80)
        {
          LED_SDA(1);
        }
        else
        {
          LED_SDA(0);
        }
        LED_SCLK(1);
        asm("nop");
        LED_SCLK(0);
        data <<= 1;
      }
}
   
void LED_WrCmd(unsigned char cmd) 
{//д�������
      u8 i = 8;
      //LED_CS = 0;
      LED_DC(0);
      LED_SCLK(0);
      while (i--)
      {
        if (cmd & 0x80)
        {
          LED_SDA(1);
        }
        else
        {       
          LED_SDA(0);
        }
        LED_SCLK(1);
        asm("nop");           
        LED_SCLK(0);    
        cmd <<= 1;   
      }
}


void LED_Set_Pos(u8 x,u8 y)
{ //�趨λ��
      LED_WrCmd(0xb0+y);
      LED_WrCmd(((x&0xf0)>>4)|0x10);
      LED_WrCmd((x&0x0f)|0x00); 
}


//ȫ��    LED_Fill(0xff);//����    LED_Fill(0x00);//����
//������MCRC��ǰ����
void  LED_Fill(u8 bmp_data)
{	
  u8 y,x;
  for(y=0;y<8;y++)
  {
    LED_WrCmd(0xb0+y);
    LED_WrCmd(0x01);
    LED_WrCmd(0x10);
    for(x=0;x<=128;x++)
      LED_Writedata(bmp_data);
  }
}

void  LED_Cls_chinese(void)
{	
  u8 y,x;
  for(y=6;y<8;y++)
  {
    LED_WrCmd(0xb0+y);
    LED_WrCmd(0x01);
    LED_WrCmd(0x10);
    for(x=0;x<=128;x++)
      LED_Writedata(0x00);
  }
}
//LED����
void LED_CLS(void)
{
  u8 x,y;
  for(y=0;y<8;y++)
  {
    LED_WrCmd(0xb0+y);
    LED_WrCmd(0x01);
    LED_WrCmd(0x10);
    for(x=0;x<=128;x++)
      LED_Writedata(0);
  }
}

void LED_DLY_ms(u16 ms)
{//��ʱ����                      
  u16 a;
  while(ms)
  {
    a=6675;
    while(a--);
    ms--;
  }
  return;
}


//��ʾһ��6x8��׼ASCII�ַ�
void LED_P6x8Char(unsigned char x,unsigned char y,unsigned char ch)
{
  unsigned char c=0,i=0;     
  
  c =ch-32;
  if(x>126)
  {
    x=2;
    y++;
  }
  LED_Set_Pos(x,y);    
  for(i=0;i<6;i++)
  {     
    LED_Writedata(F6x8[c][i]);  
  }
}

//==============================================================
//��������LED_P6x8Str(unsigned char x,unsigned char y,unsigned char *p)
//����������д��һ���׼ASCII�ַ���
//��������ʾ��λ�ã�x,y����yΪҳ��Χ0��7��Ҫ��ʾ���ַ���
//���أ���
//==============================================================  
void LED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[])
{
  unsigned char c=0,i=0,j=0;      
  while (ch[j]!='\0')
  {    
    c =ch[j]-32;
    if(x<2)
    {
      x=2;
    }
    if(x>126)
    {
      x=2;
      y++;
    }
    LED_Set_Pos(x,y);    
    for(i=0;i<6;i++) 
    {
      LED_Writedata(F6x8[c][i]);  
    }
    x+=6;
    j++;
  }
}
//==============================================================
//�������� LED_Point(unsigned int x,unsigned int y)
//��������������һ���㣨x,y��
//��������ʵ����ֵ(x,y),x�ķ�Χ0��127��y�ķ�Χ0��64
//���أ���
//==============================================================
void LED_Point(unsigned int x,unsigned int y)
{
  unsigned int data1;//data1��ǰ�������
  LED_Set_Pos(x,y>>3);
  data1 = 0x01<<(y%8);
  LED_Writedata(data1);	
}

void LED_PrintValueI(unsigned char x, unsigned char y, int data)
{//������������һ��int����ת����5λ��������ʾ
  unsigned char i,j,k,l,m;  
  if(data < 0)
  {
    LED_P6x8Char(x,y,'-');
    data = - data;	
  }
  
  l  = data/10000;
  m= (data%10000)/1000;
  i = (data%1000)/100;
  j = (data%100)/10;
  k = data%10;
  
  if(l!=0)
  {
  LED_P6x8Char(x,y,l+48);
  }
  if(m!=0)
  {
  LED_P6x8Char(x+2,y,m+48);
  }
  if(i!=0)
  {
  LED_P6x8Char(x+4,y,i+48);
  }
  if(j!=0)
  {
  LED_P6x8Char(x+6,y,j+48);
  }
  LED_P6x8Char(x+8,y,k+48);		
}

void LED_PrintValueFP(unsigned char x, unsigned char y, unsigned int data, unsigned char num)
{//��ʾunsigned int��
  signed char m,i,j,k;  	
//  LED_P6x8Char(x, y, '.');
  m= data/1000;
  i = (data%1000)/100;
  j = (data%100)/10;
  k = data%10;
  switch(num)
  {
  case 1:  	LED_P6x8Char(x+6,y,k+48);
  break;
  case 2:  	LED_P6x8Char(x+6,y,j+48);
  LED_P6x8Char(x+12,y,k+48);
  break;
  case 3: 	LED_P6x8Char(x+6,y,i+48);
  LED_P6x8Char(x+12,y,j+48);
  LED_P6x8Char(x+18,y,k+48);
  break;
  case 4: 	
  LED_P6x8Char(x+6,y,m+48);
  LED_P6x8Char(x+12,y,i+48);
  LED_P6x8Char(x+18,y,j+48);
  LED_P6x8Char(x+24,y,k+48);
  break;	
  }
}

void LED_PrintValueFPP(unsigned char x, unsigned char y, unsigned int data, unsigned char num)
{
  signed char m,i,j,k;  	
  //LED_P6x8Char(x, y, '.');
  m= data/1000;
  i = (data%1000)/100;
  j = (data%100)/10;
  k = data%10;
  switch(num)
  {
  case 1:  	LED_P6x8Char(x+6,y,k+48);
  break;
  case 2:  	LED_P6x8Char(x+6,y,j+48);
  LED_P6x8Char(x+12,y,k+48);
  break;
  case 3: 	LED_P6x8Char(x+6,y,i+48);
  LED_P6x8Char(x+12,y,j+48);
  LED_P6x8Char(x+18,y,k+48);
  break;
  case 4: 	LED_P6x8Char(x+6,y,m+48);
  LED_P6x8Char(x+12,y,i+48);
  LED_P6x8Char(x+18,y,j+48);
  LED_P6x8Char(x+24,y,k+48);
  break;	
  }
}

//������������һ��float����ת������������5λ��С���ͷ��ŵ����ݲ�������ʾ
void LED_PrintValueF(unsigned char x, unsigned char y, float data, unsigned char num)
{
  unsigned char l,m,i,j,k;  //��ǧ��ʮ��
  unsigned char databiti = 6; //����λ��
  unsigned int tempdataui = 0;
  int tempdataii = (int)data; //��������
  long int tempdatalp = (long int)((data - (int)data)*10000); //ȡС��λ��4λ
  
  //����������ʾ
  if(data < -0.0000001)  LED_P6x8Char(x, y,'-'); 
   else LED_P6x8Char(x, y,' ');
  if(tempdataii < 0)tempdataii = - tempdataii;  //ȥ���������ָ���
  tempdataui = tempdataii;
  l  = tempdataui/10000;
  m= (tempdataui%10000)/1000;
  i = (tempdataui%1000)/100;
  j = (tempdataui%100)/10;
  k = tempdataui%10;
  if (l != 0)  //��λ
  {
    LED_P6x8Char(x+6,y,l+48);
    LED_P6x8Char(x+12,y,m+48);
    LED_P6x8Char(x+18,y,i+48);
    LED_P6x8Char(x+24,y,j+48);
    LED_P6x8Char(x+30,y,k+48);
  }
  else if(m != 0) //��λ
  {
    databiti = 5;
    LED_P6x8Char(x+6,y,m+48);
    LED_P6x8Char(x+12,y,i+48);
    LED_P6x8Char(x+18,y,j+48);
    LED_P6x8Char(x+24,y,k+48);
  }
  else if(i != 0) //��λ
  {
    databiti = 4;
    LED_P6x8Char(x+6,y,i+48);
    LED_P6x8Char(x+12,y,j+48);
    LED_P6x8Char(x+18,y,k+48);
  }
  else if(j != 0) //��λ
  {
    databiti = 3;	
    LED_P6x8Char(x+6,y,j+48);
    LED_P6x8Char(x+12,y,k+48);
  }
  else 	
  {
    databiti = 2;
    LED_P6x8Char(x+6,y,k+48);
  }	
  if(tempdatalp < 0)tempdatalp = - tempdatalp;	//ȥ��С�����ָ���
  switch(num)
  {
  case 0: break;
  case 1:  LED_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 1000),num);LED_P6x8Char(x + databiti * 6, y, '.');break;
  case 2:  LED_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 100),num);LED_P6x8Char(x + databiti * 6, y, '.');break;
  case 3:  LED_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 10),num);LED_P6x8Char(x + databiti * 6, y, '.');break;
  case 4:  LED_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp),num);LED_P6x8Char(x + databiti * 6, y, '.');break;					
  }
}

void OLED_Init(void)
{
    GPIO_InitTypeDef  GPIO_OledInitTypeDef;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOG|RCC_APB2Periph_AFIO, ENABLE );//PORTB ʱ��ʹ��
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    
    
    GPIO_OledInitTypeDef.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
    GPIO_OledInitTypeDef.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_OledInitTypeDef.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_OledInitTypeDef);
    
    GPIO_OledInitTypeDef.GPIO_Pin=GPIO_Pin_15;
    GPIO_OledInitTypeDef.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_OledInitTypeDef.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOG,&GPIO_OledInitTypeDef);
    
  LED_SCLK(1);		
  LED_RST(0);
  delay_ms(50);
  LED_RST(1);
  LED_WrCmd(0xae);//--turn off oled panel
  LED_WrCmd(0x00);//---set low column address
  LED_WrCmd(0x10);//---set high column address
  LED_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
  LED_WrCmd(0x81);//--set contrast control register
  LED_WrCmd(0xcf);// Set SEG Output Current Brightness
  LED_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
  LED_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
  LED_WrCmd(0xa6);//--set normal display
  LED_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
  LED_WrCmd(0x3f);//--1/64 duty
  LED_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
  LED_WrCmd(0x00);//-not offset
  LED_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
  LED_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
  LED_WrCmd(0xd9);//--set pre-charge period
  LED_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  LED_WrCmd(0xda);//--set com pins hardware configuration
  LED_WrCmd(0x12);
  LED_WrCmd(0xdb);//--set vcomh
  LED_WrCmd(0x40);//Set VCOM Deselect Level
  LED_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
  LED_WrCmd(0x02);//
  LED_WrCmd(0x8d);//--set Charge Pump enable/disable
  LED_WrCmd(0x14);//--set(0x10) disable
  LED_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
  LED_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7) 
  LED_WrCmd(0xaf);//--turn on oled panel
  LED_Fill(0x00);//��ʼ����
  LED_Set_Pos(0,0); 
}












