#include <iostream>
#include <memory>
#include "include/Figure.h"
#include "include/FigureArray.h"
#include "include/Triangle.h"
#include "include/Square.h"
#include "include/Rectangle.h"
#define NOGDI     
#include <windows.h>

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // Создаем массив для хранения фигур
    FigureArray figures;
    
    // Создаем различные фигуры
    std::cout << "\n1. Создание фигур..." << std::endl;
    
    // Треугольник по умолчанию (равносторонний)
    Triangle* triangle1 = new Triangle();
    figures.add(triangle1);
    
    // Треугольник с заданными координатами
    Triangle* triangle2 = new Triangle(Point(0, 0), Point(3, 0), Point(1.5, 2.6));
    figures.add(triangle2);
    
    // Квадрат по умолчанию
    Square* square1 = new Square();
    figures.add(square1);
    
    // Квадрат с заданными координатами
    Square* square2 = new Square(
        Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)
    );
    figures.add(square2);
    
    // Прямоугольник по умолчанию
    Rectangle* rectangle1 = new Rectangle();
    figures.add(rectangle1);
    
    // Прямоугольник с заданными координатами
    Rectangle* rectangle2 = new Rectangle(
        Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2)
    );
    figures.add(rectangle2);
    
    // Выводим информацию о всех фигурах
    figures.printAll();
    
    // Демонстрация работы с отдельными фигурами
    std::cout << "\n2. Работа с отдельными фигурами..." << std::endl;
    
    Figure* fig = figures.get(0); // Первый треугольник
    std::cout << "Первая фигура: " << *fig << std::endl;
    std::cout << "Центр: " << fig->getCenter() << std::endl;
    std::cout << "Площадь: " << fig->getArea() << std::endl;
    std::cout << "Площадь через оператор приведения: " << static_cast<double>(*fig) << std::endl;
    
    // Демонстрация клонирования
    std::cout << "\n3. Демонстрация клонирования..." << std::endl;
    Figure* cloned = fig->clone();
    std::cout << "Клон: " << *cloned << std::endl;
    std::cout << "Центр клона: " << cloned->getCenter() << std::endl;
    figures.add(cloned);
    
    // Обновляем информацию
    std::cout << "\n4. Обновленная информация после добавления клона:" << std::endl;
    figures.printAll();
    
    // Демонстрация удаления фигуры
    std::cout << "\n5. Удаление фигуры с индексом 1..." << std::endl;
    figures.remove(1);
    std::cout << "После удаления:" << std::endl;
    figures.printAll();
    
    // Демонстрация работы с вершинами
    std::cout << "\n6. Работа с вершинами треугольника..." << std::endl;
    Triangle* triangle = dynamic_cast<Triangle*>(figures.get(0));
    if (triangle) {
        std::cout << "Вершины треугольника:" << std::endl;
        for (size_t i = 0; i < 3; ++i) {
            std::cout << "  Вершина " << i << ": " << triangle->getVertex(i) << std::endl;
        }
        
        // Изменяем одну вершину
        triangle->setVertex(0, Point(5, 5));
        std::cout << "После изменения первой вершины на (5, 5):" << std::endl;
        std::cout << "Новый центр: " << triangle->getCenter() << std::endl;
        std::cout << "Новая площадь: " << triangle->getArea() << std::endl;
    }
    
    std::cout << "\n7. Финальное состояние массива:" << std::endl;
    figures.printAll();
    
    std::cout << "\n=== Программа завершена ===" << std::endl;
    
    return 0;
}
