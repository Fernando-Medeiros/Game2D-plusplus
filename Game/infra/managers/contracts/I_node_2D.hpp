#ifndef I_NODE_2D_HPP
#define I_NODE_2D_HPP

#include <E_anchor.hpp>
#include <E_biome.hpp>
#include <E_opacity.hpp>
#include <E_terrain.hpp>
#include <functional>
#include <memory>
#include <vector>

// Forward Declaration
class IBody2D;
class IItem2D;
class IWindow;
class VectorAdapter;

/// O Node2D é a unidade básica de um mapa 2D;
/// Cada node possui um Position2D (X, Y, W, H), bioma, terreno, Entidade 2D,
/// opacidade e objetos (itens, estruturas). O node é responsável por desenhar
/// o terreno, os itens, o corpo e a seleção. Cada node pode ser navegado para
/// direções do entorno. O node possui apenas uma Entidade 2D, mas pode ter
/// vários itens. O node será bloqueado para movimentação caso esteja ocupado
/// por uma Entidade 2D.
class INode2D
{
public:
  using ItemPtr = std::unique_ptr<IItem2D>;
  using BodyPtr = std::unique_ptr<IBody2D>;
  using NodePtr = INode2D *;

  using ItemCollection = std::vector<ItemPtr>;

  using NavigationCallback
      = void (const EAnchor &, const VectorAdapter &, const INode2D &);

  using Navigation = std::unique_ptr<std::function<NavigationCallback> >;

public:
  virtual ~INode2D () noexcept = default;

  [[nodiscard]] virtual bool isEmpty () const noexcept = 0;

  [[nodiscard]] virtual bool hasItems () const noexcept = 0;

  [[nodiscard]] virtual bool isVisible () const noexcept = 0;

  [[nodiscard]] virtual bool isOccupied () const noexcept = 0;

  [[nodiscard]] virtual bool isSelected () const noexcept = 0;

  [[nodiscard]] virtual bool hasBuildings () const noexcept = 0;

  [[nodiscard]] virtual const EBiome &getBiome () const noexcept = 0;

  [[nodiscard]] virtual BodyPtr &getEntity () noexcept = 0;

  [[nodiscard]] virtual const ETerrain &getTerrain () const noexcept = 0;

  [[nodiscard]] virtual const EOpacity &getVisibility () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getPosition () const noexcept = 0;

  [[nodiscard]] virtual const ItemCollection &getItems () const noexcept = 0;

  [[nodiscard]] virtual const ItemCollection &getBuildings () const noexcept
      = 0;

  [[nodiscard]] virtual NodePtr
  navigate (std::vector<EAnchor> anchors) noexcept
      = 0;

  virtual void setBiome (EBiome biome) noexcept = 0;

  virtual void setSelected (bool option) noexcept = 0;

  virtual void setEntity (BodyPtr entity) noexcept = 0;

  virtual void setVisible (EOpacity opacity) noexcept = 0;

  virtual void setTerrain (ETerrain terrain) noexcept = 0;

  virtual void appendItem (ItemPtr &item) noexcept = 0;

  virtual void removeItem (ItemPtr &item) noexcept = 0;

  virtual void appendBuilding (ItemPtr &building) noexcept = 0;

  virtual void removeBuilding (ItemPtr &building) noexcept = 0;

  virtual void render (IWindow &window) noexcept = 0;

  virtual void clear () noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_NODE_2D_HPP
