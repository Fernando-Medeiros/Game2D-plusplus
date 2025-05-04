#include <gtest/gtest.h>
#include <rect_adapter.hpp>
#include <vector_adapter.hpp>

class RectAdapterTest : public ::testing::Test {
protected:
    VectorAdapter size{ 5, 5 };
    VectorAdapter position{ 10, 20 };
    RectAdapter rect{ position, size };
};

TEST_F(RectAdapterTest, PositionAndSizeAccess) {
    EXPECT_EQ(rect.position(), position);
    EXPECT_EQ(rect.size(), size);
}

TEST_F(RectAdapterTest, CenterCalculation) {
    VectorAdapter expectedCenter{ size };
    expectedCenter /= 2;

    EXPECT_EQ(rect.center(), expectedCenter);
}

TEST_F(RectAdapterTest, ContainsPointInside) {
    VectorAdapter point{ 12, 22 };
    EXPECT_TRUE(rect.contains(point));
}

TEST_F(RectAdapterTest, ContainsPointOnEdge) {
    VectorAdapter point{ 15, 25 };
    EXPECT_TRUE(rect.contains(point));
}

TEST_F(RectAdapterTest, ContainsPointOutside) {
    VectorAdapter point{ 16, 26 };
    EXPECT_FALSE(rect.contains(point));
}
