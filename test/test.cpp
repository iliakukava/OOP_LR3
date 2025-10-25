#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/FigureArray.h"
#include <cmath>

// Вспомогательная функция для сравнения double
bool isClose(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

// ===== ТЕСТЫ ДЛЯ TRIANGLE =====

TEST(TriangleTest, DefaultConstructor) {
    Triangle t;
    EXPECT_TRUE(t.getArea() > 0);  // Площадь больше 0
}

TEST(TriangleTest, AreaCalculation) {
    // Прямоугольный треугольник: (0,0), (3,0), (0,4)
    Triangle t(Point(0, 0), Point(3, 0), Point(0, 4));
    double area = t.getArea();
    EXPECT_TRUE(isClose(area, 6.0));  // Площадь = 0.5 * 3 * 4 = 6
}

TEST(TriangleTest, CenterCalculation) {
    Triangle t(Point(0, 0), Point(3, 0), Point(0, 3));
    Point center = t.getCenter();
    EXPECT_TRUE(isClose(center.x, 1.0));  // (0+3+0)/3 = 1
    EXPECT_TRUE(isClose(center.y, 1.0));  // (0+0+3)/3 = 1
}

TEST(TriangleTest, CopyConstructor) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle t2(t1);
    EXPECT_EQ(t1, t2);
}

TEST(TriangleTest, AssignmentOperator) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle t2;
    t2 = t1;
    EXPECT_EQ(t1, t2);
}

TEST(TriangleTest, DoubleConversion) {
    Triangle t(Point(0, 0), Point(2, 0), Point(0, 2));
    double area = static_cast<double>(t);
    EXPECT_TRUE(isClose(area, 2.0));
}

// ===== ТЕСТЫ ДЛЯ SQUARE =====

TEST(SquareTest, DefaultConstructor) {
    Square s;
    EXPECT_TRUE(s.getArea() > 0);
}

TEST(SquareTest, AreaCalculation) {
    // Квадрат 2x2: (0,0), (2,0), (2,2), (0,2)
    Square s(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    double area = s.getArea();
    EXPECT_TRUE(isClose(area, 4.0));
}

TEST(SquareTest, CenterCalculation) {
    Square s(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Point center = s.getCenter();
    EXPECT_TRUE(isClose(center.x, 1.0));
    EXPECT_TRUE(isClose(center.y, 1.0));
}

TEST(SquareTest, EqualityOperator) {
    Square s1(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    Square s2(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    EXPECT_TRUE(s1 == s2);
}

// ===== ТЕСТЫ ДЛЯ RECTANGLE =====

TEST(RectangleTest, DefaultConstructor) {
    Rectangle r;
    EXPECT_TRUE(r.getArea() > 0);
}

TEST(RectangleTest, AreaCalculation) {
    // Прямоугольник 3x2: (0,0), (3,0), (3,2), (0,2)
    Rectangle r(Point(0, 0), Point(3, 0), Point(3, 2), Point(0, 2));
    double area = r.getArea();
    EXPECT_TRUE(isClose(area, 6.0));
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle r(Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2));
    Point center = r.getCenter();
    EXPECT_TRUE(isClose(center.x, 2.0));
    EXPECT_TRUE(isClose(center.y, 1.0));
}

TEST(RectangleTest, MoveConstructor) {
    Rectangle r1(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1));
    Rectangle r2(std::move(r1));
    EXPECT_TRUE(r2.getArea() > 0);
}

// ===== ТЕСТЫ ДЛЯ FIGUREARRAY =====

TEST(FigureArrayTest, AddAndSize) {
    FigureArray arr;
    EXPECT_EQ(arr.getSize(), 0);
    
    arr.add(new Triangle());
    EXPECT_EQ(arr.getSize(), 1);
    
    arr.add(new Square());
    EXPECT_EQ(arr.getSize(), 2);
}

TEST(FigureArrayTest, GetFigure) {
    FigureArray arr;
    Triangle* t = new Triangle(Point(0, 0), Point(1, 0), Point(0, 1));
    arr.add(t);
    
    Figure* fig = arr.get(0);
    EXPECT_NE(fig, nullptr);
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray arr;
    arr.add(new Triangle());
    arr.add(new Square());
    arr.add(new Rectangle());
    
    EXPECT_EQ(arr.getSize(), 3);
    arr.remove(1);  // Удаляем Square
    EXPECT_EQ(arr.getSize(), 2);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray arr;
    
    // Треугольник площадью 6
    arr.add(new Triangle(Point(0, 0), Point(3, 0), Point(0, 4)));
    
    // Квадрат площадью 4
    arr.add(new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
    
    double total = arr.getTotalArea();
    EXPECT_TRUE(isClose(total, 10.0));
}

TEST(FigureArrayTest, Clear) {
    FigureArray arr;
    arr.add(new Triangle());
    arr.add(new Square());
    
    arr.clear();
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(FigureArrayTest, OutOfRangeException) {
    FigureArray arr;
    arr.add(new Triangle());
    
    EXPECT_THROW(arr.get(5), std::out_of_range);
    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

// ===== ТЕСТЫ ПОЛИМОРФИЗМА =====

TEST(PolymorphismTest, VirtualFunctions) {
    Figure* fig1 = new Triangle(Point(0, 0), Point(2, 0), Point(0, 2));
    Figure* fig2 = new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    
    // Вызываются правильные переопределённые методы
    EXPECT_TRUE(isClose(fig1->getArea(), 2.0));
    EXPECT_TRUE(isClose(fig2->getArea(), 1.0));
    
    delete fig1;
    delete fig2;
}

TEST(PolymorphismTest, Clone) {
    Triangle t(Point(0, 0), Point(1, 0), Point(0, 1));
    Figure* clone = t.clone();
    
    EXPECT_TRUE(isClose(t.getArea(), clone->getArea()));
    
    delete clone;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}