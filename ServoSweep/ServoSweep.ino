/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块
 舵机左右摇摆功能
 德飞莱LY-51S独立模块开发板有舵机功能块，与arduino的连接图片和说明如下：
 http://www.doflye.net/viewthread.php?tid=5311&extra=
*/
#include <Servo.h> 
 
Servo myservo;  // 
                // 最多可以控制8路舵机
 
int pos = 0;    // 用于存储舵机位置的变量
//初始化
void setup() 
{ 
  myservo.attach(9);  // 舵机控制信号引脚 
} 
 
//主循环
void loop() 
{ 
  // 从0度-180度
  {                                  // 步进角度1度
    myservo.write(180);              // 输入对应的角度值，舵机会转到此位置
                         // 15ms后进入下一个位置 
  } 
  delay(10000);
    // 从180度-0度 
  {                                
    myservo.write(0);              // 输入对应的角度值，舵机会转到此位置 
                           // 15ms后进入下一个位置
  } 
  delay(10000);
} 
