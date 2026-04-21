#include "ScreenModule.h"
#include "SensorModule.h"

void showDebugInfo(Adafruit_SSD1306& display, IMUData data) {
  display.setCursor(0, 15);

  display.print(F("AX: "));
  display.print(data.ax);

  display.print(F(" AY: "));
  display.print(data.ay);
  
  display.setCursor(0, 23);

  display.print(F("AZ: "));
  display.print(data.az);

  display.print(F(" GX: "));
  display.print(data.gx);

  display.setCursor(0, 31);
  display.print(F("GY: "));
  display.print(data.gy);

  display.print(F(" GZ: "));
  display.print(data.gz);

  display.setCursor(0, 39);
  display.print(F("Temp: "));
  display.print(data.temp);
  display.print(F("C"));

  display.setCursor(0, 47);
  display.print(F("Pitch: "));
  display.print(data.pitch);

  display.setCursor(0, 55);
  display.print(F("Roll: "));
  display.print(data.roll); 
}
