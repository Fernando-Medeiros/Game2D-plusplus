#ifndef ENUM_LOG_LEVEL_H
#define ENUM_LOG_LEVEL_H

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
