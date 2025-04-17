#ifndef ENUM_LOGGER_LEVEL_H
#define ENUM_LOGGER_LEVEL_H

#include <cstdint>

namespace core::enums {

enum class LoggerLevel : uint8_t {
    None,
    Dialog,
    General,
};
}
#endif
