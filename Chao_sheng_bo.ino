int Echo = 13;  // Echo回声脚(P13)
int Trig =12;  //  Trig 触发脚(P12)

int Distance = 0;

void setup() {
     Serial.begin(9600);        // 初始化串口
}
void loop() {
    Distance_test();
    Serial.print("Distance:");      //输出距离（单位：厘米）
    Serial.println(Distance);         //显示距离
    Serial.print("cm");     

}

void Distance_test()   // 量出前方距离 
{
  digitalWrite(Trig, LOW);   // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // 给触发脚高电平10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // 持续给触发脚低电
  float Fdistance = pulseIn(Echo, HIGH);  // 读取高电平时间(单位：微秒)
  Fdistance= Fdistance/58;       //为什么除以58等于厘米，  Y米=（X秒*344）/2
  // X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
  Serial.println(Fdistance);         //显示距离
  Distance = Fdistance;
}  
