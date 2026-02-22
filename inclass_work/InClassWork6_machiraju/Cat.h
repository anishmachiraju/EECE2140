#ifndef CAT_H
#define CAT_H

#include <string>

class Cat {
private:
    int itsAge;
    double itsWeight;
    std::string itsName;

public:
    Cat();
    Cat(const std::string& name, int age, double weight);

    int getAge() const;
    double getWeight() const;
    std::string getName() const;

    void setAge(int age);
    void setWeight(double weight);
    void setName(const std::string& name);

    void meow() const;
    void displayInfo() const;
};

#endif
