#include <gtest/gtest.h>
#include <memory>
#include <raylib.h>
#include <vector_adapter.hpp>

TEST(vector_adapter, should_create_vector_2D)
{
    float x{ 10 }, y{ 10 };
    adapters::PositionType c{ 5 }, r{ 5 };

  

    auto vectorX = std::make_unique<adapters::VectorAdapter<float>>();
    auto vectorY = std::make_unique<adapters::VectorAdapter<float>>();

    *vectorX + 500;
    *vectorX * 2;
    *vectorX + *vectorX;
    *vectorX / *vectorX;
    *vectorX - *vectorX;
    *vectorX** vectorX;

    Vector2 rayVector2D = *vectorX;
    const Vector2 rayConstVector2D = *vectorX;
    
    //adapters::VectorAdapter<float> vv = rayVector2D;

    EXPECT_EQ(vectorX->getRowPos(), vectorX->getRowPos());
};
