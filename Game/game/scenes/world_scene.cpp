#include <constants_core.hpp>
#include <node_2D.hpp>
#include <world_scene.hpp>

void
WorldScene::initialize () noexcept
{
  _nodes.clear ();
  _nodes.reserve (MAX_ROW);

  for (uint8_t row = 0; row < MAX_ROW; row++)
    {
      std::vector<std::unique_ptr<INode2D> > rowNodes;
      rowNodes.reserve (MAX_ROW);

      for (uint8_t column = 0; column < MAX_COLUMN; column++)
        {
          int posY = row * RECT;
          int posX = column * RECT;
          auto position2D = VectorAdapter (posX, posY, row, column);

          rowNodes.push_back (std::make_unique<Node2D> (position2D));
        }

      _nodes.push_back (std::move (rowNodes));
    }
}

void
WorldScene::dispose () noexcept
{
  _nodes.clear ();
}

void
WorldScene::render (WindowArgs &window) noexcept
{
  window.beginViewport ();

  auto x = window.getCurrentViewport ();

  VectorAdapter maxPosition = x.getTarget () + (x.getSize () / 2);
  VectorAdapter minPosition = x.getTarget () - (x.getSize () / 2);

  for (auto &nodes : _nodes)
    for (auto &node : nodes)
      {
        VectorAdapter pos = node->getPosition ();

        if (pos.horizontal () < minPosition.horizontal ()
            || pos.horizontal () > maxPosition.horizontal ()
            || pos.vertical () < minPosition.vertical ()
            || pos.vertical () > maxPosition.vertical ())
          continue;

        node->render (window);
      }

  window.endViewport ();
}
