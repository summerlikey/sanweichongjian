int servopin = 9; // 定义数字接口12连接伺服舵机信号线
int myangle; // 定义角度变量
int pulsewidth; // 定义脉宽变量
int val;
void servopulse(int servopin, int myangle) // 定义一个（伺服）脉冲函数
{
  pulsewidth = (myangle*11)+500; // 将角度转化为500-2480的脉宽值（0.5ms~2.5ms的脉宽）
  digitalWrite(servopin, HIGH); // 将舵机接口电平至高
  delayMicroseconds(pulsewidth); // 延时脉宽值的微妙数
  digitalWrite(servopin,LOW); // 将舵机接口电平至低
  delay(20-pulsewidth/1000); // 至低的时间远长于至高的时间
}
void setup() {
  pinMode(servopin, OUTPUT); // 设定舵机接口为输出接口
  Serial.begin(9600); // 连接到串行端口，波特率为9600
  Serial.println("servo=o_seral_simple ready");
}
// 将0到9的数转化为0到180角度，并让LED闪烁相应数的次数
void loop() {
  val = Serial.read(); // 读取串行端口的值（读取char型数据返回int类型）
  if (val>'0'&&val<='9')
  {
    val = val - '0'; // 将特征量转化为数值变量（）
    val = val*(180/9); //  将数字转化为角度
    Serial.print("moving servo to ");
    Serial.print(val, DEC); // print as an ASCII-encoded decimal
    Serial.println();
    for (int i=0; i<=50; i++) // 给予舵机足够的时间让它转到指定角度
    {
      servopulse(servopin, val); // 引用脉冲函数
    }
  }
}

