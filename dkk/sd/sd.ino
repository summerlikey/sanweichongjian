void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //设置波特率为9600，一般是这个波特率
init();
}

void init(){
  Serial.println(80060377);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)//如果串口有数据进入的话
{
int c=Serial.read();//每次读一个字符，是ASCII码的
}
//delay(2000);
}
