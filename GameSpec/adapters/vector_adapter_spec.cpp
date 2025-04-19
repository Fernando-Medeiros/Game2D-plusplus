#include <gtest/gtest.h>
#include <raylib.h>
#include <vector_adapter.hpp>

using namespace adapters;

class VectorAdapterSpec : public ::testing::Test {
protected:
    position_type row{ 50 }, column{ 100 };

    float horizontal{ 10.0f }, vertical{ 20.0f }, modifier{ 5 };

    VectorAdapter<float> vector{ horizontal, vertical, row, column };

    void SetUp() override {}
};

TEST_F(VectorAdapterSpec, Should_Return_Correct_Initial_Position) {
    EXPECT_EQ(vector.rowPosition(), row);
    EXPECT_EQ(vector.columnPosition(), column);
    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal);
}

TEST_F(VectorAdapterSpec, Should_Add_Scalar_Correctly) {
    vector + modifier;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical + modifier);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal + modifier);
}

TEST_F(VectorAdapterSpec, Should_Multiply_By_Scalar_Correctly) {
    vector* modifier;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical * modifier);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal * modifier);
}

TEST_F(VectorAdapterSpec, Should_Divide_By_Scalar_Correctly) {
    vector / modifier;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical / modifier);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal / modifier);
}

TEST_F(VectorAdapterSpec, Should_Subtract_Scalar_Correctly) {
    vector - modifier;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical - modifier);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal - modifier);
}

TEST_F(VectorAdapterSpec, Should_Subtract_Another_Vector_Correctly) {
    VectorAdapter<float> other(horizontal, vertical);
    vector - other;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), 0.0f);
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), 0.0f);
}

TEST_F(VectorAdapterSpec, Should_Multiply_By_Another_Vector_Correctly) {
    VectorAdapter<float> other(2.0f, 3.0f);
    vector* other;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical * other.verticalPosition());
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal * other.horizontalPosition());
}

TEST_F(VectorAdapterSpec, Should_Divide_By_Another_Vector_Correctly) {
    VectorAdapter<float> other(2.0f, 4.0f);
    vector / other;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical / other.verticalPosition());
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal / other.horizontalPosition());
}

TEST_F(VectorAdapterSpec, Should_Add_Another_Vector_Correctly) {
    VectorAdapter<float> other(horizontal, vertical);
    vector + other;

    EXPECT_FLOAT_EQ(vector.verticalPosition(), vertical + other.verticalPosition());
    EXPECT_FLOAT_EQ(vector.horizontalPosition(), horizontal + other.horizontalPosition());
}

TEST_F(VectorAdapterSpec, Should_Convert_To_Raylib_Vector2) {
    Vector2 rayVec = vector;
    VectorAdapter<float> other(rayVec);

    EXPECT_FLOAT_EQ(rayVec.y, vertical);
    EXPECT_FLOAT_EQ(rayVec.x, horizontal);
    EXPECT_FLOAT_EQ(other.verticalPosition(), rayVec.y);
    EXPECT_FLOAT_EQ(other.horizontalPosition(), rayVec.x);
}

