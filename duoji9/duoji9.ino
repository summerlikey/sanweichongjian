//UART send 1~9==>00~180 degree
//舵机1，秒数越小度数越小越向右，117最左，90中，63最右
//舵机2，秒数越小度数越小越向上，63最上，90平，116最下
String comdata = "";
#include <SoftwareSerial.h>
int servopin1=10;//设置舵机1驱动脚到数字口9
int servopin2=9;//设置舵机2驱动脚到数字口9
int myangle;//定义角度变量，为了增加精度，直接定义微秒数，换算关系500-0度，2500-180度。
double angle;//换算角度的串口可看
int pulsewidth;//定义脉宽变量
int val1;//直接定义需要旋转的pwm值，将舵机固定在特殊角度舵机2在1200-1800范围内
int val2;//舵机2
void servopulse2(int servopin2,int myangle)//定义一个脉冲函数，用来模拟方式产生PWM值定义舵机2的pwm
{
  pulsewidth=myangle;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin2,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin2,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
void servopulse1(int servopin1,int myangle)//定义一个脉冲函数，用来模拟方式产生PWM值定义舵机1的pwm
{
  pulsewidth=myangle;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin1,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin1,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
void setup()
{
  pinMode(servopin1,OUTPUT);//设定舵机1接口10为输出接口
  pinMode(servopin2,OUTPUT);//设定舵机2接口9为输出接口
  Serial.begin(9600);//设置波特率为9600
  //Serial.println("servo=o_seral_simple ready" ) ;
  //发送传感器测量命令，代码80 06 03 77十六进制，一直测量
//发送传感器测量命令，代码80 06 02 78十六进制，单次测量
}
void loop(){
 delay(10000);//等待10s，东西准备完全
 Serial.println(11111111);//给一个其实标记表明数据开始了
//初始化舵机，将舵机归零，即舵机在中间点处，舵机一1500，舵机二1500
val1=1630;//舵机一归零
val2=1550;//舵机二归零
    angle=(val2-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse2(servopin2,val2);//模拟产生PWM
    }
    angle=(val1-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse1(servopin1,val1);//模拟产生PWM
    }
    delay(5000);//归零完等待5s
    //*****归零
//*************////
//下面的路径为先右下角点，然后向左扫完，然后舵机2向上，舵机1再从右向左扫点
for(int j=0;j<3;j++)
{
//舵机2由下向上
   val2=1700-150*j;//1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val2-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse2(servopin2,val2);//模拟产生PWM
    }
  delay(200);//
//舵机二由下向上旋转
////******//////
//舵机一横着自由度，从右向左扫
for(int i=0;i<3;i++)
{
    
    val1=1480+150*i;//1200相当于63度，1500相当于90度，1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val1-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse1(servopin1,val1);//模拟产生PWM
    }
  delay(100);//延迟2s
  //云台就位，给予传感器延时以便测数据
delay(5000);
//传感器代码

   Serial.println(987);
   delay(1000);
   Serial.write(0x80); 
   Serial.write(0x06);
   Serial.write(0x02);
   Serial.write(0x78);//输入命令
comdata = Serial.readString();
 Serial.println(comdata);
//if(Serial.available()>0){
// delay(100);
//    comdata = Serial.readString();
//   Serial.print("long:");
//    Serial.println(comdata);
//   }
  //  comdata = "";
//延迟1s
 Serial.println(789);//传感器两个信号输出一次
delay(1000);

}
//舵机一横着自由度，从右向左扫


}
//********////
Serial.println(22222222);//给一个结束标记位，表明数据结束了
}

