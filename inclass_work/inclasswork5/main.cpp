#include <iostream>
#include "publication.h"

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(999999, '\n');
}

static bool readInt(const std::string& prompt, int& out) {
    std::cout << prompt;
    if (!(std::cin >> out)) {
        clearInput();
        return false;
    }
    return true;
}

static bool readBool01(const std::string& prompt, bool& out) {
    int x;
    std::cout << prompt;
    if (!(std::cin >> x)) {
        clearInput();
        return false;
    }
    if (x != 0 && x != 1) return false;
    out = (x == 1);
    return true;
}

static bool readDouble(const std::string& prompt, double& out) {
    std::cout << prompt;
    if (!(std::cin >> out)) {
        clearInput();
        return false;
    }
    return true;
}

int main() {
    int choice;

    while (true) {
        std::cout << "\n Menu\n";
        std::cout << "1) Cost by pages only\n";
        std::cout << "2) Cost by pages and hardcover\n";
        std::cout << "3) Cost by pages, hardcover, and color pages\n";
        std::cout << "4) (Optional) Cost by pages with discount percent\n";
        std::cout << "0) Exit\n";
        std::cout << "Choose: ";

        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Invalid input. Try again.\n\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Goodbye!\n";
            break;
        }

        int pages = 0;
        bool hardcover = false;
        int colorPages = 0;
        double cost = -1;

        if (choice == 1) {
            if (!readInt("Enter total pages: ", pages)) {
                std::cout << "Invalid pages input.\n\n";
                continue;
            }
            cost = calculateCost(pages);
            if (cost >= 0) printReceipt(pages, false, 0, cost);
            else std::cout << "Invalid values (pages must be > 0).\n\n";
        }
        else if (choice == 2) {
            if (!readInt("Enter total pages: ", pages)) {
                std::cout << "Invalid pages input.\n\n";
                continue;
            }
            if (!readBool01("Hardcover? (1 = yes, 0 = no): ", hardcover)) {
                std::cout << "Invalid hardcover input (must be 0 or 1).\n\n";
                continue;
            }
            cost = calculateCost(pages, hardcover);
            if (cost >= 0) printReceipt(pages, hardcover, 0, cost);
            else std::cout << "Invalid values (pages must be > 0).\n\n";
        }
        else if (choice == 3) {
            if (!readInt("Enter total pages: ", pages)) {
                std::cout << "Invalid pages input.\n\n";
                continue;
            }
            if (!readBool01("Hardcover? (1 = yes, 0 = no): ", hardcover)) {
                std::cout << "Invalid hardcover input (must be 0 or 1).\n\n";
                continue;
            }
            if (!readInt("Enter number of color pages: ", colorPages)) {
                std::cout << "Invalid color pages input.\n\n";
                continue;
            }

            cost = calculateCost(pages, hardcover, colorPages);
            if (cost >= 0) printReceipt(pages, hardcover, colorPages, cost);
            else std::cout << "Invalid values (pages must be > 0, and 0 <= colorPages <= pages).\n\n";
        }
        else if (choice == 4) {
            // Optional extra challenge path
            double discount = 0.0;

            if (!readInt("Enter total pages: ", pages)) {
                std::cout << "Invalid pages input.\n\n";
                continue;
            }
            if (!readDouble("Enter discount percent (0 to 50): ", discount)) {
                std::cout << "Invalid discount input.\n\n";
                continue;
            }

            cost = calculateCost(pages, discount);
            if (cost >= 0) printReceipt(pages, false, 0, cost);
            else std::cout << "Invalid values (pages > 0, discount 0-50).\n\n";
        }
        else {
            std::cout << "Invalid menu option.\n\n";
        }
    }

    return 0;
}
