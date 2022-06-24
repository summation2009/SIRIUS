#include <WiFi.h>
#include <FirebaseESP32.h>
#define WIFI_SSID " Name Wifi "
#define WIFI_PASSWORD " Password Wifi "
#define DATABASE_URL " Firebase URL DATABASE "

FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;
int P[2]={32,25};

void setup()
{
  for (int i = 0; i < 7; i++) {
    pinMode(P[i], OUTPUT);
    digitalWrite(P[i], 1);
  }
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  config.database_url = DATABASE_URL;
  config.signer.tokens.legacy_token = " Firebase Serect ";
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Firebase.setDoubleDigits(5);
}

void getupdate(int GPIO, String LEDpath) {
  if (Firebase.getInt(firebaseData, "test/" + LEDpath)) {
    if (firebaseData.intData() == 1) {
      digitalWrite(GPIO, 0);
    }
    else {
      digitalWrite(GPIO, 1);
    }
  }

}

void loop()
{
  for (int i = 0; i < 2; i++) {
    getupdate(P[i], "relay" + String(i + 1));
  }

}
