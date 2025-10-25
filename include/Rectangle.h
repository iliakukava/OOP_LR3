#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <array>

class Rectangle : public Figure {
private:
    std::array<Point, 4> vertices; 
    
public:
    Rectangle();  
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Rectangle(const std::array<Point, 4>& points);
    // Конструктор копирования
    Rectangle(const Rectangle& other);
    // Конструктор перемещения
    Rectangle(Rectangle&& other) noexcept;
    
    // Деструктор
    ~Rectangle() override = default;
    
    // Оператор присваивания (копирование)
    Rectangle& operator=(const Rectangle& other);
    
    // Оператор присваивания (перемещение)
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Rectangle& other) const;
    
    Point getCenter() const override;
    double getArea() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* clone() const override;
    
    const Point& getVertex(size_t index) const;
    void setVertex(size_t index, const Point& p);
};

#endif 