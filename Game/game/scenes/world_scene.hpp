#ifndef WORLD_SCENE_HPP
#define WORLD_SCENE_HPP

#include <I_scene.hpp>
#include <node_2D.hpp>
#include <text_adapter.hpp>

class WorldScene : public IScene
{
private:
  std::vector<std::vector<std::unique_ptr<INode2D> > > _nodes;

public:
  void initialize () noexcept override;

  void dispose () noexcept override;

  void render (WindowArgs &window) noexcept override;
};

#endif // WORLD_SCENE_HPP
