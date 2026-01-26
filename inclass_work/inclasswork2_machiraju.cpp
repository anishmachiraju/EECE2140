#include <iostream>
using namespace std;

int main() {
    int choice;
    
    do {
        cout << "\nSecret Code Decoder" << endl;
        cout << "1. Decode a message" << endl;
        cout << "2. Show decoding rules" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int length;
                
                cout << "\nHow many numbers are in the secret sequence? ";
                cin >> length;
                
                while (length <= 0) {
                    cout << "Invalid length! enter a positive number: ";
                    cin >> length;
                }
                
                cout << "Enter " << length << " numbers: " << endl;
                
                string message = "";
                
                for (int i = 0; i < length; i++) {
                    int code;
                    cin >> code;
                    
                    if (code >= 1 && code <= 26) {
                        char letter = 'A' + (code - 1);
                        message += letter;
                    } else {
                        message += '?';
                    }
                }
                
                cout << "\nDecoded message: " << message << endl;
                break;
            }
            
            case 2: {
                cout << "\nDecoding Rules" << endl;
                cout << "Each number represents a letter:" << endl;
                cout << "  1 = A, 2 = B, 3 = C, ..., 26 = Z" << endl;
                cout << "Any number outside 1-26 will be decoded as '?'" << endl;
                break;
            }
            
            case 0:
                break;
            
            default:
                cout << "\nInvalid option! Please try again." << endl;
                break;
        }
        
    } while (choice != 0);
    
    return 0;
}