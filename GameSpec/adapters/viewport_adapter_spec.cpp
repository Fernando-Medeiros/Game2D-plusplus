#include <gtest/gtest.h>
#include <raylib.h>
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

class ViewportAdapterSpec : public ::testing::Test {
protected:
    VectorAdapter size{ 50, 50 };
    VectorAdapter center{ 25, 25 };

    ViewportAdapter viewport{ size, center };

    void SetUp() override {}
};

TEST_F(ViewportAdapterSpec, Should_Initialize_With_Correct_Size_And_Center) {
    EXPECT_FLOAT_EQ(viewport.size().horizontal(), size.horizontal());
    EXPECT_FLOAT_EQ(viewport.size().vertical(), size.vertical());

    EXPECT_FLOAT_EQ(viewport.center().horizontal(), center.horizontal());
    EXPECT_FLOAT_EQ(viewport.center().vertical(), center.vertical());
}

TEST_F(ViewportAdapterSpec, Should_Allow_Updating_Size) {
    VectorAdapter newSize{ 100, 100 };
    viewport.size(newSize);

    EXPECT_FLOAT_EQ(viewport.size().horizontal(), newSize.horizontal());
    EXPECT_FLOAT_EQ(viewport.size().vertical(), newSize.vertical());
}

TEST_F(ViewportAdapterSpec, Should_Allow_Updating_Center) {
    VectorAdapter newCenter{ 10, 10 };
    viewport.center(newCenter);

    EXPECT_FLOAT_EQ(viewport.center().horizontal(), newCenter.horizontal());
    EXPECT_FLOAT_EQ(viewport.center().vertical(), newCenter.vertical());
}

// TODO
TEST_F(ViewportAdapterSpec, Should_Update_Internal_State_With_Reset) {
}

TEST_F(ViewportAdapterSpec, Should_Convert_To_Camera2D) {
    Camera2D cam = viewport;

    EXPECT_FLOAT_EQ(cam.target.x, center.horizontal());
    EXPECT_FLOAT_EQ(cam.target.y, center.vertical());

    EXPECT_FLOAT_EQ(cam.offset.x, size.horizontal());
    EXPECT_FLOAT_EQ(cam.offset.y, size.vertical());

    EXPECT_FLOAT_EQ(cam.rotation, 0);
    EXPECT_FLOAT_EQ(cam.zoom, 1);
}

TEST_F(ViewportAdapterSpec, Should_Apply_Zoom) {
    viewport.zoom(2);
    Camera2D cam = viewport;
    EXPECT_FLOAT_EQ(cam.zoom, 2);
}
