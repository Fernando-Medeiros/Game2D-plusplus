#ifndef VECTOR_ADAPTER_SPEC_HPP
#define VECTOR_ADAPTER_SPEC_HPP

#include <format>
#include <memory>
#include <print>
#include <vector_adapter.hpp>

using namespace std;

void should_create_vector_2D()
{
    string message{""};
    println("INICIO TESTE - VECTOR 2D");

    auto vector2D = make_unique<adapters::VectorAdapter<float>>();

    println("{}", vector2D->toString());
    *vector2D + 500;
    println("{}", vector2D->toString());
    *vector2D * 2;
    println("{}", vector2D->toString());
    *vector2D + *vector2D;
    println("{}", vector2D->toString());
    *vector2D / *vector2D;
    println("{}", vector2D->toString());
    *vector2D - *vector2D;
    println("{}", vector2D->toString());
    *vector2D **vector2D;
    println("{}", vector2D->toString());
    println("{} {} {} {}",
            vector2D->getVerticalPos(),
            vector2D->getHorizontalPos(),
            vector2D->getRowPos(),
            vector2D->getColumnPos());

    Vector2 rayVector2D = *vector2D;

    const Vector2 rayConstVector2D = *vector2D;

    println("To Raylib: X{} Y{}", rayVector2D.x, rayVector2D.y);
    println("To Raylib: X{} Y{}", rayConstVector2D.x, rayConstVector2D.y);
    println("FIM TESTE - VECTOR 2D");
};
#endif // !VECTOR_ADAPTER_SPEC_HPP
