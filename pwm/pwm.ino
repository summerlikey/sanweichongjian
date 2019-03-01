void setup()
{
  pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
  Serial.begin(9600); // 连接到串行端口，波特率为9600
}

void loop()
{
    for(int i=1;i<200;i++)
  {
  digitalWrite(9, HIGH);
  delayMicroseconds(1500); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(9, LOW);
  delayMicroseconds(1000); //修改这里的1000可以调整频率
  }
     for(int i=1;i<20;i++)
  {
  digitalWrite(10, HIGH);
  delayMicroseconds(1500); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(10, LOW);
  delayMicroseconds(1000); //修改这里的1000可以调整频率
delay(20);
  }
  for(int i=1;i<20;i++)
  {
  digitalWrite(10, HIGH);
  delayMicroseconds(600); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(10, LOW);
  delayMicroseconds(1900); //修改这里的1000可以调整频率
delay(20);
  }
}
