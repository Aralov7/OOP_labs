#include <gtest/gtest.h>
#include <iostream>
#include "../include/rectangle.h"
#include "../include/square.h"
#include "../include/triangle.h"
#include "../include/array.h"

TEST(RectangleTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    Rectangle<int> rect(vertices);
    double area = rect;
    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(RectangleTest, CenterTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    Rectangle<int> rect(vertices);
    auto center = rect.Center();
    EXPECT_DOUBLE_EQ(center->x, 2.0);
    EXPECT_DOUBLE_EQ(center->y, 3.0);
}

TEST(SquareTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<int> square(vertices);
    double area = square;
    EXPECT_DOUBLE_EQ(area, 4.0);
}

TEST(SquareTest, CenterTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<int> square(vertices);
    auto center = square.Center();
    EXPECT_DOUBLE_EQ(center->x, 1.0);
    EXPECT_DOUBLE_EQ(center->y, 1.0);
}

TEST(TriangleTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, 0}, {1, 2}};
    Triangle<int> triang(vertices);
    double area = triang;
    EXPECT_DOUBLE_EQ(area, 2.0);
}

TEST(TriangleTest, CenterTest)
{
    std::vector<Point<double>> vertices = {
        {0, 0}, {1, 3}, {2, 0} };
    Triangle<double> triang(vertices);
    auto center = triang.Center();
    EXPECT_DOUBLE_EQ(center->x, 1);
    EXPECT_DOUBLE_EQ(center->y, 1);
}

TEST(FigureTest, ComparisonTest)
{
    std::vector<Point<int>> vertices1 = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    Rectangle<int> rect1(vertices1);

    std::vector<Point<int>> vertices2 = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    Rectangle<int> rect2(vertices2);

    EXPECT_TRUE(rect1 == rect2);

    std::vector<Point<int>> vertices3 = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<int> square(vertices3);

    EXPECT_FALSE(rect1 == square);
}

TEST(ArrayTest, PushBackAndAccess)
{
    Array<Figure<int>> figures;
    std::vector<Point<int>> vertices = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    auto rect = make_shared<Rectangle<int>>(vertices);
    figures.push_back(rect);
    EXPECT_EQ(figures.get_size(), 1);
    double area = *figures[0];
    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(ArrayTest, RemoveAt)
{
    Array<Figure<int>> figures;
    std::vector<Point<int>> vertices1 = {
        {0, 0}, {4, 0}, {4, 6}, {0, 6}};
    auto rect1 = make_shared<Rectangle<int>>(vertices1);

    std::vector<Point<int>> vertices2 = {
        {0, 0}, {2, 0}, {2, 3}, {0, 3}};
    auto rect2 = make_shared<Rectangle<int>>(vertices2);

    figures.push_back(rect1);
    figures.push_back(rect2);

    figures.remove_at(0);
    EXPECT_EQ(figures.get_size(), 1);
    double area = *figures[0];
    EXPECT_DOUBLE_EQ(area, 6.0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}