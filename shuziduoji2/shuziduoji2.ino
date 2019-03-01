#include <Servo.h> //引入lib
 
Servo myservo;  // 创建一个伺服电机对象
 
char inByte = 0; //串口接收的数据
int angle = 0;  //角度值
String temp = "";//临时字符变量，又或者说是缓存用的吧
 
void setup() 
{
  myservo.attach(9);    //定义舵机的引脚为9，舵机只能是10，或者9引脚
  Serial.begin(9600);  //设置波特率
}
 
 
void loop() 
{
  while (Serial.available() > 0) //判断串口是否有数据
  {
    inByte = Serial.read();//读取数据，串口一次只能读1个字符
    temp += inByte;//把读到的字符存进临时变量里面缓存，
                   //再继续判断串口还有没有数据，知道把所有数据都读取出来
   }
 
   if(temp != "")   //判断临时变量是否为空
   {
    angle = temp.toInt();    //把变量字符串类型转成整型
    Serial.println(angle);  //输出数据到串口上，以便观察
   }
  temp = "";//请看临时变量
  myservo.write(angle);  //控制舵机转动相应的角度。
  delay(100);//延时100毫秒
}

