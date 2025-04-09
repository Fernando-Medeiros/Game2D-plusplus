#include "vector_adapter.h"

template<adapters::VectorType T>
adapters::VectorAdapter<T>::VectorAdapter(const Vector2 &copy)
    : X{copy.x}
    , Y{copy.y}
    , R{0}
    , C{0}
{}

template<adapters::VectorType T>
adapters::VectorAdapter<T>::VectorAdapter(const VectorAdapter &copy)
    : X{copy.X}
    , Y{copy.Y}
    , R{copy.R}
    , C{copy.C}
{}

template<adapters::VectorType T>
adapters::VectorAdapter<T>::VectorAdapter(const std::tuple<T, T> &copy)
    : X{copy[0]}
    , Y{copy[1]}
    , R{0}
    , C{0}
{}

template<adapters::VectorType T>
adapters::VectorAdapter<T>::VectorAdapter(T &x, T &y, uint8_t &row, uint8_t &column)
    : X{x}
    , Y{y}
    , R{row}
    , C{column}
{}
