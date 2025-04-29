#ifndef ADAPTER_CONTRACTS_DRAWABLE_HPP
#define ADAPTER_CONTRACTS_DRAWABLE_HPP

#include <E_color.hpp>
#include <E_font.hpp>
#include <E_font_style.hpp>
#include <E_texture.hpp>
#include <rect_adapter.hpp>
#include <string>
#include <vector_adapter.hpp>

class IDrawable {
protected:
    EFont _font{EFont::OpenSansRegular};
    EFontStyle _fontStyle{EFontStyle::Regular};
    ETexture _texture{ ETexture::None };
    EColor _fontColor{ EColor::White }, _outlineColor{ EColor::White },
        _fillColor{ EColor::CornFlowerBlue };
    VectorAdapter _size{}, _scale{}, _center{}, _position{}, _borderSize{};
    std::string _text{ "" };
    float _rotation{0.0f};
    int _fontSize{ 16 };

  public:
    IDrawable() noexcept = default;

    virtual ~IDrawable() noexcept = default;

    virtual IDrawable &
    setText (std::string value) noexcept
    {
      _text = value;
      return *this;
    }

    virtual IDrawable &
    setRotation (float value) noexcept
    {
      _rotation = value;
      return *this;
    }

    virtual IDrawable &
    setSize (VectorAdapter value) noexcept
    {
      _size = value;
      return *this;
    }

    virtual IDrawable &
    setScale (VectorAdapter value) noexcept
    {
      _scale = value;
      return *this;
    }

    virtual IDrawable &
    setPosition (VectorAdapter value) noexcept
    {
      _position = value;
      return *this;
    }

    virtual IDrawable &
    setTexture (ETexture value) noexcept
    {
      _texture = value;
      return *this;
    }

    virtual IDrawable &
    setFontSize (int value) noexcept
    {
      _fontSize = value;
      return *this;
    }

    virtual IDrawable &
    setBorderSize (VectorAdapter value) noexcept
    {
      _borderSize = value;
      return *this;
    }

    virtual IDrawable &
    setStyle (EFontStyle value) noexcept
    {
      _fontStyle = value;
      return *this;
    }

    virtual IDrawable &
    setFontColor (EColor value) noexcept
    {
      _fontColor = value;
      return *this;
    }

    virtual IDrawable &
    setBorderColor (EColor value) noexcept
    {
      _outlineColor = value;
      return *this;
    }

    virtual IDrawable &
    setBackgroundColor (EColor value) noexcept
    {
      _fillColor = value;
      return *this;
    }

    [[nodiscard]] virtual EFont &
    getFont () noexcept
    {
      return _font;
    }

    [[nodiscard]] virtual std::string
    getText () const noexcept
    {
      return _text;
    }

    [[nodiscard]] virtual float
    getRotation () const noexcept
    {
      return _rotation;
    }

    [[nodiscard]] virtual const VectorAdapter &
    getSize () const noexcept
    {
      return _size;
    }

    [[nodiscard]] virtual const VectorAdapter &
    getScale () const noexcept
    {
      return _scale;
    }

    [[nodiscard]] virtual const ETexture &
    getTexture () const noexcept
    {
      return _texture;
    }

    [[nodiscard]] virtual const VectorAdapter &
    getPosition () const noexcept
    {
      return _position;
    }

    [[nodiscard]] virtual int
    getFontSize () const noexcept
    {
      return _fontSize;
    }

    [[nodiscard]] virtual const VectorAdapter &
    getBorderSize () const noexcept
    {
      return _borderSize;
    }

    [[nodiscard]] virtual const RectAdapter getRect() const noexcept
    {
        return RectAdapter(_position, _size);
    }

    [[nodiscard]] virtual const EColor &
    getFontColor () const noexcept
    {
      return _fontColor;
    }

    [[nodiscard]] virtual const EColor &
    getBorderColor () const noexcept
    {
      return _outlineColor;
    }

    [[nodiscard]] virtual const EColor &
    getBackgroundColor () const noexcept
    {
      return _fillColor;
    }
};
#endif
