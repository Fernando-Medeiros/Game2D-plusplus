#include <text_adapter.hpp>

IText &
TextAdapter::setFont (EFont font) noexcept
{
  _font = font;
  return *this;
}

IText &
TextAdapter::setFontSpacing (int value) noexcept
{
  _fontSpacing = value;
  return *this;
}

IText &
TextAdapter::setFontSize (int value) noexcept
{
  _fontSize = value;
  return *this;
}

IText &
TextAdapter::setRotation (float value) noexcept
{
  _rotation = value;
  return *this;
}

IText &
TextAdapter::setText (std::string value) noexcept
{
  _text = value;
  return *this;
}

IText &
TextAdapter::setStyle (EFontStyle value) noexcept
{
  _fontStyle = value;
  return *this;
}

IText &
TextAdapter::setFontColor (EColor value) noexcept
{
  _fontColor = value;
  return *this;
};

IText &
TextAdapter::setSize (VectorAdapter value) noexcept
{
  _size = value;
  return *this;
}

IText &
TextAdapter::setScale (VectorAdapter value) noexcept
{
  _scale = value;
  return *this;
}

IText &
TextAdapter::setPosition (VectorAdapter value) noexcept
{
  _position = value;
  return *this;
}

IText &
TextAdapter::setOutlineSize (VectorAdapter value) noexcept
{
  _outlineSize = value;
  return *this;
}

IText &
TextAdapter::setOutlineColor (EColor value) noexcept
{
  _outlineColor = value;
  return *this;
}

IText &
TextAdapter::setFillColor (EColor value) noexcept
{
  _fillColor = value;
  return *this;
}

int
TextAdapter::getFontSpacing () const noexcept
{
  return _fontSpacing;
}

const EFont &
TextAdapter::getFont () const noexcept
{
  return _font;
}

int
TextAdapter::getFontSize () const noexcept
{
  return _fontSize;
}

float
TextAdapter::getRotation () const noexcept
{
  return _rotation;
}

std::string
TextAdapter::getText () const noexcept
{
  return _text;
}

const EColor &
TextAdapter::getFontColor () const noexcept
{
  return _fontColor;
}

const VectorAdapter &
TextAdapter::getSize () const noexcept
{
  return _size;
}

const VectorAdapter &
TextAdapter::getScale () const noexcept
{
  return _scale;
}

const VectorAdapter &
TextAdapter::getPosition () const noexcept
{
  return _position;
}

const VectorAdapter &
TextAdapter::getOutlineSize () const noexcept
{
  return _outlineSize;
}

const RectAdapter
TextAdapter::getRect () const noexcept
{
  return RectAdapter (_position, _size);
}

const EColor &
TextAdapter::getOutlineColor () const noexcept
{
  return _outlineColor;
}

const EColor &
TextAdapter::getFillColor () const noexcept
{
  return _fillColor;
}
