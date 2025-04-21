#include <gtest/gtest.h>
#include <raylib.h>
#include <vector_adapter.hpp>

class VectorAdapterSpec : public ::testing::Test {
protected:
    Position row{ 50 }, column{ 100 };

    Coords horizontal{ 10 }, vertical{ 20 }, modifier{ 5 };

    VectorAdapter vector{ horizontal, vertical, row, column };

    void SetUp() override {}
};

TEST_F(VectorAdapterSpec, Should_Return_Correct_Initial_Position) {
    EXPECT_EQ(vector.rowPosition(), row);
    EXPECT_EQ(vector.columnPosition(), column);
    EXPECT_EQ(vector.vertical(), vertical);
    EXPECT_EQ(vector.horizontal(), horizontal);
}

TEST_F(VectorAdapterSpec, Should_Add_Scalar_Correctly) {
    vector + modifier;

    EXPECT_EQ(vector.vertical(), vertical + modifier);
    EXPECT_EQ(vector.horizontal(), horizontal + modifier);
}

TEST_F(VectorAdapterSpec, Should_Multiply_By_Scalar_Correctly) {
    vector* modifier;

    EXPECT_EQ(vector.vertical(), vertical * modifier);
    EXPECT_EQ(vector.horizontal(), horizontal * modifier);
}

TEST_F(VectorAdapterSpec, Should_Divide_By_Scalar_Correctly) {
    vector / modifier;

    EXPECT_EQ(vector.vertical(), vertical / modifier);
    EXPECT_EQ(vector.horizontal(), horizontal / modifier);
}

TEST_F(VectorAdapterSpec, Should_Subtract_Scalar_Correctly) {
    vector - modifier;

    EXPECT_EQ(vector.vertical(), vertical - modifier);
    EXPECT_EQ(vector.horizontal(), horizontal - modifier);
}

TEST_F(VectorAdapterSpec, Should_Subtract_Another_Vector_Correctly) {
    VectorAdapter other(horizontal, vertical);
    vector - other;

    EXPECT_EQ(vector.vertical(), 0);
    EXPECT_EQ(vector.horizontal(), 0);
}

TEST_F(VectorAdapterSpec, Should_Multiply_By_Another_Vector_Correctly) {
    VectorAdapter other(2, 3);
    vector* other;

    EXPECT_EQ(vector.vertical(), vertical * other.vertical());
    EXPECT_EQ(vector.horizontal(), horizontal * other.horizontal());
}

TEST_F(VectorAdapterSpec, Should_Divide_By_Another_Vector_Correctly) {
    VectorAdapter other(2, 4);
    vector / other;

    EXPECT_EQ(vector.vertical(), vertical / other.vertical());
    EXPECT_EQ(vector.horizontal(), horizontal / other.horizontal());
}

TEST_F(VectorAdapterSpec, Should_Add_Another_Vector_Correctly) {
    VectorAdapter other(horizontal, vertical);
    vector + other;

    EXPECT_EQ(vector.vertical(), vertical + other.vertical());
    EXPECT_EQ(vector.horizontal(), horizontal + other.horizontal());
}

TEST_F(VectorAdapterSpec, Should_Convert_To_Raylib_Vector2) {
    Vector2 rayVec = vector;
    VectorAdapter other(rayVec);

    EXPECT_EQ(rayVec.y, vertical);
    EXPECT_EQ(rayVec.x, horizontal);
    EXPECT_EQ(other.vertical(), rayVec.y);
    EXPECT_EQ(other.horizontal(), rayVec.x);
}

