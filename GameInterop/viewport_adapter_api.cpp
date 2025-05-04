#include "viewport_adapter_api.hpp"
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

ViewportHandle
CreateViewport (Vector target, Vector size)
{
  auto *adapter = new ViewportAdapter (VectorAdapter (size.x, size.y),
                                       VectorAdapter (target.x, target.y));

  return reinterpret_cast<ViewportHandle> (adapter);
}

void DestroyViewport(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    delete adapter;
}

Vector GetViewportSize(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    const auto &s = adapter->getSize ();
    return Vector{ s.horizontal(), s.vertical() };
}

Vector GetViewportCenter(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    const auto &c = adapter->getCenter ();
    return Vector{ c.horizontal(), c.vertical() };
}

void ZoomViewport(ViewportHandle handle, float scale) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    adapter->setZoom (scale);
}
