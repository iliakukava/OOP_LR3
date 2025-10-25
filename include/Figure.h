#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <iostream>

class Figure {
public:
    // деструктор
    virtual ~Figure() = default;
    // Вычисление геометрического центра фигуры
    virtual Point getCenter() const = 0;
    // Вычисление площади фигуры
    virtual double getArea() const = 0;    
    // Оператор приведения к double (возвращает площадь)
    virtual operator double() const = 0;
    // Вывод информации о фигуре
    virtual void print(std::ostream& os) const = 0;
    // Чтение данных фигуры 
    virtual void read(std::istream& is) = 0;
    
    
    
    // Клонирование фигуры (для копирования через указатель)    
    virtual Figure* clone() const = 0;
};


inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}
inline std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}

#endif 