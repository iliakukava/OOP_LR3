#include "../include/Rectangle.h"
#include <cmath>
#include <stdexcept>

// Конструктор по умолчанию (прямоугольник 2x1)
Rectangle::Rectangle() : vertices{
    Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1)
} {}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices{p1, p2, p3, p4} {}

Rectangle::Rectangle(const std::array<Point, 4>& points)
    : vertices(points) {}

Rectangle::Rectangle(const Rectangle& other)
    : vertices(other.vertices) {}

// Конструктор перемещения
Rectangle::Rectangle(Rectangle&& other) noexcept
    : vertices(std::move(other.vertices)) {}

// Оператор присваивания (копирование)
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

// Оператор присваивания (перемещение)
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

// Оператор сравнения
bool Rectangle::operator==(const Rectangle& other) const {
    for (size_t i = 0; i < 4; ++i) {
        if (vertices[i] != other.vertices[i]) {
            return false;
        }
    }
    return true;
}

Point Rectangle::getCenter() const {
    double cx = 0, cy = 0;
    for (const auto& v : vertices) {
        cx += v.x;
        cy += v.y;
    }
    return Point(cx / 4.0, cy / 4.0);
}

double Rectangle::getArea() const {
    // Тем же методом, что и у квадрата
    double area = 0;
    for (size_t i = 0; i < 4; ++i) {
        size_t j = (i + 1) % 4;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

Rectangle::operator double() const {
    return getArea();
}


void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: ";
    for (size_t i = 0; i < 4; ++i) {
        os << vertices[i];
        if (i < 3) os << " ";
    }
}

// Чтение прямоугольника из потока
void Rectangle::read(std::istream& is) {
    std::cout << "Введите координаты 4 вершин прямоугольника (x y для каждой):\n";
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

// Клонирование
Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

// Получить вершину по индексу
const Point& Rectangle::getVertex(size_t index) const {
    if (index >= 4) {
        throw std::out_of_range("Rectangle vertex index out of range");
    }
    return vertices[index];
}

// Установить вершину по индексу
void Rectangle::setVertex(size_t index, const Point& p) {
    if (index >= 4) {
        throw std::out_of_range("Rectangle vertex index out of range");
    }
    vertices[index] = p;
}