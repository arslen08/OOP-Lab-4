#include <gtest/gtest.h>
#include <cmath>
#include <sstream>
#include <memory>
#include "../includes/point.h"
#include "../includes/pentagon.h"
#include "../includes/hexagon.h"
#include "../includes/octagon.h"
#include "../includes/array.h"

TEST(PointTest, DefaultConstructor) {
    Point<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), 4.2);
}

TEST(PointTest, SettersAndGetters) {
    Point<float> p;
    p.setX(1.1f);
    p.setY(2.2f);
    EXPECT_FLOAT_EQ(p.getX(), 1.1f);
    EXPECT_FLOAT_EQ(p.getY(), 2.2f);
}

TEST(PointTest, EqualityOperator) {
    Point<int> p1(1, 2);
    Point<int> p2(1, 2);
    Point<int> p3(3, 4);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, ArithmeticOperators) {
    Point<int> p1(1, 2);
    Point<int> p2(3, 4);
    
    Point<int> sum = p1 + p2;
    EXPECT_EQ(sum.getX(), 4);
    EXPECT_EQ(sum.getY(), 6);
    
    Point<int> diff = p2 - p1;
    EXPECT_EQ(diff.getX(), 2);
    EXPECT_EQ(diff.getY(), 2);
    
    Point<int> scaled = p1 * 3;
    EXPECT_EQ(scaled.getX(), 3);
    EXPECT_EQ(scaled.getY(), 6);
}

TEST(PointTest, OutputOperator) {
    Point<int> p(5, 10);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "(5, 10)");
}

TEST(PentagonTest, ConstructorAndGetters) {
    Pentagon<int> pentagon(1, 2, 5);
    Point<int> center = pentagon.getCenter();
    
    EXPECT_EQ(center.getX(), 1);
    EXPECT_EQ(center.getY(), 2);
    EXPECT_EQ(pentagon.getRadius(), 5);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon<double> pentagon(0, 0, 1.0);
    double expected_area = (5.0 / 2.0) * 1.0 * 1.0 * std::sin(2 * M_PI / 5);
    double actual_area = pentagon.area();
    
    EXPECT_NEAR(actual_area, expected_area, 1e-10);
}

TEST(PentagonTest, CopyConstructor) {
    Pentagon<int> pentagon1(1, 2, 5);
    Pentagon<int> pentagon2(pentagon1);
    
    EXPECT_EQ(pentagon1.getCenter(), pentagon2.getCenter());
    EXPECT_EQ(pentagon1.getRadius(), pentagon2.getRadius());
}

TEST(PentagonTest, AssignmentOperator) {
    Pentagon<int> pentagon1(1, 2, 5);
    Pentagon<int> pentagon2(3, 4, 6);
    
    pentagon2 = pentagon1;
    
    EXPECT_EQ(pentagon1.getCenter(), pentagon2.getCenter());
    EXPECT_EQ(pentagon1.getRadius(), pentagon2.getRadius());
}

TEST(PentagonTest, DoubleConversion) {
    Pentagon<double> pentagon(0, 0, 2.0);
    double area = pentagon.area();
    double converted = static_cast<double>(pentagon);
    
    EXPECT_DOUBLE_EQ(area, converted);
}

TEST(PentagonTest, Clone) {
    Pentagon<int> pentagon(1, 2, 5);
    auto clone = pentagon.clone();
    
    EXPECT_NE(dynamic_cast<Pentagon<int>*>(clone.get()), nullptr);
    EXPECT_EQ(pentagon.getCenter(), clone->getCenter());
}

TEST(HexagonTest, ConstructorAndGetters) {
    Hexagon<int> hexagon(3, 4, 6);
    Point<int> center = hexagon.getCenter();
    
    EXPECT_EQ(center.getX(), 3);
    EXPECT_EQ(center.getY(), 4);
    EXPECT_EQ(hexagon.getRadius(), 6);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon<double> hexagon(0, 0, 1.0);
    double expected_area = (3.0 * std::sqrt(3) / 2.0) * 1.0 * 1.0;
    double actual_area = hexagon.area();
    
    EXPECT_NEAR(actual_area, expected_area, 1e-10);
}

