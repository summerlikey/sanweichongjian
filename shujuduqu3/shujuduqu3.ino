
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//RX=2,TX=3 //自定义软串口
//还是利用的01口
String comdata = "";
void setup() 
{
//硬件串口波特率
Serial.begin(9600);
//软件串口波特率
//mySerial.begin(9600);//自定义软串口的波特率
//发送传感器测量命令，代码80 06 03 77十六进制，一直测量
//发送传感器测量命令，代码80 06 02 78十六进制，单次测量
/*
Serial.write(0x80); 
Serial.write(0x06);
Serial.write(0x03);
Serial.write(0x77);
//只会设置一次

*/
} 
void loop()
{
//循环代码

 Serial.println(111111);
delay(1000);
   Serial.write(0x80); 
   Serial.write(0x06);
   Serial.write(0x02);
   Serial.write(0x78);
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
 Serial.println(222222);//传感器两个信号输出一次
delay(1000);
/*
//如果硬件串口有数据
if(Serial.available())
{
          //从硬件串口读出一字节，写入软件串口
          //mySerial.write(Serial.read());
}
      //    如果软件串口有数据
         if(mySerial.available())
        {
         //从软件串口读出一字节，写入硬件串口
         Serial.write(mySerial.read());
        }
        */
}
