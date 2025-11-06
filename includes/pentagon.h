#pragma once
#include "figure.h"
#include <cmath>
#include <memory>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T> requires Scalar<T>
class Pentagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T radius;

public:
    Pentagon(T x = T(), T y = T(), T r = T()) : center(std::make_unique<Point<T>>(x, y)), radius(r) {}
    Pentagon(const Pentagon& other) : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}
    Pentagon& operator=(const Pentagon& other) {
        if (this != &other) {
            center = std::make_unique<Point<T>>(*other.center);
            radius = other.radius;
        }
        return *this;
    }

    Point<T> getCenter() const override { return *center; }
    T getRadius() const { return radius; }
    
    double area() const override {
        return (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5);
    }
    
    void printVertices() const override;
    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Pentagon>(*this);
    }
    
    bool operator==(const Pentagon& other) const {
        return center == other.center && radius == other.radius;
    }
};