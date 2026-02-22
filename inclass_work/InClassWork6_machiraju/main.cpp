#include <iostream>
#include "Employee.h"
#include "Square.h"
#include "Cat.h"
#include "TV.h"

int main() {
    // Exercises 3–5: Employee tests
    Employee emp1;
    emp1.setAge(30);
    emp1.setYearsOfService(5);
    emp1.setSalary(75000.0);

    Employee emp2(42, 15, 95000.0);

    std::cout << "Employee 1:\n";
    emp1.display();
    std::cout << "Salary in thousands: " << emp1.getSalaryInThousands() << "\n\n";

    std::cout << "Employee 2:\n";
    emp2.display();
    std::cout << "Salary in thousands: " << emp2.getSalaryInThousands() << "\n\n";

    // Exercise 6: Square
    Square sq(5);
    std::cout << "Square side: " << sq.getSide() << "\n";
    std::cout << "Square area: " << sq.getArea() << "\n";
    std::cout << "Square perimeter: " << sq.getPerimeter() << "\n\n";

    // Exercise 7: Cat
    Cat c("Milo", 3, 9.2);
    c.displayInfo();
    c.meow();
    std::cout << "\n";

    // Exercise 8: TV
    TV myTV;
    myTV.SetStation(9);
    myTV.displayStatus();

    myTV.SetStation(10);
    myTV.displayStatus();

    TV myOtherTV(2);
    std::cout << "Other ";
    myOtherTV.displayStatus();

    return 0;
}
