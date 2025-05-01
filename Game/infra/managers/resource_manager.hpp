#pragma once
#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <E_font.hpp>
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
  using FontCollection
      = std::unordered_map<EFont, std::unique_ptr<FontAdapterResource> >;

  using SoundCollection
      = std::unordered_map<ESound, std::unique_ptr<SoundAdapterResource> >;

  using TextureCollection
      = std::unordered_map<ETexture, std::unique_ptr<TextureAdapterResource> >;

private:
  FontCollection _fonts;
  SoundCollection _sounds;
  TextureCollection _textures;

public:
  void dispose () noexcept;

  template <typename T, typename E>
  requires std::is_enum_v<E> const T &load (const E &key);

private:
  template <typename E>
  requires std::is_enum_v<E> [[nodiscard]] const auto &
  loadTexture (const E &key) noexcept;

  template <typename E>
  requires std::is_enum_v<E> [[nodiscard]] const auto &
  loadFont (const E &key) noexcept;

  template <typename E>
  requires std::is_enum_v<E> [[nodiscard]] const auto &
  loadSound (const E &key) noexcept;

  template <typename E>
  requires std::is_enum_v<E> [[nodiscard]] const auto
  loadMusic (const E &key) noexcept;
};

#include <resource_manager.tpp>

#endif // RESOURCE_MANAGER_HPP
