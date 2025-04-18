#ifndef ENUM_LOGGER_LEVEL_HPP
#define ENUM_LOGGER_LEVEL_HPP

#include <cstdint>

namespace core::enums {

enum class LoggerLevel : uint8_t {
    None,
    Dialog,
    General,
};
}
#endif
