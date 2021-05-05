M = 0.3024;%��������
R = 0.056;%���ְ뾶

L = 0.1225;%�������ĵ��׶˾���

m = 0.8718;%���˷��ֺ���ת��֮���ȫ������  
l = 0.0935  ;%���˷���֮������������ĵ��׶˾��� 

m3=0.145;%��ת������
l3=0.22;%��ת�����ĵ��������

g=9.8;%�������ٶ�
Ipb = m*l*l;
%  Iwc = 0.00019685 ;%����solidworks��ֱ�ӵó� kg.m^2
 Iwc = 0.5*M*R*R;%����solidworks��ֱ�ӵó� kg.m^2
a = M*L*L + Ipb+m3*l3*l3;
b = m*l + M*L+m3*l3;
A = [0      1   0
     b*g/a  0   0
     -b*g/a 0   0
    ];%״̬����
B = [0;-1/a;(a+Iwc)/(a*Iwc)];%�������
C = [1 0 0];   %�۲�Ƕ�  
D = 0;

Q = [10000000*5 0 0 
     0 100000 0 
     0 0 110
    ];  

R = 1000;

%����K  
K = lqr(A,B,Q,R);  
Ac = A - B*K;  
%��ϵͳ����ģ��  
x0 = [-6.56;0;0]; %��ʼ״̬  
t = 0:0.01:7.5;  
u = zeros(size(t));  
[y,x]=lsim(Ac,B,C,D,u,t,x0);

% uu =  zeros(size(t)); 
% ii=1;
% for i = 0:0.01:5
%  uu(ii) = -(K(1)*x(ii,1) + K(2)*x(ii,2) + K(3)*x(ii,3));
%  ii=ii+1;
% end

figure(1);
plot(t,y,'r');hold on;
% title('���߶���ͼ');
% 
% aaa=xxx(565:1300,:)/100+0.2;
% t=(0:size(aaa,1)-1)*0.01;
% for i=1:1:size(aaa)
%         if(aaa(i)>0.7)aaa(i)=aaa(i)/3;
%         end
% end
% plot(t,aaa/2,'b');

% hold on;
% legend('��������','ʵ������');

xlabel('ʱ�䣨s��');
ylabel('�����(��)');

% figure(3);
% plot(t,uu); 
% title('���');
% 
% figure(4);
% plot(t,x(1:61,3)*0.1/360*44);
% title('������');
