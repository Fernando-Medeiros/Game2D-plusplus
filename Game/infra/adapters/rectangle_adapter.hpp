#ifndef ADAPTER_RECTANGLE_HPP
#define ADAPTER_RECTANGLE_HPP

#include <I_drawable.hpp>
#include <raylib.h>

class RectangleAdapter : public IDrawable
{
public:
    operator Rectangle() noexcept {
	  Rectangle rectangle{};
	  rectangle.y = _position.vertical();
	  rectangle.x = _position.horizontal();
	  rectangle.width = _size.horizontal();
	  rectangle.height = _size.vertical();
	  return rectangle;
    };
};
#endif