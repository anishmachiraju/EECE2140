#include "Employee.h"
#include <iomanip>

Employee::Employee()
    : itsAge(0), itsYearsOfService(0), itsSalary(0.0) {}

Employee::Employee(int age, int yearsOfService, double salary)
    : itsAge(0), itsYearsOfService(0), itsSalary(0.0) {
    // Validation via setters
    setAge(age);
    setYearsOfService(yearsOfService);
    setSalary(salary);
}

int Employee::getAge() const { return itsAge; }
int Employee::getYearsOfService() const { return itsYearsOfService; }
double Employee::getSalary() const { return itsSalary; }

void Employee::setAge(int age) {
    if (age > 0) itsAge = age;
    else itsAge = 0; // keep object valid
}

void Employee::setYearsOfService(int yearsOfService) {
    if (yearsOfService >= 0) itsYearsOfService = yearsOfService;
    else itsYearsOfService = 0;
}

void Employee::setSalary(double salary) {
    if (salary >= 0.0) itsSalary = salary;
    else itsSalary = 0.0;
}

// Exercise 4: round to nearest thousand
int Employee::getSalaryInThousands() const {
    // Handout hint: (salary + 500) / 1000
    // salary is double, so compute carefully:
    return static_cast<int>((itsSalary + 500.0) / 1000.0);
}

void Employee::display(const std::string& label) const {
    if (!label.empty()) {
        std::cout << label << "\n";
    }
    std::cout << "Age : " << itsAge << " years\n";
    std::cout << "Years of Service : " << itsYearsOfService << " years\n";
    std::cout << "Salary : $"
              << std::fixed << std::setprecision(2)
              << itsSalary << "\n";
}
