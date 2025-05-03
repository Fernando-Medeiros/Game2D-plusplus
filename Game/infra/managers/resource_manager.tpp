#pragma once
#ifndef RESOURCE_MANAGER_TPP
#define RESOURCE_MANAGER_TPP

#include <E_biome.hpp>
#include <E_music.hpp>
#include <enum_adapter.hpp>
#include <format>
#include <resource_manager.hpp>

template <typename T, IsEnum E>
T &
ResourceManager::load (const E &key)
{
  if constexpr (std::is_same_v<E, EMusic>)
    return loadMusic<T, E> (key);

  else if constexpr (std::is_same_v<E, EFont>)
    return loadFont<T, E> (key);

  else if constexpr (std::is_same_v<E, ESound>)
    return loadSound<T, E> (key);

  else if constexpr (std::is_same_v<E, ETexture>)
    return loadTexture<T, E> (key);

  else
    static_assert ([] { return false; }(), "Unsupported enum type");
};

template <typename T, IsEnum E>
[[nodiscard]] T &
ResourceManager::loadTexture (const E &key) noexcept
{
  if (!_textures.contains (key))
    {
      std::string path
          = std::format ("./resources/textures/{}.png", getEnumName (key));

      _textures.emplace (key, std::make_unique<TextureAdapterResource> (
                                  LoadTexture (path.c_str ())));
    }

  return _textures.at (key);
}

template <typename T, IsEnum E>
[[nodiscard]] T &
ResourceManager::loadFont (const E &key) noexcept
{
  if (!_fonts.contains (key))
    {
      std::string path
          = std::format ("./resources/fonts/{}.ttf", getEnumName (key));

      _fonts.emplace (key, std::make_unique<FontAdapterResource> (
                               LoadFont (path.c_str ())));
    }

  return _fonts.at (key);
}

template <typename T, IsEnum E>
[[nodiscard]] T &
ResourceManager::loadSound (const E &key) noexcept
{
  if (!_sounds.contains (key))
    {
      std::string path
          = std::format ("./resources/sounds/{}.ogg", getEnumName (key));

      _sounds.emplace (key, std::make_unique<SoundAdapterResource> (
                                LoadSound (path.c_str ())));
    }

  return _sounds.at (key);
}

template <typename T, IsEnum E>
[[nodiscard]] T &
ResourceManager::loadMusic (const E &key) noexcept
{
  _musics.clear ();

  if (!_musics.contains (key))
    {
      std::string path
          = std::format ("./resources/musics/{}.mp3", getEnumName (key));

      _musics.emplace (key, std::make_unique<MusicAdapterResource> (
                                LoadMusicStream (path.c_str ())));
    }

  return _musics.at (key);
}
#endif
