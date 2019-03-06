//UART send 1~9==>00~180 degree
//舵机1，秒数越小度数越小越向右，117最左，90中，63最右
//舵机2，秒数越小度数越小越向上，63最上，90平，116最下
int servopin1=10;//设置舵机2驱动脚到数字口9
int servopin2=9;//设置舵机2驱动脚到数字口9
int myangle;//定义角度变量，为了增加精度，直接定义微秒数，换算关系500-0度，2500-180度。
double angle;//换算角度的串口可看
int pulsewidth;//定义脉宽变量
int val;//直接定义需要旋转的pwm值，将舵机固定在特殊角度舵机2在1200-1800范围内
void servopulse2(int servopin2,int myangle)//定义一个脉冲函数，用来模拟方式产生PWM值定义舵机2的pwm
{
  pulsewidth=myangle;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin2,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin2,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
void servopulse1(int servopin1,int myangle)//定义一个脉冲函数，用来模拟方式产生PWM值定义舵机1的pwm
{
  pulsewidth=myangle;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin1,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin1,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
void setup()
{
  pinMode(servopin1,OUTPUT);//设定舵机1接口10为输出接口
  pinMode(servopin2,OUTPUT);//设定舵机2接口9为输出接口
  Serial.begin(9600);//设置波特率为9600
  Serial.println("servo=o_seral_simple ready" ) ;
}
void loop(){
//*************////
//下面的路径为先右下角点，然后向左扫完，然后舵机2向上，舵机1再从右向左扫点

//舵机2向下旋转
    val=1800;//1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo2 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse2(servopin2,val);//模拟产生PWM
    }
  delay(2000);//延迟2s
//舵机二向下旋转
////******//////

//舵机一横着自由度，从右向左扫
for(int i=0;i<3;i++)
{
    
    val=1200+300*i;//1200相当于63度，1500相当于90度，1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo1 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse1(servopin1,val);//模拟产生PWM
    }
  delay(10000);//延迟2s
}
//舵机一横着自由度，从右向左扫

//********////

//舵机2中间位置
    val=1500;//1500微妙相当于90度，注意val设置不能小于500不能大于2500
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo2 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse2(servopin2,val);//模拟产生PWM
    }
  delay(2000);//延迟2s
//舵机2中间位置

//********************************//////////

//舵机一横着自由度，从右向左扫
for(int i=0;i<3;i++)
{
    
    val=1200+300*i;//1200相当于63度，1500相当于90度，1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo1 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse1(servopin1,val);//模拟产生PWM
    }
  delay(10000);//延迟2s
}
//舵机一横着自由度，从右向左扫

//////**************************************///////////////////


//舵机2上面位置
      val=1200;//1200微妙相当于63度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo2 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse2(servopin2,val);//模拟产生PWM
    }
  delay(2000);//延迟2s

//舵机2上面位置

////*****************************************////

//舵机一横着自由度，从右向左扫
for(int i=0;i<3;i++)
{
    
    val=1200+300*i;//1200相当于63度，1500相当于90度，1800微妙相当于117度，注意舵机二的舵机不能设置不能大于2000，因为以及快挨近舵机1，同时舵机经计算需要让舵机在正负30度范围内为好因此在1200-1800微妙内合适
    angle=(val-500.0)/2000.0*180.0;//将pwm占空比换算为角度
    Serial.print("moving servo1 to ");//串口中显示
    Serial.print(angle,DEC);//显示角度
    Serial.println();//打印串口
    for(int i=0;i<=50;i++) //产生PWM个数，等效延时以保证能转到响应角度
    {
      servopulse1(servopin1,val);//模拟产生PWM
    }
  delay(10000);//延迟2s
}
//舵机一横着自由度，从右向左扫


//////**************************//////////////


}

