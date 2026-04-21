#include "SensorModule.h"

SensorModule sensor;

void setup() {
  Serial.begin(115200);
  sensor.init();
}

void loop() {
  IMUData data = sensor.read();

  Serial.print("AX: ");
  Serial.println(data.ax);
  Serial.print("AY: ");
  Serial.println(data.ay);
  Serial.print("AZ: ");
  Serial.println(data.az);
  Serial.print("Temperature: ");
  Serial.println(data.temp);
  Serial.print("Pitch: ");
  Serial.println(data.pitch);
  Serial.print("Roll: ");
  Serial.println(data.roll);
  Serial.print("Yaw: ");
  Serial.println(data.yaw);

  delay(100);
}
