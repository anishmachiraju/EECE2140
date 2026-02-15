#include <iostream>
#include <limits>
#include "include/Queue.h"

int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail()) {
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter an integer.\n";
    }
}

void printMenu() {
    std::cout << "\n Queue Menu\n";
    std::cout << "1. Enqueue\n";
    std::cout << "2. Dequeue\n";
    std::cout << "3. Peek\n";
    std::cout << "4. Size\n";
    std::cout << "5. Print queue\n";
    std::cout << "6. Clear queue\n";
    std::cout << "7. Is Empty?\n";
    std::cout << "8. Is Full?\n";
    std::cout << "9. Exit\n";
}

int main() {
    try {
        int cap = readInt("Enter queue capacity: ");
        Queue q(cap);

        bool running = true;
        while (running) {
            printMenu();
            int choice = readInt("Choose an option: ");

            try {
                switch (choice) {
                    case 1: {
                        int x = readInt("Enter value to enqueue: ");
                        q.enqueue(x);
                        std::cout << "Enqueued " << x << "\n";
                        break;
                    }
                    case 2: {
                        int removed = q.dequeue();
                        std::cout << "Dequeued " << removed << "\n";
                        break;
                    }
                    case 3: {
                        std::cout << "Front element: " << q.front() << "\n";
                        break;
                    }
                    case 4: {
                        std::cout << "Current size: " << q.size() << "\n";
                        break;
                    }
                    case 5: {
                        q.print();
                        break;
                    }
                    case 6: {
                        q.clear();
                        std::cout << "Queue cleared.\n";
                        break;
                    }
                    case 7: {
                        std::cout << (q.isEmpty() ? "Yes, queue is empty.\n" : "No, queue is not empty.\n");
                        break;
                    }
                    case 8: {
                        std::cout << (q.isFull() ? "Yes, queue is full.\n" : "No, queue is not full.\n");
                        break;
                    }
                    case 9: {
                        running = false;
                        std::cout << "Exiting...\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid option. Try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Initialization error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
