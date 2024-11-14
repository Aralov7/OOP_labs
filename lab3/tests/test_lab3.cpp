#include <gtest/gtest.h>
#include "../include/Figure.h"

using namespace std;

TEST(TriangleTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {0, 3}, {3, 0}};
    Triangle triangle(vertices);
    double area = static_cast<double>(triangle);
    EXPECT_DOUBLE_EQ(area, 4.5);
}

TEST(TriangleTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {-2, -2}, {0, 2}, {2, -2}};
    Triangle triangle(vertices);
    auto center = triangle.Center();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0.6666666666666666);
}

TEST(SquareTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square square(vertices);
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 4.0);
}

TEST(SquareTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square square(vertices);
    auto center = square.Center();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(RectangleTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        {-2, -1}, {-2, 1}, {2, 1}, {2, -1}};
    Rectangle rect(vertices);
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 8.0);
}

TEST(RectangleTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {-2, -1}, {-2, 1}, {2, 1}, {2, -1}};
    Rectangle rect(vertices);
    auto center = rect.Center();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
}

TEST(FigureTest, ComparisonTest)
{
    vector<pair<double, double>> vertices1 = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    vector<pair<double, double>> vertices2 = vertices1;
    Square square1(vertices1);
    Square square2(vertices2);
    EXPECT_TRUE(square1 == square2);
}

TEST(FigureTest, CopyAssignmentTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square square1(vertices);
    Square square2;
    square2 = square1;
    EXPECT_TRUE(square1 == square2);
}

TEST(FigureTest, MoveAssignmentTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square square1(vertices);
    Square square2;
    square2 = move(square1);
    EXPECT_TRUE(square2 == Square(vertices));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}