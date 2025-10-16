#include "vector.h"

#include <cmath>
#include <stdexcept>


using namespace std;


//------ конструктор ------//

Vector::Vector(const Point& b, const Point& e) : beg(b), end(e) {
    vec = end - beg;
}

Vector::Vector() : beg{0,0,0}, end{0,0,0}, vec{0,0,0} {};



//------ гетеры ------//

Point Vector::GetBegin() const{
    return beg;
}

Point Vector::GetEnd() const{
    return end;
}

double Vector::GetLength() const{
    return vec.GetLength();
}


//------ оператор косинуса ------//

double Vector::operator ^ (const Vector& other) const{
    if (this->GetLength() == 0 || other.GetLength() == 0)
        throw domain_error("Сosine between the zero vector");

    double scalar = this->vec.x * other.vec.x 
                  + this->vec.y * other.vec.y 
                  + this->vec.z * other.vec.z;
    return scalar / (this->GetLength() * other.GetLength());
}



//------ операторы векторного прпоизведения ------//

Vector Vector::operator * (const Vector& other) const{
    double new_x = this->vec.y * other.vec.z - this->vec.z * other.vec.y;
    double new_y = this->vec.z * other.vec.x - this->vec.x * other.vec.z;
    double new_z = this->vec.x * other.vec.y - this->vec.y * other.vec.x;

    return Vector({0, 0, 0}, {new_x, new_y, new_z});
}

Vector& Vector::operator *= (const Vector& other){
    double new_x = this->vec.y * other.vec.z - this->vec.z * other.vec.y;
    double new_y = this->vec.z * other.vec.x - this->vec.x * other.vec.z;
    double new_z = this->vec.x * other.vec.y - this->vec.y * other.vec.x;

    this->vec.x = new_x;
    this->vec.y = new_y;
    this->vec.z = new_z;

    this->end = this->beg + this->vec;

    return *this;
}



//------ операторы произведения вектора на число ------//

Vector Vector::operator * (const double& other) const{
    Point new_point = this->beg + this->vec * other; 
    return Vector(this->beg, new_point);
}

Vector& Vector::operator *= (const double& other){
    this->end = this->beg + this->vec * other; 
    this->vec = this->end - this->beg;
    return *this;
}



//------ операторы сложения векторов ------//

Vector Vector::operator + (const Vector& other) const{
    Point new_vec = this->vec + other.vec;
    return Vector({0, 0, 0}, new_vec);
}

Vector& Vector::operator += (const Vector& other){
    this->vec = this->vec + other.vec;
    this->end = this->beg + this->vec;

    return *this;
}

//------ операторы разности векторов ------//

Vector Vector::operator - (const Vector& other) const{
    Point new_vec = this->vec - other.vec;
    return Vector({0, 0, 0}, new_vec);
}

Vector& Vector::operator -= (const Vector& other){
    this->vec = this->vec - other.vec;
    this->end = this->beg + this->vec;

    return *this;
}



//------ операторы деления векторов ------//

Vector Vector::operator / (const Vector& other) const{
    if (other.vec.x == 0 || other.vec.y == 0 || other.vec.z == 0)
        throw domain_error("Division by zero vector");
    
    return Vector(
        {0, 0, 0}, 
        {
            this->vec.x / other.vec.x,
            this->vec.y / other.vec.y,
            this->vec.z / other.vec.z,
        }
    );
}

Vector& Vector::operator /= (const Vector& other){
    if (other.vec.x == 0 || other.vec.y == 0 || other.vec.z == 0)
        throw domain_error("Division by zero vector");

    this->vec.x = this->vec.x / other.vec.x;
    this->vec.y = this->vec.y / other.vec.y;
    this->vec.z = this->vec.z / other.vec.z;

    this->end = this->beg + this->vec;

    return *this;
}



//------ вспомогательная функция для операторов сравнения ------//

bool Vector::almostEQ(double a, double b, double eps){
    return fabs(a / b - 1) < eps; 
}



//------ операторы сравнения ------//

bool Vector::operator == (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");

    return almostEQ(this->vec.x, other.vec.x) &&
           almostEQ(this->vec.y, other.vec.y) &&
           almostEQ(this->vec.z, other.vec.z);
}

bool Vector::operator != (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");
    
    return !(almostEQ(this->vec.x, other.vec.x) &&
             almostEQ(this->vec.y, other.vec.y) &&
             almostEQ(this->vec.z, other.vec.z));
}

bool Vector::operator < (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");

    return (this->vec.x < other.vec.x) && (*this != other);
}

bool Vector::operator <= (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");

    return (this->vec.x < other.vec.x) || (*this == other);
}

bool Vector::operator > (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");

    return (this->vec.x > other.vec.x) && (*this != other);
}

bool Vector::operator >= (const Vector& other) const{
    if ((*this * other).GetLength() != 0)
        throw domain_error("Non-collinear vectors cannot be compared");

    return (this->vec.x > other.vec.x) || (*this == other);
}



//------ операторы для работы с потоками ------//

ostream& operator<<(ostream& os, const Vector& vec){
    os << "({" << vec.beg.x << "," << vec.beg.y << ","  << vec.beg.z << "},{"
               << vec.end.x << "," << vec.end.y << ","  << vec.end.z << "})";
    return os;
}

istream& operator>>(std::istream& is, Vector& vec){
    is >> vec.beg.x >> vec.beg.y >> vec.beg.z;
    is >> vec.end.x >> vec.end.y >> vec.end.z;

    vec.vec = vec.end - vec.beg;

    return is;
}
