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

