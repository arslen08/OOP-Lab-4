#include "../includes/octagon.h"
#include <iostream>

template<typename T> requires Scalar<T>
void Octagon<T>::printVertices() const {
    std::cout << "Octagon vertices (radius " << radius << "):\n";
    for (int i = 0; i < 8; ++i) {
        double angle = 2 * M_PI * i / 8 - M_PI / 2;
        T x = center->getX() + radius * std::cos(angle);
        T y = center->getY() + radius * std::sin(angle);
        std::cout << "  " << Point<T>(x, y) << "\n";
    }
}

template class Octagon<int>;
template class Octagon<double>;
template class Octagon<float>;