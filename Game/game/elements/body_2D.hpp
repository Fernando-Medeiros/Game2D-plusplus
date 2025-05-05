#ifndef BODY_2D_HPP
#define BODY_2D_HPP

#include <I_body_2D.hpp>

class Body2D : public IBody2D
{
public:
  Body2D ();

public:
  void dispose () noexcept override;
};

#endif // BODY_2D_HPP
