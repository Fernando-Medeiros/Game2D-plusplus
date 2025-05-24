#ifndef I_STATISTIC_COMPONENT_HPP
#define I_STATISTIC_COMPONENT_HPP

class IBody2D;
class IEventArgs;

class IStatisticComponent
{
public:
  virtual ~IStatisticComponent () noexcept = default;

  [[nodiscard]] virtual IStatisticComponent &
  withEntity (IBody2D &linkedEntity) noexcept
      = 0;

  virtual int getBlock () const noexcept = 0;

  virtual int getDefense () const noexcept = 0;

  virtual int getEvasion () const noexcept = 0;

  virtual float getHealthProgress () const noexcept = 0;

  virtual void receiveDamage (int damage) noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_STATISTIC_COMPONENT_HPP