TEST(HexagonTest, CopyConstructor) {
    Hexagon<int> hexagon1(1, 2, 5);
    Hexagon<int> hexagon2(hexagon1);
    
    EXPECT_EQ(hexagon1.getCenter(), hexagon2.getCenter());
    EXPECT_EQ(hexagon1.getRadius(), hexagon2.getRadius());
}

TEST(HexagonTest, DoubleConversion) {
    Hexagon<double> hexagon(0, 0, 3.0);
    double area = hexagon.area();
    double converted = static_cast<double>(hexagon);
    
    EXPECT_DOUBLE_EQ(area, converted);
}

TEST(OctagonTest, ConstructorAndGetters) {
    Octagon<int> octagon(5, 6, 7);
    Point<int> center = octagon.getCenter();
    
    EXPECT_EQ(center.getX(), 5);
    EXPECT_EQ(center.getY(), 6);
    EXPECT_EQ(octagon.getRadius(), 7);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon<double> octagon(0, 0, 1.0);
    double expected_area = 2.0 * 1.0 * 1.0 * (1 + std::sqrt(2));
    double actual_area = octagon.area();
    
    EXPECT_NEAR(actual_area, expected_area, 1e-10);
}

TEST(OctagonTest, CopyConstructor) {
    Octagon<int> octagon1(1, 2, 5);
    Octagon<int> octagon2(octagon1);
    
    EXPECT_EQ(octagon1.getCenter(), octagon2.getCenter());
    EXPECT_EQ(octagon1.getRadius(), octagon2.getRadius());
}

TEST(OctagonTest, DoubleConversion) {
    Octagon<double> octagon(0, 0, 4.0);
    double area = octagon.area();
    double converted = static_cast<double>(octagon);
    
    EXPECT_DOUBLE_EQ(area, converted);
}

TEST(ArrayTest, DefaultConstructor) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_GE(array.getCapacity(), 2);
}

TEST(ArrayTest, PushBack) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    auto pentagon = std::make_shared<Pentagon<int>>(0, 0, 5);
    array.push_back(pentagon);
    
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_EQ((*array[0]).getCenter(), pentagon->getCenter());
}

TEST(ArrayTest, MultiplePushBack) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    array.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    array.push_back(std::make_shared<Hexagon<int>>(1, 1, 4));
    array.push_back(std::make_shared<Octagon<int>>(2, 2, 3));
    
    EXPECT_EQ(array.getSize(), 3);
}

TEST(ArrayTest, EraseElement) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    array.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    array.push_back(std::make_shared<Hexagon<int>>(1, 1, 4));
    array.push_back(std::make_shared<Octagon<int>>(2, 2, 3));
    
    EXPECT_EQ(array.getSize(), 3);
    array.erase(1);
    EXPECT_EQ(array.getSize(), 2);
    
    EXPECT_EQ((*array[0]).getCenter(), Point<int>(0, 0));
    EXPECT_EQ((*array[1]).getCenter(), Point<int>(2, 2));
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    array.push_back(std::make_shared<Pentagon<double>>(0, 0, 1.0));
    array.push_back(std::make_shared<Hexagon<double>>(0, 0, 1.0));
    array.push_back(std::make_shared<Octagon<double>>(0, 0, 1.0));
    
    double pentagon_area = (5.0 / 2.0) * 1.0 * 1.0 * std::sin(2 * M_PI / 5);
    double hexagon_area = (3.0 * std::sqrt(3) / 2.0) * 1.0 * 1.0;
    double octagon_area = 2.0 * 1.0 * 1.0 * (1 + std::sqrt(2));
    double expected_total = pentagon_area + hexagon_area + octagon_area;
    
    EXPECT_NEAR(array.totalArea(), expected_total, 1e-10);
}

