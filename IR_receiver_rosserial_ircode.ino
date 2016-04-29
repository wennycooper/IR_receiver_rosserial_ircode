
#include <ros.h>
#include <geometry_msgs/Vector3.h>

#include <CppList.h>
#include <IRremote.h>

//int RECV_PIN = 2; // 使用數位腳位2接收紅外線訊號
IRrecv irrecv2(2); // 初始化紅外線訊號輸入
IRrecv irrecv3(3); //

decode_results results; // 儲存訊號的結構

unsigned int flag2, flag3;

ros::NodeHandle nh;
geometry_msgs::Vector3 irCode;
ros::Publisher pub("irCode", &irCode);

void setup()
{
  nh.initNode();
  nh.advertise(pub);
  
  Serial.begin(57600);
//  irrecv.blink13(true); // 設為true的話，當收到訊號時，腳位13的LED便會閃爍
  irrecv2.enableIRIn(); // 啟動接收
  irrecv3.enableIRIn();
}

void loop() {
  flag2 = 0; flag3 = 0;
  if (irrecv2.decode(&results)) { // 接收紅外線訊號並解碼
    if (results.value == 0x77E14050) flag2=1;
    irrecv2.resume(); // 準備接收下一個訊號
  }


  if (irrecv3.decode(&results)) { // 接收紅外線訊號並解碼
    if (results.value == 0x77E14050) flag3=1;
    irrecv3.resume(); // 準備接收下一個訊號
  }


/*
  if (flag2 && flag3) {
    Serial.println("Pin2: True, Pin3: True");
  }
  if (flag2 && !flag3) {
    Serial.println("Pin2: True, Pin3: False");
  }
  if (!flag2 && flag3) {
    Serial.println("Pin2: False, Pin3: True");
  }
*/

  irCode.x = flag2;
  irCode.y = flag3;
  pub.publish(&irCode);

  nh.spinOnce();
}
