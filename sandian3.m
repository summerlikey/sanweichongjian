clc;clear;clf;
%ԭʼ���ݵĶ���
%X=-15:5:15;%����Ϊ�����Сֵ���м�Ϊ�̶�ֵ��Ҫ��Yһ��
%Y=-15:0.1:15;%����Ϊ�����Сֵ���м�Ϊ�̶�ֵ��Ҫ��Xһ��
h=[0.154 0.154 0.178 0.141 0.141 0.155 0.145 0.143 0.160];
x=[0.03496 0.00000 -0.04040 0.03291 0.00000 -0.03618 0.03291 0.00000 -0.03632];
y=[-0.03594 -0.03594 -0.04154 0.00000 0.00000 0.00000 0.03384 0.03337 0.03734 ];

%[X,Y]=meshgrid(X,Y);%����meshgrid���ɸ�����
z=[0.145609 0.145609 0168301 0.133317 0.133317 0.146554 0.137099 0.135208 0.151282];
scatter(x,y,5,z)%ɢ��ͼ
[X,Y,Z]=griddata(x,y,z,linspace(-0.045,0.045)',linspace(0.04,0.04),'v4');%��ֵ
pcolor(X,Y,Z);shading interp%α��ɫͼ
figure,contourf(X,Y,Z) %�ȸ���ͼ
figure,surf(X,Y,Z)%��ά����
%mesh(X,Y,Z)%���Ƶ������񻮷ֵ�ͼ
%surf(X,Y,Z)%����ͼ�Ļ���
[xq,yq] = meshgrid(-3:0.1:3);
z4 = griddata(x,y,z,xq,yq,'cubic');
figure
plot3(x,y,z,'mo')
hold on
mesh(xq,yq,z4)
title('Cubic')
legend('Sample Points','Interpolated Surface','Location','NorthWest')