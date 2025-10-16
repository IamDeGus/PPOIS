#include "point.h"
#include <cmath>

using namespace std;


Point Point::operator+(const Point& other) const{
    double new_x = this->x + other.x;
    double new_y = this->y + other.y;
    double new_z = this->z + other.z;

    return Point(new_x, new_y, new_z);
}

Point& Point::operator+=(const Point& other){
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    this->z = this->z + other.z;

    return *this;
}


Point Point::operator-(const Point& other) const{
    double new_x = this->x - other.x;
    double new_y = this->y - other.y;
    double new_z = this->z - other.z;

    return Point(new_x, new_y, new_z);
}

Point& Point::operator-=(const Point& other){
    this->x = this->x - other.x;
    this->y = this->y - other.y;
    this->z = this->z - other.z;

    return *this;
}


Point Point::operator*(const double& other) const{
    double new_x = this->x * other;
    double new_y = this->y * other;
    double new_z = this->z * other;

    return Point(new_x, new_y, new_z);
}

Point& Point::operator*=(const double& other){
    this->x = this->x * other;
    this->y = this->y * other;
    this->z = this->z * other;

    return *this;
}

double Point::GetLength() const{
    return sqrt( pow(x, 2) + pow(y, 2) + pow(z, 2));
}
