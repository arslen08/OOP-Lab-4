#include "../includes/hexagon.h"
#include <iostream>

template<typename T> requires Scalar<T>
void Hexagon<T>::printVertices() const {
    std::cout << "Hexagon vertices (radius " << radius << "):\n";
    for (int i = 0; i < 6; ++i) {
        double angle = 2 * M_PI * i / 6 - M_PI / 2;
        T x = center->getX() + radius * std::cos(angle);
        T y = center->getY() + radius * std::sin(angle);
        std::cout << "  " << Point<T>(x, y) << "\n";
    }
}

template class Hexagon<int>;
template class Hexagon<double>;
template class Hexagon<float>;