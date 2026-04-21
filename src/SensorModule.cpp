#define MPU_ADDR 0x68
#define PI 3.14159
#include "SensorModule.h"
#include <Wire.h>
#include <math.h>

void SensorModule::init() {
  Wire.begin();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // power management
  Wire.write(0);    // wake up
  Wire.endTransmission(true);
}

IMUData SensorModule::read() {
  IMUData data;

  // leemos
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // empieza en aceleración x, checar documentación
  Wire.endTransmission(false);
  /* pedimos 14 bytes,
  1 ocupados por aceleración x,
  2 ocupados por aceleración x,  
  3 ocupados por aceleración y,  
  4 ocupados por aceleración y,  
  5 ocupados por aceleración z,  
  6 ocupados por aceleración z,  
  7 ocupados por temperatura,
  8 ocupados por temperatura,  
  9 ocupados por rotación x,  
  10 ocupados por rotación x,  
  11 ocupados por rotación y,  
  12 ocupados por rotación y,  
  13 ocupados por rotación z,  
  14 ocupados por rotación z,  
  */
  Wire.requestFrom(MPU_ADDR, 14, true);

  int16_t ax = Wire.read() << 8 | Wire.read();
  int16_t ay = Wire.read() << 8 | Wire.read();
  int16_t az = Wire.read() << 8 | Wire.read();

  int16_t temp = Wire.read() << 8 | Wire.read();

  int16_t gx = Wire.read() << 8 | Wire.read();
  int16_t gy = Wire.read() << 8 | Wire.read();
  int16_t gz = Wire.read() << 8 | Wire.read();

  // convertir a valores útiles
  data.ax = ax / 16384.0;
  data.ay = ay / 16384.0;
  data.az = az / 16384.0;

  data.gx = gx / 131.0;
  data.gy = gy / 131.0;
  data.gz = gz / 131.0;

  data.temp = (temp / 340.0) + 36.53;

  data.pitch = atan2(data.ay, data.az) * 180 / PI;
  data.roll = atan2(data.ax, data.az) * 180 / PI;
  data.yaw = 0; // TO DO

  return data;
}
