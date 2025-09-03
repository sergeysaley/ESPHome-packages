import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import CONF_ID, DEVICE_CLASS_DISTANCE, STATE_CLASS_MEASUREMENT

DEPENDENCIES = ["i2c"]

vl53l1x_ns = cg.esphome_ns.namespace("vl53l1x_sensor")
VL53L1XSensor = vl53l1x_ns.class_("VL53L1XSensor", cg.PollingComponent, i2c.I2CDevice)

CONFIG_SCHEMA = (
    sensor.sensor_schema(
        unit_of_measurement="cm",
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_DISTANCE,
        state_class=STATE_CLASS_MEASUREMENT,
    )
    .extend(cv.polling_component_schema("1s"))
    .extend(i2c.i2c_device_schema(0x29))
)

async def to_code(config):
    # створюємо C++ об’єкт
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)

    # створюємо Sensor об’єкт у Python
    sens = sensor.new_sensor(config)
    var.distance_sensor = sens
    await sensor.register_sensor(sens, config)
