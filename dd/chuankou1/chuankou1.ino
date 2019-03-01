

void setup() {
  // 初始化串口参数
  Serial.begin(9600); 
  Serial.print(80,HEX);
  Serial.print(06,HEX);
  Serial.print(03,HEX);
  Serial.print(77,HEX);
}

void loop() {

  Serial.print("1.www.doflye.net\n" );                       
       
  Serial.print("2.thanks for using mcu-box\n");      


  // 等待2s进行下一个循环
  // 取保能稳定读取下一次数值
  delay(2000);                     
}



