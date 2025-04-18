#ifndef ENUM_FOLDER_HPP
#define ENUM_FOLDER_HPP

#include <cstdint>

namespace core::enums {

enum class Folder : uint8_t {
    Logs,
    Worlds,
    Options,
    Regions,
    Characters,
};
}
#endif
