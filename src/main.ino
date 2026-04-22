#include <Wire.h>
#include <avr/pgmspace.h>

#include "SensorModule.h"
#include "ScreenModule.h"
#include "OLED.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

SensorModule sensor;

void setup() {
  Serial.begin(115200);

  oled_init();

  sensor.init();
}

void loop() {
  IMUData data = sensor.read();

  showDebugInfo(data);

  delay(200);
}
