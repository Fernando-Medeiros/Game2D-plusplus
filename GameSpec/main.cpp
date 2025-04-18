#include <format>
#include <iostream>
#include <memory>
#include <vector_adapter.h>

using namespace std;

void output(auto &args)
{
    cout << format("{0}", args) << endl;
}

void should_create_vector_2D()
{
    string message{""};
    output("INICIO TESTE - VECTOR 2D");

    auto vector2D = make_unique<adapters::VectorAdapter<float>>();

    output(vector2D->toString());
    *vector2D + 500;
    output(vector2D->toString());
    *vector2D * 2;
    output(vector2D->toString());
    *vector2D + *vector2D;
    output(vector2D->toString());
    *vector2D / *vector2D;
    output(vector2D->toString());
    *vector2D - *vector2D;
    output(vector2D->toString());
    *vector2D **vector2D;
    output(vector2D->toString());
    output(message = format("{0} {1} {2} {3}",
                            vector2D->getVerticalPos(),
                            vector2D->getHorizontalPos(),
                            vector2D->getRowPos(),
                            vector2D->getColumnPos()));

    Vector2 rayVector2D = *vector2D;

    const Vector2 rayConstVector2D = *vector2D;

    output(message = format("To Raylib: X{0} Y{1}", rayVector2D.x, rayVector2D.y));
    output(message = format("To Raylib: X{0} Y{1}", rayConstVector2D.x, rayConstVector2D.y));
    output("FIM TESTE - VECTOR 2D");
}

int main()
{
    should_create_vector_2D();

    return 0;
}
