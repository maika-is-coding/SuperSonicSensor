// 腳位設定
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 8; // 新增 LED 腳位

// 測距相關變數
long duration;
float distance;

// 閾值設定
const float threshold = 15.0; // 小於15公分就亮紅燈

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // 設定 LED 為輸出
  Serial.begin(9600);
}

void loop() {
  // 發出超音波
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 接收回音時間
  duration = pulseIn(echoPin, HIGH);

  // 計算距離（公分），預設聲速340公尺/秒
  distance = duration * 0.034 / 2;


  // 根據距離控制 LED
  if (distance < threshold) {
    digitalWrite(ledPin, HIGH); // 亮燈
  } else {
    digitalWrite(ledPin, LOW);  // 關燈
  }
  delay(500);
}
