#ifndef I_TEXT_HPP
#define I_TEXT_HPP

#include <E_color.hpp>
#include <E_font.hpp>
#include <E_font_style.hpp>
#include <rect_adapter.hpp>
#include <string>
#include <vector_adapter.hpp>

class IText
{
public:
  virtual ~IText () noexcept = default;

  virtual IText &setFontSize (int value) noexcept = 0;

  virtual IText &setFontSpacing (int value) noexcept = 0;

  virtual IText &setRotation (float value) noexcept = 0;

  virtual IText &setFont (EFont font) noexcept = 0;

  virtual IText &setText (std::string value) noexcept = 0;

  virtual IText &setStyle (EFontStyle value) noexcept = 0;

  virtual IText &setFontColor (EColor value) noexcept = 0;

  virtual IText &setSize (VectorAdapter value) noexcept = 0;

  virtual IText &setScale (VectorAdapter value) noexcept = 0;

  virtual IText &setPosition (VectorAdapter value) noexcept = 0;

  virtual IText &setOutlineSize (VectorAdapter value) noexcept = 0;

  virtual IText &setOutlineColor (EColor value) noexcept = 0;

  virtual IText &setFillColor (EColor value) noexcept = 0;

  [[nodiscard]] virtual int getFontSpacing () const noexcept = 0;

  [[nodiscard]] virtual int getFontSize () const noexcept = 0;

  [[nodiscard]] virtual float getRotation () const noexcept = 0;

  [[nodiscard]] virtual std::string getText () const noexcept = 0;

  [[nodiscard]] virtual const EFont &getFont () const noexcept = 0;

  [[nodiscard]] virtual const EColor &getFontColor () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getSize () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getScale () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getPosition () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getOutlineSize () const noexcept
      = 0;

  [[nodiscard]] virtual const RectAdapter getRect () const noexcept = 0;

  [[nodiscard]] virtual const EColor &getOutlineColor () const noexcept = 0;

  [[nodiscard]] virtual const EColor &getFillColor () const noexcept = 0;
};

#endif // I_TEXT_HPP
