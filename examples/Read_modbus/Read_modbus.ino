#include <ModbusMaster.h>
#include <Wire.h>
#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();
#define RXD 16
#define TXD 17

ModbusMaster node;

void setup() {

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  Serial1.begin(9600, SERIAL_8N1, RXD, TXD);
  Serial.begin(115200);

}
float humi, temp , CO2;
void loop() {
  humi = Read_sensor(1 , 0);//(ID,ADDRESS)
  delay(200);
  temp = Read_sensor(1 , 1);
  delay(200);
  CO2 = Read_sensor(1 , 5);
  delay(200);
  Serial.print("Temperature : ");
  Serial.print(temp / 10, 1);
  Serial.println("C");

  Serial.print("Humidity : ");
  Serial.print(humi / 10, 1);
  Serial.println("%");

  Serial.print("CO2 : ");
  Serial.print(CO2);
  Serial.println("PPM");

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(45, 20, 2);
  tft.println("TEMPERATURE VALUE: ");
  
  tft.setTextColor(TFT_RED);
  tft.setCursor(70, 40, 2);
  tft.print(temp / 10);

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(45, 60, 2);
  tft.println("HIMIDITY VALUE: ");
  
  tft.setTextColor(TFT_RED);
  tft.setCursor(70, 80, 2);
  tft.print(humi / 10);

   tft.setTextColor(TFT_WHITE);
  tft.setCursor(50, 100, 2);
  tft.println("CO2 VALUE: ");
  
  tft.setTextColor(TFT_RED);
  tft.setCursor(70, 120, 2);
  tft.print(CO2);

}

int Read_sensor(int addr , uint16_t  REG) {
  int j, result;
  node.begin(addr, Serial1);
  result = node.readHoldingRegisters (REG, 2); ///< Modbus function 0x04 Read Input Registers
  //delay(500);
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(0);
    //return i;
  } else {
    //mySerial.print("Connec modbus fail. REG >>> "); mySerial.println(REG, HEX); // Debug
    //delay(1000);
    return 333;
  }
}