TEST(ArrayTest, CopyConstructor) {
    Array<std::shared_ptr<Figure<int>>> array1;
    array1.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    
    Array<std::shared_ptr<Figure<int>>> array2(array1);
    
    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_EQ((*array1[0]).getCenter(), (*array2[0]).getCenter());
}

TEST(ArrayTest, AssignmentOperator) {
    Array<std::shared_ptr<Figure<int>>> array1;
    array1.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    
    Array<std::shared_ptr<Figure<int>>> array2;
    array2 = array1;
    
    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_EQ((*array1[0]).getCenter(), (*array2[0]).getCenter());
}

TEST(ArrayTest, MoveConstructor) {
    Array<std::shared_ptr<Figure<int>>> array1;
    array1.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    
    size_t original_size = array1.getSize();
    Array<std::shared_ptr<Figure<int>>> array2(std::move(array1));
    
    EXPECT_EQ(array2.getSize(), original_size);
    EXPECT_EQ(array1.getSize(), 0); 
}

TEST(ArrayTest, MoveAssignmentOperator) {
    Array<std::shared_ptr<Figure<int>>> array1;
    array1.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    
    size_t original_size = array1.getSize();
    Array<std::shared_ptr<Figure<int>>> array2;
    array2 = std::move(array1);
    
    EXPECT_EQ(array2.getSize(), original_size);
    EXPECT_EQ(array1.getSize(), 0);
}

TEST(ArrayTest, ResizeOnPushBack) {
    Array<std::shared_ptr<Figure<int>>> array;
    size_t initial_capacity = array.getCapacity();
    
    for (size_t i = 0; i < initial_capacity + 5; ++i) {
        array.push_back(std::make_shared<Pentagon<int>>(i, i, i));
    }
    
    EXPECT_GT(array.getCapacity(), initial_capacity);
    EXPECT_EQ(array.getSize(), initial_capacity + 5);
}

TEST(ArrayTest, SpecificTypeArray) {
    Array<std::shared_ptr<Hexagon<double>>> hexagonArray;
    
    hexagonArray.push_back(std::make_shared<Hexagon<double>>(0.0, 0.0, 5.5));
    hexagonArray.push_back(std::make_shared<Hexagon<double>>(1.5, 1.5, 3.2));
    
    EXPECT_EQ(hexagonArray.getSize(), 2);
    EXPECT_EQ((*hexagonArray[0]).getCenter(), Point<double>(0.0, 0.0));
    EXPECT_EQ((*hexagonArray[1]).getCenter(), Point<double>(1.5, 1.5));
}

TEST(IntegrationTest, MixedFiguresInArray) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    array.push_back(std::make_shared<Pentagon<double>>(0, 0, 2.0));
    array.push_back(std::make_shared<Hexagon<double>>(1, 1, 1.5));
    array.push_back(std::make_shared<Octagon<double>>(2, 2, 1.0));
    
    EXPECT_EQ(array.getSize(), 3);
    
    EXPECT_EQ((*array[0]).getCenter(), Point<double>(0, 0));
    EXPECT_EQ((*array[1]).getCenter(), Point<double>(1, 1));
    EXPECT_EQ((*array[2]).getCenter(), Point<double>(2, 2));
    
    EXPECT_GT(array.totalArea(), 0);
}

TEST(IntegrationTest, ArrayManipulations) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    array.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    array.push_back(std::make_shared<Hexagon<int>>(1, 1, 4));
    array.push_back(std::make_shared<Octagon<int>>(2, 2, 3));
    
    array.erase(1);
    
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_EQ((*array[0]).getCenter(), Point<int>(0, 0));
    EXPECT_EQ((*array[1]).getCenter(), Point<int>(2, 2));
    
    array.push_back(std::make_shared<Pentagon<int>>(3, 3, 2));
    EXPECT_EQ(array.getSize(), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}