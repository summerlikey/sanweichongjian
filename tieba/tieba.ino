int servopin = 6; //定义舵机接口数字接口7 也就是舵机的橙色信号线。

void setup(){

pinMode(servopin,OUTPUT);//设定舵机接口为输出接口

}

void servopulse( int pulsewidth)//定义一个脉冲函数
{
digitalWrite(servopin,HIGH); //将舵机接口电平至高
Serial.println(1);
delayMicroseconds(pulsewidth); //延时脉宽值的微秒数

digitalWrite(servopin,LOW); //将舵机接口电平至低
Serial.println(0);
delayMicroseconds(20000-pulsewidth);


}

//主循环
void loop() {

for(int i=0;i<=50;i++)//给予舵机足够的时间让它转到指定角度
{ servopulse(560); //引用脉冲函数
}
delay(2000); 
for(int i=0;i<=50;i++)//给予舵机足够的时间让它转到指定角度
{servopulse(600); //引用脉冲函数
}
delay(2000);
for(int i=0;i<=50;i++)//给予舵机足够的时间让它转到指定角度
{servopulse(1260); //引用脉冲函数
} 
delay(2000);

}

