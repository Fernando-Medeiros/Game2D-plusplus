#ifndef I_NODE_2D_HPP
#define I_NODE_2D_HPP

#include <E_anchor.hpp>
#include <E_biome.hpp>
#include <E_opacity.hpp>
#include <E_terrain.hpp>
#include <vector>

class IBody2D;
class IItem2D;
class IWindow;
class VectorAdapter;

class INode2D
{
public:
  virtual ~INode2D () noexcept = default;

  [[nodiscard]] virtual bool IsEmpty () const noexcept = 0;

  [[nodiscard]] virtual bool HasItems () const noexcept = 0;

  [[nodiscard]] virtual bool IsVisible () const noexcept = 0;

  [[nodiscard]] virtual bool IsOccupied () const noexcept = 0;

  [[nodiscard]] virtual bool IsSelected () const noexcept = 0;

  [[nodiscard]] virtual bool HasBuildings () const noexcept = 0;

  [[nodiscard]] virtual EBiome &GetBiome () const noexcept = 0;

  [[nodiscard]] virtual IBody2D *GetEntity () const noexcept = 0;

  [[nodiscard]] virtual ETerrain &GetTerrain () const noexcept = 0;

  [[nodiscard]] virtual EOpacity &GetVisibility () const noexcept = 0;

  [[nodiscard]] virtual VectorAdapter &GetPosition () const noexcept = 0;

  [[nodiscard]] virtual std::vector<IItem2D &> GetItems () const noexcept = 0;

  [[nodiscard]] virtual std::vector<IItem2D &> GetBuildings () const noexcept
      = 0;

  [[nodiscard]] virtual INode2D
  Navigate (std::vector<EAnchor> anchors) noexcept
      = 0;

  virtual void SetBiome (EBiome biome) noexcept = 0;

  virtual void SetSelected (bool option) noexcept = 0;

  virtual void SetEntity (IBody2D *entity) noexcept = 0;

  virtual void SetVisible (EOpacity &opacity) noexcept = 0;

  virtual void SetTerrain (ETerrain &terrain) noexcept = 0;

  virtual void AppendItem (IItem2D &item) noexcept = 0;

  virtual void RemoveItem (IItem2D &item) noexcept = 0;

  virtual void AppendBuilding (IItem2D &building) noexcept = 0;

  virtual void RemoveBuilding (IItem2D &building) noexcept = 0;

  virtual void RenderSync (IWindow &window) noexcept = 0;

  virtual void Clear () noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_NODE_2D_HPP
