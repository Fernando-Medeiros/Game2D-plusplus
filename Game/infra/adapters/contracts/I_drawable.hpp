#ifndef I_DRAWABLE_HPP
#define I_DRAWABLE_HPP

class IDrawable {
  public:
    virtual ~IDrawable () noexcept = default;

    template <typename T>
    [[nodiscard]] const T *
    toSecurePtr () const
    {
      return dynamic_cast<const T *> (this);
    }
};
#endif
