#ifndef I_STATISTIC_COMPONENT_HPP
#define I_STATISTIC_COMPONENT_HPP

class IBody2D;
class IEventArgs;

class IStatisticComponent
{
public:
  virtual ~IStatisticComponent () noexcept = default;

  [[nodiscard]] virtual IStatisticComponent &
  WithEntity (IBody2D &linkedEntity) noexcept
      = 0;

  virtual int GetBlock () const noexcept = 0;

  virtual int GetDefense () const noexcept = 0;

  virtual int GetEvasion () const noexcept = 0;

  virtual float GetHealthProgress () const noexcept = 0;

  virtual void ReceiveDamage (int damage) noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_STATISTIC_COMPONENT_HPP
