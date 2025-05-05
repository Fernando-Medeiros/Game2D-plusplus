#ifndef I_BODY_2D_HPP
#define I_BODY_2D_HPP

class IBody2D
{
public:
  virtual ~IBody2D () noexcept = default;

  virtual void dispose () noexcept = 0;
};

#endif // I_BODY_2D_HPP
