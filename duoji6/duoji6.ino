//UART send 1~9==>20~180 degree
int servopin=5;//设置舵机驱动脚到数字口9
int myangle;//定义角度变量
int pulsewidth;//定义脉宽变量
int val;
void setup(){
//TCCR2B = TCCR2B＆B11111000 | B00000001; //用于3引脚PWM频率31372.55 Hz
//TCCR2B=TCCR2B&B11111000|B00000110;//用于3引脚pwm的122.55hz 
TCCR0B=TCCR0B&B11111000|B00000101;//对5引脚pwm为61.04hz
pinMode(3,OUTPUT);
Serial.begin(9600);//设置波特率为9600


}
void servopulse(int servopin,int myangle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
  
 
 pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin,HIGH);//将舵机接口电平置高
//  delay(1500);//1500高电平
delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
digitalWrite(servopin,LOW);//将舵机接口电平置低
//  delay(1000);//1000低电平
delayMicroseconds(2480-pulsewidth);
//delay(20-pulsewidth/1000);//延时周期内剩余时间

}
void loop(){
//把你的主要代码放在这里，重复运行：
//将您的设置代码放在这里，运行一次：
 pulsewidth=600+500;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin,HIGH);//将舵机接口电平置高
//  delay(1500);//1500高电平
delayMicroseconds(1100);//延时脉宽值的微秒数
digitalWrite(servopin,LOW);//将舵机接口电平置低
//  delay(1000);//1000低电平
delayMicroseconds(2480-pulsewidth);
//delay(20-pulsewidth/1000);//延时周期内剩余时间
}

