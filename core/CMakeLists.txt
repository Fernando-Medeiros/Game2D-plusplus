file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/enums/*.h
)

add_library(core INTERFACE)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(core INTERFACE ${CORE_HEADERS})
