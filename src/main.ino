#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Org_01.h>

#include "SensorModule.h"
#include "ScreenModule.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 displayMovementDebug(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

SensorModule sensor;

void setup() {
  Serial.begin(115200);

  // Init screen
  if (!displayMovementDebug.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306-1 allocation failed"));
    for (;;); // Crash
  }

  displayMovementDebug.clearDisplay();
  displayMovementDebug.setTextSize(1.0);
  displayMovementDebug.setTextColor(SSD1306_WHITE);
  displayMovementDebug.setFont(&Org_01);

  sensor.init();
}

void loop() {
  IMUData data = sensor.read();

  displayMovementDebug.clearDisplay();
  displayMovementDebug.setCursor(26, 6);
  displayMovementDebug.print(F("Movement Info"));
  showDebugInfo(displayMovementDebug, data);
  displayMovementDebug.display();

  delay(200);
}
