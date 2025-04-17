#include <vector_adapter.h>

using namespace adapters;

template<VectorType T>
VectorAdapter<T>::VectorAdapter(const Vector2 &copy) noexcept
    : X{copy.x}
    , Y{copy.y}
    , R{0}
    , C{0}
{}

template<VectorType T>
VectorAdapter<T>::VectorAdapter(const T &x,
                                const T &y,
                                const PositionType &row,
                                const PositionType &column) noexcept
    : X{x}
    , Y{y}
    , R{row}
    , C{column}
{}
