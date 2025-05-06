#ifndef MAIN_SCENE_HPP
#define MAIN_SCENE_HPP

#include <I_scene.hpp>

class MainScene : public IScene
{
public:
  void initialize () noexcept override;

  void dispose () noexcept override;

  void render (WindowArgs &window) noexcept override;
};

#endif // MAIN_SCENE_HPP
