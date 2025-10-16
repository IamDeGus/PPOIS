/**
 * @file point.h
 * @author DeGus
 * 
 * @brief Определение класса трёхмерной точки Point.
 *
 * @details
 * Данный класс реализует простую трёхмерную точку в декартовой системе координат,
 * а также базовые операции над точками: сложение, вычитание, умножение на скаляр
 * и вычисление длины (модуля) вектора.
 *  
 * @version 0.1
 * @date 2025-09-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once



/**
 * @class Point
 * @brief Класс, представляющий трёхмерную точку в пространстве.
 *
 * Содержит координаты x, y, z и набор базовых операций над ними.
 */
class Point{
public:
    double x; ///< X-координата
    double y; ///< Y-координата
    double z; ///< Z-координата 

    /**
     * @brief Конструктор по умолчанию.
     * 
     * Инициализирует все координаты нулями.
     */
    Point() : x(0), y(0), z(0) {}


    /**
     * @brief Конструктор с параметрами.
     * 
     * @param x X-координата.
     * @param y Y-координата.
     * @param z Z-координата.
     */
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    /**
     * @brief Вычитание точек (векторов).
     * 
     * @param other Другая точка.
     * @return Point Разность текущей и другой точки.
     */
    Point operator-(const Point& other) const;

    /**
     * @brief Сложение точек (векторов).
     * 
     * @param other Другая точка.
     * @return Point Сумма текущей и другой точки.
     */
    Point operator+(const Point& other) const;

    /**
     * @brief Умножение на скаляр.
     * 
     * @param other Скаляр (число, на которое умножается вектор).
     * @return Point Результат умножения.
     */
    Point operator*(const double& other) const;

    /**
     * @brief Вычитание с присваиванием.
     * 
     * @param other Другая точка.
     * @return Point& Ссылка на текущий объект.
     */
    Point& operator-=(const Point& other);

    /**
     * @brief Сложение с присваиванием.
     * 
     * @param other Другая точка.
     * @return Point& Ссылка на текущий объект.
     */
    Point& operator+=(const Point& other);

    /**
     * @brief Умножение с присваиванием на скаляр.
     * 
     * @param other Скаляр.
     * @return Point& Ссылка на текущий объект.
     */
    Point& operator*=(const double& other);

    /**
     * @brief Вычисляет длину (модуль) вектора.
     * 
     * @return double Длина вектора.
     */
    double GetLength() const;

};
