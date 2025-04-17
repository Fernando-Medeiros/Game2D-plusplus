#ifndef ENUM_FOLDER_H
#define ENUM_FOLDER_H

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
