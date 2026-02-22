#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
private:
    int itsAge;
    int itsYearsOfService;
    double itsSalary;

public:
    // Exercise 5 bonus: default constructor initializes to 0
    Employee();

    // Exercise 5: parameterized constructor
    Employee(int age, int yearsOfService, double salary);

    // Exercise 2: getters (const)
    int getAge() const;
    int getYearsOfService() const;
    double getSalary() const;

    // Exercise 2: setters (with validation)
    void setAge(int age);
    void setYearsOfService(int yearsOfService);
    void setSalary(double salary);

    // Exercise 4: business logic
    int getSalaryInThousands() const;

    // Exercise 3 bonus: formatted printing
    void display(const std::string& label = "") const;
};

#endif
