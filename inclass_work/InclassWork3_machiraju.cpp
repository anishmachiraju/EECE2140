#include <iostream>
#include <cmath>
using namespace std;

void question1() {
    double x = 2.0, y = 3.0, a = 4.0, b = 9.0, c = 1.0;
    
    cout << "1) C++ Expressions:" << endl;
    cout << "a) 9.2 / 4 = " << 9.2 / 4 << endl;
    cout << "b) sqrt(5*x - 3*x*y) = " << sqrt(5*x - 3*x*y) << endl;
    cout << "c) pow(a + b, 1.0/3.0) = " << pow(a + b, 1.0/3.0) << endl;
    cout << "d) (-b + sqrt(b*b - 4*a*c)) / (2*a) = " << (-b + sqrt(b*b - 4*a*c)) / (2*a) << endl;
    cout << "e) abs(3*x*x - 2*y) = " << abs(3*x*x - 2*y) << endl << endl;
}

void question2() {
    double n1, n2, n3;
    cout << "2) Floor Comparison Function" << endl;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;
    
    bool result = (floor(n1 * n2) == floor(n3));
    cout << "floor(" << n1 << " * " << n2 << ") == floor(" << n3 << "): " << (result ? "TRUE" : "FALSE") << endl << endl;
}

void question5() {
    double num1, num2;
    cout << "5) Power-Sum Function" << endl;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    double result = pow(num1, num2) + pow(num2, num1);
    cout << num1 << "^" << num2 << " + " << num2 << "^" << num1 << " = " << result << endl << endl;
}

int main() {
    string input;
    
    while (true) {
        cout << "InClassWork 3 Questions" << endl;
        cout << "Q1" << endl;
        cout << "Q2" << endl;
        cout << "Q5" << endl;
        cout << "Enter your choice (1,2,5 or 'q' to quit): ";
        cin >> input;
        cout << endl;
        
        if (input == "q") {
            break;
        }
        
        int choice = stoi(input);
        
        switch(choice) {
            case 1:
                question1();
                break;
            case 2:
                question2();
                break;
            case 5:
                question5();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}