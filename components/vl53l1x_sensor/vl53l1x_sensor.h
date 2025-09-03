#pragma once
#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace vl53l1x_sensor {

class VL53L1XSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  VL53L1XSensor() : PollingComponent(1000) {}  // 1s default

  void setup() override {}
  void update() override {}

  float distance = 0.0;
};

}  // namespace vl53l1x_sensor
}  // namespace esphome
