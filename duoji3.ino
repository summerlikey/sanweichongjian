#include <Servo.h>
Servo myservo1;//创建伺服器对象
Servo myservo2;//创建伺服器对象
int seroverdown = 9; //定义舵机信号线接口
int seroverup = 10; //定义舵机信号线接口
int psx = 1;//定义摇杆信号线接口
int psy = 2;//定义摇杆信号线接口
int valx;//定义变量，从摇杆接口读取值（0-1023，不过一般取不到，大概在90-900多左右）
int valy;//定义变量，从摇杆接口读取值（0-1023，不过一般取不到，大概在90-900多左右）

void setup()
{
  Serial.begin(9600);
  pinMode(psx, OUTPUT); 
  pinMode(psy, OUTPUT);
  myservo1.attach(9);
  myservo2.attach(10);
}

void loop()
{
  valx = analogRead(psx);
  valy = analogRead(psy);
  valx = map(valx,0,1023,0,179);
  valy = map(valy,0,1023,0,179);
  Serial.println(valx, DEC);
  Serial.println(valy, DEC);
    
  myservo2.write(179-valx);
  myservo1.write(179-valy);//根据实际情况，测试摇杆转动方法和舵机方向一致,or myservo.write(val);
  delay(15);
}
