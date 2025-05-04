#ifndef CONSTANTS_CORE_HPP
#define CONSTANTS_CORE_HPP

#include <string>

constexpr uint8_t RECT = 64;
constexpr uint8_t MAX_ROW = 255;
constexpr uint8_t MAX_COLUMN = 255;
constexpr uint8_t MAX_FRAME = 188;
constexpr uint8_t MIN_FRAME = 30;
constexpr float WORLD_WIDTH = 255 * 64;
constexpr float WORLD_HEIGHT = 255 * 64;

const inline std::string GAME_TITLE = "Game 2D";
const inline std::string FONTS_PATH = "./resources/fonts/";
const inline std::string MUSICS_PATH = "./resources/musics";
const inline std::string SOUNDS_PATH = "./resources/sounds/";
const inline std::string TEXTURES_PATH = "./resources/textures/";
const inline std::string FONT_EXT = ".ttf";
const inline std::string MUSIC_EXT = ".mp3";
const inline std::string SOUND_EXT = ".ogg";
const inline std::string TEXTURE_EXT = ".png";

#endif // CONSTANTS_CORE_HPP
