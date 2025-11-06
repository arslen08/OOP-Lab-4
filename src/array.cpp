#include "../includes/array.h"
#include <iostream>
#include "../includes/hexagon.h"
#include "../includes/pentagon.h"
#include "../includes/octagon.h"

template<typename T>
void Array<T>::resize(size_t newCapacity) {
    auto newData = std::make_unique<T[]>(newCapacity);
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
    capacity = newCapacity;
}

template<typename T>
Array<T>::Array() : capacity(2), size(0) {
    data = std::make_unique<T[]>(capacity);
}

template<typename T>
Array<T>::Array(const Array& other) : capacity(other.capacity), size(other.size) {
    data = std::make_unique<T[]>(capacity);
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        data = std::make_unique<T[]>(capacity);
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::Array(Array&& other) noexcept 
    : data(std::move(other.data))
    , capacity(other.capacity)
    , size(other.size) {
    other.capacity = 0;
    other.size = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        capacity = other.capacity;
        size = other.size;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

template<typename T>
void Array<T>::push_back(const T& elem) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = elem;
}

template<typename T>
void Array<T>::erase(size_t index) {
    if (index >= size) return;
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
    data[size] = T();
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    return data[index];
}

template<typename T>
size_t Array<T>::getSize() const {
    return size;
}

template<typename T>
size_t Array<T>::getCapacity() const {
    return capacity;
}

template<typename T>
double Array<T>::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            total += data[i]->area();
        }
    }
    return total;
}

template<typename T>
void Array<T>::printAll() const {
    std::cout << "Array contents (" << size << " elements):\n";
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            std::cout << "Element " << i << ":\n";
            data[i]->printVertices();
            std::cout << "Center: " << data[i]->getCenter() << "\n";
            std::cout << "Area: " << data[i]->area() << "\n\n";
        }
    }
}

template class Array<std::shared_ptr<Figure<int>>>;
template class Array<std::shared_ptr<Figure<double>>>;
template class Array<std::shared_ptr<Figure<float>>>;

template class Array<std::shared_ptr<Hexagon<int>>>;
template class Array<std::shared_ptr<Hexagon<double>>>;
template class Array<std::shared_ptr<Hexagon<float>>>;
template class Array<std::shared_ptr<Pentagon<int>>>;
template class Array<std::shared_ptr<Pentagon<double>>>;
template class Array<std::shared_ptr<Pentagon<float>>>;
template class Array<std::shared_ptr<Octagon<int>>>;
template class Array<std::shared_ptr<Octagon<double>>>;
template class Array<std::shared_ptr<Octagon<float>>>;