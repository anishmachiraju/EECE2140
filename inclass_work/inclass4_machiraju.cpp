#include <iostream>
using namespace std;

void question1() {
    int scores[5];
    scores[2] = 90; 
    
    cout << "1) Third element (index 2): " << scores[2] << endl << endl;
}

void question2() {
    int nums[4] = {2, 4, 6, 8};
    cout << "2) Array elements:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << nums[i] << endl;
    }
    cout << endl;
}

void question3() {
    int values[6] = {3, 5, 1, 4, 2, 7};
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += values[i];
    }
    cout << "3) Sum of array: " << sum << endl << endl;
}

void question5() {
    int arr[] = {7, 2, 9, 4, 1};
    int size = 5;
    int minVal = arr[0];
    int maxVal = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    cout << "5) Min = " << minVal << endl;
    cout << "    Max = " << maxVal << endl << endl;
}

void question6() {
    int reverseArr[] = {1, 3, 5, 7, 9};
    int reverseSize = 5;
    
    for (int i = 0; i < reverseSize / 2; i++) {
        int temp = reverseArr[i];
        reverseArr[i] = reverseArr[reverseSize - 1 - i];
        reverseArr[reverseSize - 1 - i] = temp;
    }
    
    cout << "6) Reversed array: ";
    for (int i = 0; i < reverseSize; i++) {
        cout << reverseArr[i] << " ";
    }
    cout << endl;
}

int main() {
    string input;
    
    while (true) {
        cout << "Inclass4 Questions" << endl;
        cout << "Q1" << endl;
        cout << "Q2" << endl;
        cout << "Q3" << endl;
        cout << "Q5" << endl;
        cout << "Q6" << endl;
        cout << "Enter your choice (1-6 or 'q' to quit): ";
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
            case 3:
                question3();
                break;
            case 5:
                question5();
                break;
            case 6:
                question6();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}