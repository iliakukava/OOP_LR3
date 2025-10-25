#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <array>

class Triangle : public Figure {
private:
    std::array<Point, 3> vertices; 

public:
    // Конструкторы
    Triangle(); 
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(const std::array<Point, 3>& points);
    
    // Конструктор копирования
    Triangle(const Triangle& other);
    // Конструктор перемещения
    Triangle(Triangle&& other) noexcept;
    ~Triangle() override = default;
    
    // Оператор присваивания (копирование)
    Triangle& operator=(const Triangle& other);
    // Оператор присваивания (перемещение)
    Triangle& operator=(Triangle&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Triangle& other) const;
    
    // Переопределение методов базового класса
    Point getCenter() const override;
    double getArea() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* clone() const override;
    

    const Point& getVertex(size_t index) const;
    void setVertex(size_t index, const Point& p);
};

#endif // TRIANGLE_H