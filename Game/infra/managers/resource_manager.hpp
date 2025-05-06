#pragma once
#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <E_font.hpp>
#include <E_music.hpp>
#include <E_sound.hpp>
#include <E_texture.hpp>
#include <font_adapter_resource.hpp>
#include <magic_enum/magic_enum.hpp>
#include <memory>
#include <music_adapter_resource.hpp>
#include <sound_adapter_resource.hpp>
#include <texture_adapter_resource.hpp>
#include <unordered_map>

class ResourceManager
{
public:
  using FontResource = std::unique_ptr<FontAdapterResource>;
  using MusicResource = std::shared_ptr<MusicAdapterResource>;
  using SoundResource = std::unique_ptr<SoundAdapterResource>;
  using TextureResource = std::unique_ptr<TextureAdapterResource>;

  using FontCollection = std::unordered_map<EFont, FontResource>;
  using MusicCollection = std::unordered_map<EMusic, MusicResource>;
  using SoundCollection = std::unordered_map<ESound, SoundResource>;
  using TextureCollection = std::unordered_map<ETexture, TextureResource>;

private:
  FontCollection _fonts;
  SoundCollection _sounds;
  MusicCollection _musics;
  TextureCollection _textures;

public:
  void dispose () noexcept;

  template <typename T, IsEnum E> T &load (const E &key);

private:
  template <typename T, IsEnum E>
  [[nodiscard]] T &loadTexture (const E &key) noexcept;

  template <typename T, IsEnum E>
  [[nodiscard]] T &loadFont (const E &key) noexcept;

  template <typename T, IsEnum E>
  [[nodiscard]] T &loadSound (const E &key) noexcept;

  template <typename T, IsEnum E>
  [[nodiscard]] T &loadMusic (const E &key) noexcept;
};

#include <resource_manager.tpp>

#endif // RESOURCE_MANAGER_HPP
