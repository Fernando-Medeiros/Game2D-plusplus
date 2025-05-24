#include <node_2D.hpp>

#include <I_window.hpp>
#include <sprite_adapter.hpp>

Node2D::Node2D (VectorAdapter position) noexcept : _position{ position } {};

bool
Node2D::isEmpty () const noexcept
{
  return _entity == nullptr;
}

bool
Node2D::hasItems () const noexcept
{
  return _items.size () > 0;
}

bool
Node2D::isVisible () const noexcept
{
  return _visibility == EOpacity::Light;
}

bool
Node2D::isOccupied () const noexcept
{
  return _entity != nullptr;
}

bool
Node2D::isSelected () const noexcept
{
  return _selected;
}

bool
Node2D::hasBuildings () const noexcept
{
  return _buildings.size () > 0;
}

const EBiome &
Node2D::getBiome () const noexcept
{
  return _biome;
}

Node2D::BodyPtr &
Node2D::getEntity () noexcept
{
  return _entity;
}

const ETerrain &
Node2D::getTerrain () const noexcept
{
  return _terrain;
}

const EOpacity &
Node2D::getVisibility () const noexcept
{
  return _visibility;
}

const VectorAdapter &
Node2D::getPosition () const noexcept
{
  return _position;
}

const Node2D::ItemCollection &
Node2D::getItems () const noexcept
{
  return _items;
}

const Node2D::ItemCollection &
Node2D::getBuildings () const noexcept
{
  return _buildings;
}

Node2D::NodePtr
Node2D::navigate (std::vector<EAnchor> anchors) noexcept
{
  return this;
}

void
Node2D::setBiome (EBiome biome) noexcept
{
  _biome = biome;
}

void
Node2D::setSelected (bool option) noexcept
{
  _selected = option;
}

void
Node2D::setEntity (Node2D::BodyPtr entity) noexcept
{
  _entity = std::move (entity);
}

void
Node2D::setVisible (EOpacity opacity) noexcept
{
  _visibility = opacity;
}

void
Node2D::setTerrain (ETerrain terrain) noexcept
{
  _terrain = terrain;
}

void
Node2D::appendItem (Node2D::ItemPtr &item) noexcept
{
  _items.push_back (std::move (item));
}

void
Node2D::removeItem (Node2D::ItemPtr &target) noexcept
{
  auto it = std::remove_if (
      _items.begin (), _items.end (),
      [&target] (const Node2D::ItemPtr &item) { return item == target; });

  _items.erase (it, _items.end ());
}

void
Node2D::appendBuilding (Node2D::ItemPtr &building) noexcept
{
  _buildings.push_back (std::move (building));
}

void
Node2D::removeBuilding (Node2D::ItemPtr &target) noexcept
{
  auto it = std::remove_if (
      _buildings.begin (), _buildings.end (),
      [&target] (const Node2D::ItemPtr &item) { return item == target; });

  _buildings.erase (it, _buildings.end ());
}

void
Node2D::render (IWindow &window) noexcept
{
  renderTerrain (window);
  renderBuildings (window);
  renderItems (window);
  renderBody (window);
  renderSelected (window);
}

void
Node2D::clear () noexcept
{
  _entity->dispose ();
  _entity.release ();

  _items.clear ();
  _buildings.clear ();

  setEntity (nullptr);
  setSelected (false);
  setBiome (EBiome::Forest);
  setTerrain (ETerrain::ForestA);
  setVisible (EOpacity::Opaque);
}

void
Node2D::dispose () noexcept
{
  clear ();
  _navigation.release ();
}

/////////////////////////////////////////////////////////////////////////////////////////

void
Node2D::renderTerrain (IWindow &window) noexcept
{
  SpriteAdapter sprite{};
  // sprite.set (getVisibility ());
  sprite.setTexture (castEnum<ETexture> (getTerrain (), ETexture::NONE));

  sprite.setPosition (getPosition ());

  window.render (sprite);
}

void
Node2D::renderBuildings (IWindow &window) noexcept
{
}

void
Node2D::renderItems (IWindow &window) noexcept
{
}

void
Node2D::renderBody (IWindow &window) noexcept
{
}

void
Node2D::renderSelected (IWindow &window) noexcept
{
}
