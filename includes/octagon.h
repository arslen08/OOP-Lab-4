#pragma once
#include "figure.h"
#include <cmath>
#include <memory>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T> requires Scalar<T>
class Octagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T radius;

public:
    Octagon(T x = T(), T y = T(), T r = T()) : center(std::make_unique<Point<T>>(x, y)), radius(r) {}
    Octagon(const Octagon& other) : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}
    Octagon& operator=(const Octagon& other) {
        if (this != &other) {
            center = std::make_unique<Point<T>>(*other.center);
            radius = other.radius;
        }
        return *this;
    }

    Point<T> getCenter() const override { return *center; }
    T getRadius() const { return radius; }
    
    double area() const override {
        return 2.0 * radius * radius * (1 + std::sqrt(2));
    }
    
    void printVertices() const override;
    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Octagon>(*this);
    }
    
    bool operator==(const Octagon& other) const {
        return center == other.center && radius == other.radius;
    }
};