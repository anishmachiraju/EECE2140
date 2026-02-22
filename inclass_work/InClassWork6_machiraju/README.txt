README.txt

Name: Anish Machiraju
Student ID: 002863226

Compilation (g++):
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Employee.cpp Square.cpp Cat.cpp TV.cpp -o oop_exercises

Run:
./oop_exercises

File Descriptions:
- main.cpp
  Test driver that creates and exercises Employee, Square, Cat, and TV objects and prints results.

- Employee.h / Employee.cpp
  Defines and implements Employee with private members: age, yearsOfService, salary.
  Includes getters/setters with validation, a default + parameterized constructor, display(), and
  getSalaryInThousands() (rounds to nearest thousand).

- Square.h / Square.cpp
  Defines and implements Square with private side length and methods for area and perimeter.

- Cat.h / Cat.cpp
  Defines and implements Cat with private name, age, weight.
  Includes constructors, getters/setters with validation, meow(), and displayInfo().

- TV.h / TV.cpp
  Defines and implements TV with private station.
  Includes SetStation/GetStation, channelUp/channelDown, constructors (default and station), and displayStatus().
