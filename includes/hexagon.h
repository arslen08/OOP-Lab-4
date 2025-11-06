#pragma once
#include "figure.h"
#include <cmath>
#include <memory>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T> requires Scalar<T>
class Hexagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T radius;

public:
    Hexagon(T x = T(), T y = T(), T r = T()) : center(std::make_unique<Point<T>>(x, y)), radius(r) {}
    Hexagon(const Hexagon& other) : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}
    Hexagon& operator=(const Hexagon& other) {
        if (this != &other) {
            center = std::make_unique<Point<T>>(*other.center);
            radius = other.radius;
        }
        return *this;
    }

    Point<T> getCenter() const override { return *center; }
    T getRadius() const { return radius; }
    
    double area() const override {
        return (3.0 * std::sqrt(3) / 2.0) * radius * radius;
    }
    
    void printVertices() const override;
    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Hexagon>(*this);
    }
    
    bool operator==(const Hexagon& other) const {
        return center == other.center && radius == other.radius;
    }
};