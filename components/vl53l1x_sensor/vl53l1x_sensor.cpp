
#include "vl53l1x_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace vl53l1x_sensor {

static const char *const TAG = "vl53l1x_sensor";

void VL53L1XSensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up VL53L1X...");
  if (!vl_.init()) {
    ESP_LOGE(TAG, "Failed to initialize VL53L1X sensor");
    this->mark_failed();
    return;
  }
  vl_.setDistanceMode(VL53L1X::Medium);
  vl_.setMeasurementTimingBudget(20000);
  vl_.startContinuous(50);
}

void VL53L1XSensor::update() {
  uint16_t distance = vl_.read();
  if (distance == 0) {
    ESP_LOGW(TAG, "VL53L1X read failed!");
    return;
  }
  publish_state(distance / 10.0f); // см
}

}  // namespace vl53l1x_sensor
}  // namespace esphome
