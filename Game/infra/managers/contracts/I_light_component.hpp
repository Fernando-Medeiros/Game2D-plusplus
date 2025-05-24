#ifndef I_LIGHT_COMPONENT_HPP
#define I_LIGHT_COMPONENT_HPP

#include <E_opacity.hpp>

class IBody2D;

class ILightComponent
{
public:
  virtual ~ILightComponent () noexcept = default;

  virtual void visibilityTo (IBody2D &entity, EOpacity &opacity) noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_LIGHT_COMPONENT_HPP
