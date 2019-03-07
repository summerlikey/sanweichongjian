clc;clear;clf;
%原始数据的定义
%X=-15:5:15;%两边为最大最小值，中间为刻度值需要和Y一样
%Y=-15:0.1:15;%两边为最大最小值，中间为刻度值需要和X一样
h=[0.154 0.154 0.178 0.141 0.141 0.155 0.145 0.143 0.160];
x=[0.03496 0.00000 -0.04040 0.03291 0.00000 -0.03618 0.03291 0.00000 -0.03632];
y=[-0.03594 -0.03594 -0.04154 0.00000 0.00000 0.00000 0.03384 0.03337 0.03734 ];

%[X,Y]=meshgrid(X,Y);%利用meshgrid生成格点矩阵
z=[0.145609 0.145609 0168301 0.133317 0.133317 0.146554 0.137099 0.135208 0.151282];
scatter(x,y,5,z)%散点图
[X,Y,Z]=griddata(x,y,z,linspace(-0.045,0.045)',linspace(0.04,0.04),'v4');%插值
pcolor(X,Y,Z);shading interp%伪彩色图
figure,contourf(X,Y,Z) %等高线图
figure,surf(X,Y,Z)%三维曲面
%mesh(X,Y,Z)%绘制的是网格划分的图
%surf(X,Y,Z)%曲面图的绘制
[xq,yq] = meshgrid(-3:0.1:3);
z4 = griddata(x,y,z,xq,yq,'cubic');
figure
plot3(x,y,z,'mo')
hold on
mesh(xq,yq,z4)
title('Cubic')
legend('Sample Points','Interpolated Surface','Location','NorthWest')