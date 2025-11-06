#include "../includes/pentagon.h"
#include <iostream>

template<typename T> requires Scalar<T>
void Pentagon<T>::printVertices() const {
    std::cout << "Pentagon vertices (radius " << radius << "):\n";
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * M_PI * i / 5 - M_PI / 2;
        T x = center->getX() + radius * std::cos(angle);
        T y = center->getY() + radius * std::sin(angle);
        std::cout << "  " << Point<T>(x, y) << "\n";
    }
}

template class Pentagon<int>;
template class Pentagon<double>;
template class Pentagon<float>;