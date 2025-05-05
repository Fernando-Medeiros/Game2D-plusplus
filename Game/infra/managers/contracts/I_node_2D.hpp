#ifndef I_NODE_2D_HPP
#define I_NODE_2D_HPP

class INode2D
{
public:
  virtual ~INode2D () noexcept = default;

  virtual void dispose () noexcept = 0;
};

#endif // I_NODE_2D_HPP
