#include <vector_adapter.hpp>

using namespace adapters;

template<VectorType T>
VectorAdapter<T>::VectorAdapter(const Vector2& copy) noexcept
    : X{ copy.x }
    , Y{ copy.y }
    , R{ 0 }
    , C{ 0 }
{
}

template<VectorType T>
VectorAdapter<T>::VectorAdapter(
    T x, T y,
    PositionType row,
    PositionType column) noexcept
    : X{ x }
    , Y{ y }
    , R{ row }
    , C{ column }
{
}