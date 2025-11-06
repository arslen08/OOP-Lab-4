#pragma once
#include "point.h"
#include <memory>

template<typename T> requires Scalar<T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point<T> getCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices() const = 0;
    virtual std::unique_ptr<Figure<T>> clone() const = 0;
    
    virtual operator double() const {
        return area();
    }
    
    virtual bool operator==(const Figure<T>& other) const {
        return getCenter() == other.getCenter() && area() == other.area();
    }
};