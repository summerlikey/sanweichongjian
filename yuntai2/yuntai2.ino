#include <Servo.h>
Servo myservo;
int pos = 0;
void setup()

{
myservo.attach(9);
myservo.write(90);
}
void loop()
{
       myservo.write(120);
       delay(1000);
       myservo.write(150);
       delay(1000);
}
