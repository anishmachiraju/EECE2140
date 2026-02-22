#ifndef SQUARE_H
#define SQUARE_H

class Square {
private:
    int side;

public:
    Square();              // default
    Square(int side);      // constructor with parameter

    int getSide() const;
    void setSide(int side);

    int getArea() const;        // side * side
    int getPerimeter() const;   // 4 * side
};

#endif
