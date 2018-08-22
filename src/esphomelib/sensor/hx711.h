//
//  hx711.h
//  esphomelib
//
//  Created by Otto Winter on 07.08.18.
//  Copyright © 2018 Otto Winter. All rights reserved.
//

#ifndef ESPHOMELIB_SENSOR_HX711_H
#define ESPHOMELIB_SENSOR_HX711_H

#include "esphomelib/sensor/sensor.h"
#include "esphomelib/defines.h"

#ifdef USE_HX711

ESPHOMELIB_NAMESPACE_BEGIN

namespace sensor {

enum HX711Gain {
  HX711_GAIN_128 = 1,
  HX711_GAIN_32 = 2,
  HX711_GAIN_64 = 3,
};

class HX711Sensor : public PollingSensorComponent {
 public:
  HX711Sensor(const std::string &name, GPIOPin *dout, GPIOPin *sck, uint32_t update_interval = 15000);

  void setup() override;
  float get_setup_priority() const override;
  void update() override;

  void set_gain(HX711Gain gain);

  std::string unit_of_measurement() override;
  std::string icon() override;
  int8_t accuracy_decimals() override;

 protected:
  bool read_sensor_(uint32_t *result);

  GPIOPin *dout_pin_;
  GPIOPin *sck_pin_;
  HX711Gain gain_{HX711_GAIN_128};
};

} // namespace sensor

ESPHOMELIB_NAMESPACE_END

#endif //USE_HX711

#endif //ESPHOMELIB_SENSOR_HX711_H