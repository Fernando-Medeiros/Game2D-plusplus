#ifndef I_SCENE_HPP
#define I_SCENE_HPP

#include <concepts>

class IScene
{
public:
  virtual ~IScene () noexcept = default;

  virtual void dispose () noexcept = 0;

  template <typename T>
  requires std::derived_from<T, IScene> [[nodiscard]] const T *
  toSecurePtr () const
  {
    return dynamic_cast<const T *> (this);
  }
};

#endif // I_SCENE_HPP
