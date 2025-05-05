#ifndef WORLD_SCENE_HPP
#define WORLD_SCENE_HPP

#include <I_scene.hpp>

class WorldScene : public IScene
{
public:
  void dispose () noexcept override;
};

#endif // WORLD_SCENE_HPP
