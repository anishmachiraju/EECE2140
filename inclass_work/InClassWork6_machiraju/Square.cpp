#include "Square.h"

Square::Square() : side(0) {}

Square::Square(int side) : side(0) {
    setSide(side);
}

int Square::getSide() const { return side; }

void Square::setSide(int s) {
    if (s >= 0) side = s;
    else side = 0;
}

int Square::getArea() const {
    return side * side;
}

int Square::getPerimeter() const {
    return 4 * side;
}
