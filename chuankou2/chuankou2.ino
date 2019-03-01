#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//RX=2,TX=3 //自定义软串口
void setup() 
{
//硬件串口波特率
Serial.begin(9600);
//软件串口波特率
mySerial.begin(9600);//自定义软串口的波特率

Serial.write(0x80); 
Serial.write(0x06);
Serial.write(0x03);
Serial.write(0x77);

} 
void loop()
{




//延迟4s
delay(40000);
}
