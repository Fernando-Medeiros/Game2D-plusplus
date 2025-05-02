#ifndef ADAPTER_TEXT_HPP
#define ADAPTER_TEXT_HPP

#include <I_drawable.hpp>
#include <I_text.hpp>

class TextAdapter : public IText, public IDrawable
{
private:
  EFont _font{ EFont::OpenSansRegular };
  EFontStyle _fontStyle{ EFontStyle::Regular };
  EColor _fontColor{ EColor::White }, _outlineColor{ EColor::White },
      _fillColor{ EColor::CornFlowerBlue };
  VectorAdapter _size, _scale, _center, _position, _outlineSize;
  std::string _text{ "" };
  float _rotation{ 0.0f };
  int _fontSize{ 16 };

public:
  IText &setFontSize (int value) noexcept override;

  IText &setRotation (float value) noexcept override;

  IText &setText (std::string value) noexcept override;

  IText &setStyle (EFontStyle value) noexcept override;

  IText &setFontColor (EColor value) noexcept override;

  IText &setSize (VectorAdapter value) noexcept override;

  IText &setScale (VectorAdapter value) noexcept override;

  IText &setPosition (VectorAdapter value) noexcept override;

  IText &setOutlineSize (VectorAdapter value) noexcept override;

  IText &setOutlineColor (EColor value) noexcept override;

  IText &setFillColor (EColor value) noexcept override;

  [[nodiscard]] EFont &getFont () noexcept override;

  [[nodiscard]] int getFontSize () const noexcept override;

  [[nodiscard]] float getRotation () const noexcept override;

  [[nodiscard]] std::string getText () const noexcept override;

  [[nodiscard]] const EColor &getFontColor () const noexcept override;

  [[nodiscard]] const VectorAdapter &getSize () const noexcept override;

  [[nodiscard]] const VectorAdapter &getScale () const noexcept override;

  [[nodiscard]] const VectorAdapter &getPosition () const noexcept override;

  [[nodiscard]] const VectorAdapter &getOutlineSize () const noexcept override;

  [[nodiscard]] const RectAdapter getRect () const noexcept override;

  [[nodiscard]] const EColor &getOutlineColor () const noexcept override;

  [[nodiscard]] const EColor &getFillColor () const noexcept override;
};
#endif
