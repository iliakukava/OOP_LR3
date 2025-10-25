#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <array>

class Square : public Figure {
private:
    std::array<Point, 4> vertices; 
    
public:
    // Конструкторы
    Square();  
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Square(const std::array<Point, 4>& points);
    
    // Конструктор копирования
    Square(const Square& other);
    
    // Конструктор перемещения
    Square(Square&& other) noexcept;
    
    // Деструктор
    ~Square() override = default;
    
    // Оператор присваивания (копирование)
    Square& operator=(const Square& other);
    
    // Оператор присваивания (перемещение)
    Square& operator=(Square&& other) noexcept;
    
    // Оператор сравнения
    bool operator==(const Square& other) const;
   
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