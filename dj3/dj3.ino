int servoPin = 9;    //定义舵机接口数字接口7 也就是舵机的橙色信号线。
 
void setup() {
  pinMode(servoPin, OUTPUT); //设定舵机接口为输出接口
  Serial.begin(9600);
}
 void servo(int angle) { //定义一个脉冲函数
  //发送50个脉冲
  for(int i=0;i<330;i++){
    int pulsewidth = (angle * 11) + 500; //将角度转化为500-2480的脉宽值
    digitalWrite(servoPin, HIGH);   //将舵机接口电平至高
    delayMicroseconds(pulsewidth);  //延时脉宽值的微秒数
    digitalWrite(servoPin, LOW);    //将舵机接口电平至低
    delayMicroseconds(20000 - pulsewidth);
  }
  delay(100);
}

void loop() {
  servo(10);
  delay(600);
}
 

