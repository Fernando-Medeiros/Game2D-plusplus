#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include <I_node_2D.hpp>

class Node2D : public INode2D
{
public:
  Node2D ();

public:
  // INode2D interface
public:
  bool IsEmpty () const noexcept override;
  bool HasItems () const noexcept override;
  bool IsVisible () const noexcept override;
  bool IsOccupied () const noexcept override;
  bool IsSelected () const noexcept override;
  bool HasBuildings () const noexcept override;
  EBiome &GetBiome () const noexcept override;
  IBody2D *GetEntity () const noexcept override;
  ETerrain &GetTerrain () const noexcept override;
  EOpacity &GetVisibility () const noexcept override;
  VectorAdapter &GetPosition () const noexcept override;
  std::vector<IItem2D &> GetItems () const noexcept override;
  std::vector<IItem2D &> GetBuildings () const noexcept override;
  INode2D Navigate (std::vector<EAnchor> anchors) noexcept override;
  void SetBiome (EBiome biome) noexcept override;
  void SetSelected (bool option) noexcept override;
  void SetEntity (IBody2D *entity) noexcept override;
  void SetVisible (EOpacity &opacity) noexcept override;
  void SetTerrain (ETerrain &terrain) noexcept override;
  void AppendItem (IItem2D &item) noexcept override;
  void RemoveItem (IItem2D &item) noexcept override;
  void AppendBuilding (IItem2D &building) noexcept override;
  void RemoveBuilding (IItem2D &building) noexcept override;
  void RenderSync (IWindow &window) noexcept override;
  void Clear () noexcept override;
  void Dispose () noexcept override;
};

#endif // NODE_2D_HPP
