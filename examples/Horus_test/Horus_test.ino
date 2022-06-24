#include <Horus_ESP32.h>
Horus horus();
void setup() {
  horus.init();
}

void loop() {
  horus.intravel();
  Serial.print("Temperature = ");
  Serial.println(horus.getTemperature());

  Serial.print("humidity = ");
  Serial.println(horus.getHumidity());
}
