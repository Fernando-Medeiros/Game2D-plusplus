#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include <I_body_2D.hpp>
#include <I_item_2D.hpp>
#include <I_node_2D.hpp>
#include <vector_adapter.hpp>

class Node2D : public INode2D
{
private:
  bool _selected{ false };
  VectorAdapter _position{};
  EBiome _biome{ EBiome::Forest };
  ETerrain _terrain{ ETerrain::ForestA };
  EOpacity _visibility{ EOpacity::Opaque };
  BodyPtr _entity{ nullptr };
  ItemCollection _items{};
  ItemCollection _buildings{};

public:
  inline static Navigation _navigation;

public:
  Node2D (VectorAdapter position) noexcept;

  bool isEmpty () const noexcept override;

  bool hasItems () const noexcept override;

  bool isVisible () const noexcept override;

  bool isOccupied () const noexcept override;

  bool isSelected () const noexcept override;

  bool hasBuildings () const noexcept override;

  [[nodiscard]] const EBiome &getBiome () const noexcept override;

  [[nodiscard]] BodyPtr &getEntity () noexcept override;

  [[nodiscard]] const ETerrain &getTerrain () const noexcept override;

  [[nodiscard]] const EOpacity &getVisibility () const noexcept override;

  [[nodiscard]] const VectorAdapter &getPosition () const noexcept override;

  [[nodiscard]] const ItemCollection &getItems () const noexcept override;

  [[nodiscard]] const ItemCollection &getBuildings () const noexcept override;

  [[nodiscard]] NodePtr
  navigate (std::vector<EAnchor> anchors) noexcept override;

  void setBiome (EBiome biome) noexcept override;

  void setSelected (bool option) noexcept override;

  void setEntity (BodyPtr entity) noexcept override;

  void setVisible (EOpacity opacity) noexcept override;

  void setTerrain (ETerrain terrain) noexcept override;

  void appendItem (ItemPtr &item) noexcept override;

  void removeItem (ItemPtr &item) noexcept override;

  void appendBuilding (ItemPtr &building) noexcept override;

  void removeBuilding (ItemPtr &building) noexcept override;

  void render (IWindow &window) noexcept override;

  void clear () noexcept override;

  void dispose () noexcept override;

private:
  void renderTerrain (IWindow &window) noexcept;
  void renderBuildings (IWindow &window) noexcept;
  void renderItems (IWindow &window) noexcept;
  void renderBody (IWindow &window) noexcept;
  void renderSelected (IWindow &window) noexcept;
};

#endif // NODE_2D_HPP
