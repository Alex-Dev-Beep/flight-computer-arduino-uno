struct IMUData {
  float ax, ay, az;
  float gx, gy, gz;
  float temp;
  
  float pitch;
  float roll;
  float yaw;
};

class SensorModule {
public:
  void init();
  IMUData read();

private:
  IMUData data;
};
