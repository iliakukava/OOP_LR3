#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <iostream>

class Figure {
public:
    // деструктор
    virtual ~Figure() = default;
    virtual Point getCenter() const = 0;
    virtual double getArea() const = 0;    
    // Приведения к double возвращает площадь
    virtual operator double() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    
    // Создание копии фигуры (нужно для работы с указателями)
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