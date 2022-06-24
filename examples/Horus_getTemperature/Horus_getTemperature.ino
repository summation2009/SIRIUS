#include <Horus_ESP32.h>
Horus horus("YOUR WIFI SSID.", "YOUR WIFI PASSWORD", "FIREBASE URL WITH OUT http://", "FIREBASE DATABASE KEY");
void setup() {
  horus.init();
}

void loop() {
  horus.intravel();
  // Serial start Buadrate in 115200 
  Serial.print("Temperature = ");
  Serial.println(horus.getTemperature());
}
