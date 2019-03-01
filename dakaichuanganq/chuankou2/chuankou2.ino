#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//RX=2,TX=3 //自定义软串口
void setup() 
{
//硬件串口波特率
Serial.begin(9600);
//软件串口波特率
//mySerial.begin(9600);//自定义软串口的波特率
//发送传感器测量命令，代码80 06 03 77十六进制，一直测量
//发送传感器测量命令，代码80 06 02 78十六进制，单次测量

Serial.write(0x80); 
Serial.write(0x06);
Serial.write(0x03);
Serial.write(0x77);
//只会设置一次
} 
void loop()
{
//循环代码


if (Serial.available() > 0) {
    delay(100); // 等待数据传完
    int numdata = Serial.available();
    Serial.print("Serial.available = :");
    Serial.println(numdata);
  }
  while(Serial.read()>=0){} //清空串口缓存







//延迟40s
delay(40000);




/*如果硬件串口有数据
if(Serial.available())
{



          //从硬件串口读出一字节，写入软件串口
          //mySerial.write(Serial.read());
}
          如果软件串口有数据
         if(mySerial.available())
        {
         //从软件串口读出一字节，写入硬件串口
         Serial.write(mySerial.read());
        }*/
}
