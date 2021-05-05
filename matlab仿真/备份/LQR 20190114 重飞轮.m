M = 0.3025;%��������
R = 0.056;%���ְ뾶
L = 0.151;%�������ĵ��׶˾���

m = 0.9313;%���˷���֮���ȫ������
l = 0.085    ;%���˷���֮������������ĵ��׶˾��� 

g=9.8;%�������ٶ�
 Ipb = m*l*l;
 Iwc = 0.5*M*R*R;%����solidworks��ֱ�ӵó� kg.m^2
a = M*L*L + Ipb;
b = m*l + M*L;
A = [0      1   0
     b*g/a  0   0
     -b*g/a 0   0
    ];%״̬����
B = [0;1/a;-(a+Iwc)/(a*Iwc)];%�������
C = [1 0 0];   %�۲�Ƕ�  
D = 0;

Q = [10000000 0 0 
     0 1000 0 
     0 0 200
    ];  
R = 1;

%����K  
K = lqr(A,B,Q,R);  
Ac = A - B*K;  
%��ϵͳ����ģ��  
x0 = [2;0;0]; %��ʼ״̬  
t = 0:0.05:3;  
u = zeros(size(t));  
[y,x]=lsim(Ac,B,C,D,u,t,x0);

uu =  zeros(size(t)); 
ii=1;
for i = 0:0.05:3
 uu(ii) = -(K(1)*x(ii,1) + K(2)*x(ii,2) + K(3)*x(ii,3));
 ii=ii+1;
end
figure(1);
plot(t,y);
title('pitch');
% figure(2);
% plot(t,y,t,uu);  
figure(3);
plot(t,uu); 
title('���');
figure(4);
plot(t,x(1:61,3)*0.1/360*44);
title('���ٶ� ������');
