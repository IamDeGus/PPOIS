/**
 * @file vector.h
 * @author DeGus
 * @brief Класс Vector - для работы с векторами в трехмерном пространстве.
 * 
 * @version 0.1
 * @date 2025-09-11
 * 
 * @details 
 * Класс хранит начало (beg) и конец (end) вектора - для удобного представления,
 * а так же их разницу (vec) - для удобного и быстрого выполнения операций:
 * получение длины, сложение, вычитание, векторное произведение, произведение на
 * сколяр, покомпонентное деление, косинус угла и операторы сравнения.
 * 
 * @copyright Copyright (c) 2025
 * 
 * @see Point
 */



#pragma once

#include <iostream>
#include "../Point/point.h"

/// @brief  Класс для работы с векторами в трехмерном пространстве.
class Vector{
public:

    /**
     * @brief Конструктор вектора по начальной и конечной точке.
     * 
     * @param b Point& b - точка начала.
     * @param e Point& e - Точка конца.
     */
    Vector(const Point& b, const Point& e);

    /// @brief Конструктор по умолчанию, создает нулевой вектор.
    Vector();

    /// @brief Получить точку начала вектора.
    /// @return Point beg - точку начала вектора.
    Point GetBegin() const;

    /// @brief Получить точку конца вектора.
    /// @return Point end - точку конца вектора.
    Point GetEnd() const;

    /// @brief Вычислить длину (модуль) вектора.
    /// @return double Length - длину (модуль) вектора.
    double GetLength() const;



    /// @brief Сложение векторов по координатам (vec)
    /// и сохранение результата в новый вектор.
    /// @return Vector результат c beg = {0,0,0}.
    Vector operator + (const Vector&) const;

    /// @brief Прибавление второго вектора к первому по координатам (vec)
    /// и сохранение результата в первый вектор.
    /// @return Vector результат c beg = начало первого вектора.
    Vector& operator += (const Vector&);

    /// @brief Разность векторов по координатам (vec)
    /// и сохранение результата в новый вектор.
    /// @return Vector результат c beg = {0,0,0}.
    Vector operator - (const Vector&) const;

    /// @brief Вычитание из первого вектора второй по координатам (vec)
    /// и сохранение результата в первый вектор.
    /// @return Vector результат c beg = начало первого вектора.
    Vector& operator -= (const Vector&);

    /// @brief Векторное произведение.
    /// @return Новый вектор, перпендикулярный плоскости "векторов-родителей",
    /// с beg = {0,0,0}.
    Vector operator * (const Vector&) const;
    
    /// @brief Векторное произведение.
    /// @return Переписывает старый вектор, перпендикулярный плоскости "векторов-родителей",
    /// с beg = точка начала старого вектора.
    Vector& operator *= (const Vector&);

    /// @brief Произведение вектора на скаляр.
    /// @param  Double - скаляр.
    /// @return Новый вектор со старым beg, но изменненым масштабом.
    Vector operator * (const double&) const;

    /// @brief Произведение вектора на скаляр.
    /// @param  Double - скаляр.
    /// @return Вектор со старым beg, но изменненым масштабом.  
    Vector& operator *= (const double&);

    /// @brief Покомпонентное деление векторов.
    /// @return Новый вектор с beg = {0,0,0}.
    /// @throws Бросает исключение при делении на нулевой компонент.
    Vector operator / (const Vector&) const;

    /// @brief Покомпонентное деление векторов.
    /// @return Старый вектор с beg = началу старого вектора.
    /// @throws Бросает исключение при делении на нулевой компонент.
    Vector& operator /= (const Vector&);

    /// @brief Косинус угла между векторами.
    /// @return Double - значение косинуса.
    /// @throws Бросает исключение, если один из векторов нулевой.
    double operator ^ (const Vector&) const;
    

    /* --- Сравнение: определены только для коллинеарных векторов --- */
    /// @note Операторы сравнения реализованы для коллинеарных векторов,
    /// через сравнение модулей векторов. Елси векторы не коллинеарны,
    /// операторы бросают исключение.
    /// @name Операторы сравнения.
    /// @{
    bool operator < (const Vector&) const;
    bool operator <= (const Vector&) const;
    bool operator >= (const Vector&) const;
    bool operator > (const Vector&) const;
    bool operator == (const Vector&) const;
    bool operator != (const Vector&) const;
    /// @}


    /* --- Потоковые операции --- */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);

private:
    
    Point beg; ///< координаты начала
    Point end; ///< координаты конца

    Point vec; ///< (end - beg)

    /**
     * @brief Вспомогательная функция сравнение double чисел с учетом
     * относительной погрешности.
     * 
     * @param a Double - левый операнд
     * @param b Double - правый операнд
     * @param eps Double - допустимая погрешность (по умолчанию 1e-9)
     * @return true если a и b равны с заданной точностью (|1 - a/b| < eps)
     */
    static bool almostEQ(double a, double b, double eps=1e-9);
};



