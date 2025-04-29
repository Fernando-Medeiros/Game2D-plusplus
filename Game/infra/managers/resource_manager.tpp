#pragma once
#ifndef RESOURCE_MANAGER_TPP
#define RESOURCE_MANAGER_TPP

#include <format>
#include <resource_manager.hpp>

template <typename T, typename E>
requires std::is_enum_v<E> const T &
ResourceManager::load (const E &key)
{
  if constexpr (std::is_same_v<E, EBiome>)
    return loadMusic<E> (key);

  else if constexpr (std::is_same_v<E, EFont>)
    return loadFont<E> (key);

  else if constexpr (std::is_same_v<E, ESound>)
    return loadSound<E> (key);

  else if constexpr (std::is_same_v<E, ETexture>)
    return loadTexture<E> (key);

  else
    static_assert ([] { return false; }(), "Unsupported enum type");
};

template <typename E>
requires std::is_enum_v<E> [[nodiscard]] const auto &
ResourceManager::loadTexture (const E &key) noexcept
{
  if (!_textures.contains (key))
    {
      auto name = magic_enum::enum_name (key);

      std::string path = std::format ("./resources/textures/{}.png", name);

      _textures.emplace (key, std::make_unique<TextureAdapterResource> (
                                  LoadTexture (path.c_str ())));
    }

  return _textures.at (key);
}

template <typename E>
requires std::is_enum_v<E> [[nodiscard]] const auto &
ResourceManager::loadFont (const E &key) noexcept
{
  if (!_fonts.contains (key))
    {
      auto name = magic_enum::enum_name (key);

      std::string path = std::format ("./resources/fonts/{}.ttf", name);

      _fonts.emplace (key,
                      std::make_unique<FontAdapterResource> (LoadFont (path)));
    }

  return _fonts.at (key);
}

template <typename E>
requires std::is_enum_v<E> [[nodiscard]] const auto &
ResourceManager::loadSound (const E &key) noexcept
{
  if (!_sounds.contains (key))
    {
      auto name = magic_enum::enum_name (key);

      std::string path = std::format ("./resources/sounds/{}.ogg", name);

      _sounds.emplace (
          key, std::make_unique<SoundAdapterResource> (LoadSound (path)));
    }

  return _sounds.at (key);
}

template <typename E>
requires std::is_enum_v<E> [[nodiscard]] const auto
ResourceManager::loadMusic (const E &key) noexcept
{
  auto name = magic_enum::enum_name (key);

  std::string path = std::format ("./resources/musics/{}.mp3", name);

  return MusicAdapterResource (LoadMusicStream (path.c_str ()));
}
#endif
