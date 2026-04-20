struct IMUData {
  float ax, ay, az;
  float gx, gy, gz;
  float temp;
};

class SensorModule {
public:
  void init();
  IMUData read();

private:
  IMUData data;
};
