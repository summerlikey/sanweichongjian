 #include <Servo.h>//
Servo myservo;//定义舵机变量名     
     void setup()
     {myservo.attach(9);//定义舵机接
      }
     void loop()
      {
     myservo.write(90);
   }
