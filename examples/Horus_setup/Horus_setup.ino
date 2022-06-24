#include <Horus_ESP32.h>
Horus horus("YOUR WIFI SSID.", "YOUR WIFI PASSWORD", "FIREBASE URL WITH OUT http://", "FIREBASE DATABASE KEY");
void setup() {
  horus.init();
}

void loop() {
  horus.intravel();
}
