#include <iostream>
using namespace std;
// Mini Project 1: Terminal Calculator and git
int main() {
    double num1, num2;
    char operation;
    string input;
    
    cout << "Calculator" << endl;
    cout << "Supported operations: +, -, *, /, %" << endl;
    cout << "Type 'q' or 'exit' to quit\n" << endl;
    
    while (true) {
        cout << "Enter first number (or 'q' to quit): ";
        cin >> input;
        
        if (input == "q" || input == "exit") {
            break;
        }
        
        try {
            num1 = stod(input);
        } catch (...) {
            cout << "Invalid input. Please enter a valid number.\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        cout << "Enter operator (+, -, *, /, %): ";
        cin >> operation;
        
        if (operation != '+' && operation != '-' && operation != '*' && 
            operation != '/' && operation != '%') {
            cout << "Invalid operator. Please use +, -, *, /, or %\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        cout << "Enter second number: ";
        cin >> num2;
        
        if ((operation == '/' || operation == '%') && num2 == 0) {
            cout << "Error: Division by zero is not allowed.\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        double result;
        
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '%':
                result = (long long)num1 % (long long)num2;
                break;
        }
        
        cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << "\n" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    return 0;
}