#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include <I_node_2D.hpp>

class Node2D : public INode2D
{
public:
  Node2D ();

public:
  void dispose () noexcept override;
};

#endif // NODE_2D_HPP
