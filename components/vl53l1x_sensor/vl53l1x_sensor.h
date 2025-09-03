#pragma once
#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"
#include "esphome/components/sensor/sensor.h"
#include <VL53L1X.h>

namespace esphome {
namespace vl53l1x_sensor {

// обов’язково: наслідувати PollingComponent + i2c::I2CDevice
class VL53L1XSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  VL53L1XSensor() : PollingComponent(1000) {}

  void setup() override;
  void update() override;

  sensor::Sensor *distance_sensor = new sensor::Sensor();

 protected:
  VL53L1X vl_;
};

}  // namespace vl53l1x_sensor
}  // namespace esphome
