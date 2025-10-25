#include "../include/Square.h"
#include <cmath>
#include <stdexcept>

//по умолчанию квадрат 1x1 в начале координат
Square::Square() : vertices{
    Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)
} {}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices{p1, p2, p3, p4} {}

Square::Square(const std::array<Point, 4>& points)
    : vertices(points) {}

// Конструктор копирования
Square::Square(const Square& other)
    : vertices(other.vertices) {}

// Конструктор перемещения
Square::Square(Square&& other) noexcept
    : vertices(std::move(other.vertices)) {}

// Оператор присваивания (копирование)
Square& Square::operator=(const Square& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

// Оператор присваивания (перемещение)
Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    for (size_t i = 0; i < 4; ++i) {
        if (vertices[i] != other.vertices[i]) {
            return false;
        }
    }
    return true;
}

Point Square::getCenter() const {
    double cx = 0, cy = 0;
    for (const auto& v : vertices) {
        cx += v.x;
        cy += v.y;
    }
    return Point(cx / 4.0, cy / 4.0);
}

double Square::getArea() const {
    // Площадь через формулу Гаусса
    // S = 0.5 × |Σ(xi × yi+1 - xi+1 × yi)|
    double area = 0;
    for (size_t i = 0; i < 4; ++i) {
        size_t next = (i + 1) % 4;
        area += vertices[i].x * vertices[next].y;
        area -= vertices[next].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

Square::operator double() const {
    return getArea();
}

void Square::print(std::ostream& os) const {
    os << "Square: ";
    for (size_t i = 0; i < 4; ++i) {
        os << vertices[i];
        if (i < 3) os << " ";
    }
}

void Square::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

Figure* Square::clone() const {
    return new Square(*this);
}

const Point& Square::getVertex(size_t index) const {
    if (index >= 4) {
        throw std::out_of_range("Square vertex index out of range");
    }
    return vertices[index];
}

void Square::setVertex(size_t index, const Point& p) {
    if (index >= 4) {
        throw std::out_of_range("Square vertex index out of range");
    }
    vertices[index] = p;
}