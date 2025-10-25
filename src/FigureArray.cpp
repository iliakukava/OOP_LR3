#include "../include/FigureArray.h"
#include <iostream>
#include <stdexcept>

FigureArray::FigureArray(size_t initialCapacity) 
    : capacity(initialCapacity), size(0) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        data[i] = nullptr;
    }
}

FigureArray::~FigureArray() {
    clear();
    delete[] data;
}

void FigureArray::resize() {
    size_t newCapacity = capacity * 2;
    Figure** newData = new Figure*[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    for (size_t i = size; i < newCapacity; ++i) {
        newData[i] = nullptr;
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void FigureArray::add(Figure* figure) {
    if (figure == nullptr) {
        throw std::invalid_argument("Cannot add null figure");
    }
    if (size >= capacity) {
        resize();
    }
    
    data[size++] = figure;
}

void FigureArray::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete data[index];
    // Сдвигаем все элементы после удалённого влево
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    data[--size] = nullptr;
}

Figure* FigureArray::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

double FigureArray::getTotalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*data[i]);
    }
    return total;
}

void FigureArray::printAll() const {
    if (size == 0) {
        std::cout << "Массив пуст" << std::endl;
        return;
    }
    
    std::cout << "\n Все фигуры в массиве" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << i << ". ";
        std::cout << *data[i];
        Point center = data[i]->getCenter();
        double area = data[i]->getArea();
        
        std::cout << "Центр: " << center 
                  << "Площадь: " << area << std::endl;
    }
    std::cout << "\nОбщая площадь всех фигур: " << getTotalArea() << std::endl;
}

void FigureArray::clear() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
        data[i] = nullptr;
    }
    size = 0;
}