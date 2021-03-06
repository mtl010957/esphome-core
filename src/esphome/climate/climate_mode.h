#ifndef ESPHOME_CORE_CLIMATE_MODE_H
#define ESPHOME_CORE_CLIMATE_MODE_H

#include "esphome/defines.h"

#ifdef USE_CLIMATE

#include <cstdint>

ESPHOME_NAMESPACE_BEGIN

namespace climate {

/// Enum for all modes a climate device can be in.
enum ClimateMode : uint8_t {
  /// The climate device is off (not in auto, heat or cool mode)
  CLIMATE_MODE_OFF = 0,
  /// The climate device is set to automatically change the heating/cooling cycle
  CLIMATE_MODE_AUTO = 1,
  /// The climate device is manually set to cool mode (not in auto mode!)
  CLIMATE_MODE_COOL = 2,
  /// The climate device is manually set to heat mode (not in auto mode!)
  CLIMATE_MODE_HEAT = 3,
};

/// Convert the given ClimateMode to a human-readable string.
const char *climate_mode_to_string(ClimateMode mode);

}  // namespace climate

ESPHOME_NAMESPACE_END

#endif  // USE_CLIMATE

#endif  // ESPHOME_CORE_CLIMATE_MODE_H
