figure(1);
a=before(100:2000,:)/100;
b=after(1200:3100,:)/200;
t=(0:size(a,1)-1)*0.01;

plot(t,a,'r');
hold on;
plot(t,b,'b');
hold on;

legend('δ�ӿ���','������');
title('���߶���ͼ');
xlabel('ʱ�䣨s��');
ylabel('Z����ٶ�ԭʼ����');

