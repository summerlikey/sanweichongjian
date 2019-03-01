#include <Servo.h>    // 声明调用Servo.h库
Servo myservo1;
Servo myservo2;
int pos = 0;

void setup() {
myservo1.attach(9);
myservo2.attach(10);
Serial.begin(9600);
}
void loop() {  
for(pos = 0; pos < 180; pos += 1){
myservo1.write(pos);
myservo2.write(pos);
delay(45);
}
for(pos = 180; pos>=1; pos-=1) {
myservo1.write(pos);
myservo2.write(pos);
delay(45);
}
}
//进入主函数，有两个for循环，第一段是从0开始，循环到180，每次增加1度。第二个for循环则是从180开始，每次减小1度，一直减到0。
//for循环中又调用了一个Servo库中的函数write(pos)
