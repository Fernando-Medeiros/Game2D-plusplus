#include <gtest/gtest.h>
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

class ViewportAdapterSpec : public ::testing::Test {
protected:
    adapters::VectorAdapter size{ 50.0f, 50.0f }, center{ 25.0f, 25.0f };

    adapters::ViewportAdapter viewport{ size, center };

    void SetUp() override {}
};

TEST_F(ViewportAdapterSpec, Should_Return_Correct_Initial_Positionx) {
    EXPECT_FLOAT_EQ(viewport.size().verticalPosition(), size.verticalPosition());
    EXPECT_FLOAT_EQ(viewport.size().horizontalPosition(), size.horizontalPosition());
}