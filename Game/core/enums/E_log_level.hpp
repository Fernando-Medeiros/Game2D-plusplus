#ifndef ENUM_LOG_LEVEL_HPP
#define ENUM_LOG_LEVEL_HPP

#include <cstdint>

namespace core::enums {

enum class LogLevel : uint8_t {
    None,
    Error,
    Info,
    Success,
    Warning,
};
}
#endif
