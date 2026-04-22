#include "ScreenModule.h"
#include "SensorModule.h"
#include "OLED.h"
#include <stdio.h>

void showDebugInfo(IMUData data) {
  char buffer[32];

  char ax[10], ay[10], az[10];
  char gx[10], gy[10], gz[10];
  char temp[10], pitch[10], roll[10];

  dtostrf(data.ax, 5, 2, ax);
  dtostrf(data.ay, 5, 2, ay);
  dtostrf(data.az, 5, 2, az);

  dtostrf(data.gx, 5, 2, gx);
  dtostrf(data.gy, 5, 2, gy);
  dtostrf(data.gz, 5, 2, gz);

  dtostrf(data.temp, 5, 2, temp);
  dtostrf(data.pitch, 5, 2, pitch);
  dtostrf(data.roll, 5, 2, roll);

  snprintf(buffer, sizeof(buffer), "AX:%s AY:%s", ax, ay);
  oled_printLine(1, buffer);

  snprintf(buffer, sizeof(buffer), "AZ:%s GX:%s", az, gx);
  oled_printLine(2, buffer);

  snprintf(buffer, sizeof(buffer), "GY:%s GZ:%s", gy, gz);
  oled_printLine(3, buffer);

  snprintf(buffer, sizeof(buffer), "Temp:%sC", temp);
  oled_printLine(4, buffer);

  snprintf(buffer, sizeof(buffer), "Pitch:%s", pitch);
  oled_printLine(5, buffer);

  snprintf(buffer, sizeof(buffer), "Roll:%s", roll);
  oled_printLine(6, buffer);
}
