#pragma once
#include <memory>
#include <iostream>
#include "figure.h"

template<typename T>
class Array {
private:
    std::unique_ptr<T[]> data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity);

public:
    Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;

    void push_back(const T& elem);
    void erase(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
    double totalArea() const;
    void printAll() const;
};