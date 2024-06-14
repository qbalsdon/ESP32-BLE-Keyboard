// SETUP: ESP32 board (S3 / C3)
//        USB CDC on Boot: Enabled

#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {

    for (int i = 0; i < 3; i++) {
      Serial.println("    Sending Tab key...");
      bleKeyboard.write(KEY_TAB);
      delay(1000);
    }

    Serial.println("    Sending Volume up media key...");
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);

    delay(1000);

    Serial.println("    Sending Volume down media key...");
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  } else {
    Serial.println("    --> No connection");
  }
  Serial.print("Waiting ");
  for (int i = 0; i < 5; i++) {
    Serial.print(String(5 - i) + " ");
    delay(1000);
  }
  Serial.println("");
}