#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include <cstddef>

// Динамический массив указателей на фигуры
class FigureArray {
private:
    Figure** data;      // Массив указателей на Figure
    size_t capacity;    // Вместимость массива
    size_t size;        // Текущее количество фигур
    
    void resize();     
    
public:
    // Конструктор
    FigureArray(size_t initialCapacity = 10);
    
    // Деструктор
    ~FigureArray();
    
    // Запрет копирования
    FigureArray(const FigureArray&) = delete;
    FigureArray& operator=(const FigureArray&) = delete;
    
    // Добавить фигуру
    void add(Figure* figure);
    
    // Удалить фигуру по индексу
    void remove(size_t index);
    
    // Получить фигуру по индексу
    Figure* get(size_t index) const;
    
    // Получить количество фигур
    size_t getSize() const { return size; }
    
    // Вычислить общую площадь всех фигур
    double getTotalArea() const;

    void printAll() const;
    
    void clear();
};

#endif