#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
    
    Point() : x(0.0), y(0.0) {}
    
    Point(double x_, double y_) : x(x_), y(y_) {}
    
    // Оператор сравнения
    bool operator==(const Point& other) const {
        const double epsilon = 1e-9;
        return std::abs(x - other.x) < epsilon && 
               std::abs(y - other.y) < epsilon;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

// Оператор вывода для Point для отладки
inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
// Оператор ввода для Point
inline std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

#endif 