#include "viewport_adapter.hpp"
#include "viewport_adapter_api.hpp"

using namespace adapters;

ViewportHandle CreateViewport(Vector size, Vector center) {
    auto* adapter = new ViewportAdapter(
	  VectorAdapter(size.x, size.y),
	  VectorAdapter(center.x, center.y)
    );
    return reinterpret_cast<ViewportHandle>(adapter);
}

void DestroyViewport(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    delete adapter;
}

Vector GetViewportSize(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    const auto& s = adapter->size();
    return Vector{ s.horizontalPosition(), s.verticalPosition() };
}

Vector GetViewportCenter(ViewportHandle handle) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    const auto& c = adapter->center();
    return Vector{ c.horizontalPosition(), c.verticalPosition() };
}

void ZoomViewport(ViewportHandle handle, float scale) {
    auto* adapter = reinterpret_cast<ViewportAdapter*>(handle);
    adapter->zoom(scale);
}