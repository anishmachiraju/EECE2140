#include "Cat.h"
#include <iostream>

Cat::Cat() : itsAge(0), itsWeight(0.0), itsName("Unknown") {}

Cat::Cat(const std::string& name, int age, double weight)
    : itsAge(0), itsWeight(0.0), itsName("Unknown") {
    setName(name);
    setAge(age);
    setWeight(weight);
}

int Cat::getAge() const { return itsAge; }
double Cat::getWeight() const { return itsWeight; }
std::string Cat::getName() const { return itsName; }

void Cat::setAge(int age) {
    if (age >= 0) itsAge = age;
    else itsAge = 0;
}

void Cat::setWeight(double weight) {
    if (weight >= 0.0) itsWeight = weight;
    else itsWeight = 0.0;
}

void Cat::setName(const std::string& name) {
    if (!name.empty()) itsName = name;
    else itsName = "Unknown";
}

void Cat::meow() const {
    std::cout << itsName << " says meow!\n";
}

void Cat::displayInfo() const {
    std::cout << "Cat Info:\n";
    std::cout << "Name: " << itsName << "\n";
    std::cout << "Age: " << itsAge << "\n";
    std::cout << "Weight: " << itsWeight << "\n";
}
