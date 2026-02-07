#include "publication.h"
#include <iostream>

static const double COST_PER_PAGE = 0.05;
static const double HARDCOVER_FEE = 7.50;
static const double COLOR_FEE_PER_PAGE = 0.20;

double calculateCost(int pages) {
    return calculateCost(pages, false, 0);
}

double calculateCost(int pages, bool hardcover) {
    return calculateCost(pages, hardcover, 0);
}

double calculateCost(int pages, bool hardcover, int colorPages) {
    if (pages <= 0) return -1;
    if (colorPages < 0 || colorPages > pages) return -1;

    double cost = pages * COST_PER_PAGE;

    if (hardcover) {
        cost += HARDCOVER_FEE;
    }

    cost += colorPages * COLOR_FEE_PER_PAGE;

    return cost;
}

double calculateCost(int pages, double discountPercent) {
    if (pages <= 0) return -1;
    if (discountPercent < 0.0 || discountPercent > 50.0) return -1;

    double cost = calculateCost(pages); // base paperback, no color
    if (cost < 0) return -1;

    cost *= (1.0 - discountPercent / 100.0);
    return cost;
}

void printReceipt(int pages, bool hardcover, int colorPages, double cost) {
    std::cout << "\n Publication Receipt \n";
    std::cout << "Total pages:      " << pages << "\n";
    std::cout << "Hardcover:        " << (hardcover ? "Yes" : "No") << "\n";
    std::cout << "Color pages:      " << colorPages << "\n";
    std::cout << "Total cost:       $" << cost << "\n";

}
