#ifndef FONT_ARGS_HPP
#define FONT_ARGS_HPP

#include <E_font.hpp>
#include <event.hpp>

class FontArgs : public IEventArgs
{
private:
  EFont _font;

public:
  FontArgs (EFont font) noexcept : _font{ font } {};

  [[nodiscard]] const EFont &
  getFont () const noexcept
  {
    return _font;
  }
};
#endif // FONT_ARGS_HPP
