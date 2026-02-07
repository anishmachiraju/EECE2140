#include <iostream>

int main() {
    int n =5;
    if (!(std::cin >> n)) return 0; // read number of rows
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) std::cout << '*';
    }
    return 0;
}