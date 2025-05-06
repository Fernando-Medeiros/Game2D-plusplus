#ifndef I_HUD_HPP
#define I_HUD_HPP

#include <concepts>
#include <constants_callback.hpp>

class IHud
{
public:
  virtual ~IHud () noexcept = default;

  virtual void initialize () noexcept = 0;

  virtual void dispose () noexcept = 0;

  virtual void render (WindowArgs &window) noexcept = 0;

  template <typename T>
  requires std::derived_from<T, IHud> [[nodiscard]] const T *
  toSecurePtr () const
  {
    return dynamic_cast<const T *> (this);
  }
};

#endif // I_HUD_HPP
