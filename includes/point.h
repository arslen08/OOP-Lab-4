#pragma once
#include <iostream>
#include <concepts> 

template<typename T>
concept Scalar = std::integral<T> || std::floating_point<T>;

template<Scalar T>
class Point {
private:
    T x, y;
public:
    Point(T x = T(), T y = T()) : x(x), y(y) {}
    
    T getX() const { return x; }
    T getY() const { return y; }
    
    void setX(T newX) { x = newX; }
    void setY(T newY) { y = newY; }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    Point operator*(T scalar) const {
        return Point(x * scalar, y * scalar);
    }
};