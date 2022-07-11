
#define ON LOW
#define OFF HIGH
#define INPUT1 39
#define INPUT2 35
#define Relay1 13
#define Relay2 15
void setup() {
  Serial.begin(9600);     // กำหนดบอดเรท Serial port สำหรับดูค่าผ่าน Serial monitor;
  
  Serial.println("MCP23xxx Button Test!");


  // ชิพ MCP23017 บนบอร์ด PORT GPA[0,7] ตำแหน่งพิน 0-7 จะใช้เป็น INPUT
  // และ GPB[0,7] ตำแหน่งพิน 8-15 จะใช้เป็น OUTPUT
  
  pinMode(INPUT1, INPUT);                      // กำหนดพิน 0-3 เป็น INPUT (X1-X4)
  pinMode(INPUT2, INPUT);

  
  pinMode(Relay1, OUTPUT);                     // กำหนดพิน 8-11 (รีเลย์ 1-4) เป็น OUTPUT
  pinMode(Relay2, OUTPUT);


  digitalWrite(Relay1, OFF);                  // สั่งค่าเริ่มต้น OUTPUT 8-11 (รีเลย์ 1-4) ให้มีสถานะเป็น HIGH (OFF)
  digitalWrite(Relay2, OFF);


  Serial.println("Looping...");
}

void loop() {
  IN_OUT_CONTROL();                           // เรียกใช้งานฟังก์ชั่น IN_OUT_CONTROL
}


void IN_OUT_CONTROL() {
  if (digitalRead(INPUT1) == LOW) {            // หากมี INPUT X1 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    digitalWrite(Relay1, ON);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) ON
    Serial.println("X1 Active");
  } else {
    digitalWrite(Relay1, OFF);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) OFF
    Serial.println("X1 NOT Active");
  }
  
  if (digitalRead(INPUT2) == LOW) {            // หากมี INPUT X2 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    digitalWrite(Relay2, ON);                  // จะสั่งให้รีเลย์ตัวที่ 2 (RELAY2) ON
    Serial.println("X2 Active");
  } else {
    digitalWrite(Relay2, OFF);                 // จะสั่งให้รีเลย์ตัวที่ 2 (RELAY2) OFF
    Serial.println("X2 NOT Active");
  }
}
