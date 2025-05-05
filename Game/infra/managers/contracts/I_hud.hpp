#ifndef I_HUD_HPP
#define I_HUD_HPP

#include <concepts>

class IHud
{
public:
  virtual ~IHud () noexcept = default;

  virtual void dispose () noexcept = 0;

  template <typename T>
  requires std::derived_from<T, IHud> [[nodiscard]] const T *
  toSecurePtr () const
  {
    return dynamic_cast<const T *> (this);
  }
};

#endif // I_HUD_HPP
