#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"
#include <VL53L1X.h>

namespace esphome {
namespace vl53l1x_sensor {

class VL53L1XSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  Sensor *distance_sensor = new Sensor();

  VL53L1XSensor() : PollingComponent(1000) {}
  void setup() override;
  void update() override;
};

 protected:
  VL53L1X vl_;
};

}  // namespace vl53l1x_sensor
}  // namespace esphome
