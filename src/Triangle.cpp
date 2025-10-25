#include "../include/Triangle.h"
#include <cmath>
#include <stdexcept>

Triangle::Triangle() : vertices{Point(0, 0), Point(1, 0), Point(0.5, 0.866)} {
    // равносторонний треугольник со стороной 1
}
// Конструктор с тремя точками
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) 
    : vertices{p1, p2, p3} {}

// Конструктор с массивом точек
Triangle::Triangle(const std::array<Point, 3>& points) 
    : vertices(points) {}

// Конструктор копирования
Triangle::Triangle(const Triangle& other) 
    : vertices(other.vertices) {}

// Конструктор перемещения
Triangle::Triangle(Triangle&& other) noexcept 
    : vertices(std::move(other.vertices)) {}

// Оператор присваивания (копирование)
Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}
// Оператор присваивания (перемещение)
Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

// Оператор сравнения
bool Triangle::operator==(const Triangle& other) const {
    for (size_t i = 0; i < 3; ++i) {
        if (vertices[i] != other.vertices[i]) {
            return false;
        }
    }
    return true;
}

// Вычисление геометрического центра (центроид)
Point Triangle::getCenter() const {
    double cx = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
    double cy = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;
    return Point(cx, cy);
}

// Вычисление площади треугольника по формуле Герона
double Triangle::getArea() const {
    // Формула: S = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
    double x1 = vertices[0].x, y1 = vertices[0].y;
    double x2 = vertices[1].x, y2 = vertices[1].y;
    double x3 = vertices[2].x, y3 = vertices[2].y;
    
    double area = 0.5 * std::abs(
        x1 * (y2 - y3) + 
        x2 * (y3 - y1) + 
        x3 * (y1 - y2)
    );
    
    return area;
}

// Оператор приведения к double
Triangle::operator double() const {
    return getArea();
}

// Вывод информации о треугольнике
void Triangle::print(std::ostream& os) const {
    os << "Triangle: ";
    for (size_t i = 0; i < 3; ++i) {
        os << vertices[i];
        if (i < 2) os << " ";
    }
}

// Чтение треугольника из потока
void Triangle::read(std::istream& is) {
    std::cout << "Введите координаты 3 вершин треугольника (x y для каждой):\n";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "Вершина " << (i + 1) << ": ";
        is >> vertices[i];
    }
}

// Клонирование (создание копии через указатель)
Figure* Triangle::clone() const {
    return new Triangle(*this);
}

// Получить вершину по индексу
const Point& Triangle::getVertex(size_t index) const {
    if (index >= 3) {
        throw std::out_of_range("Triangle vertex index out of range");
    }
    return vertices[index];
}

// Установить вершину по индексу
void Triangle::setVertex(size_t index, const Point& p) {
    if (index >= 3) {
        throw std::out_of_range("Triangle vertex index out of range");
    }
    vertices[index] = p;
}