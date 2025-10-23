#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>


struct Item {
    int id;
    std::string name;
    float cost;
};

bool compareByCostDescending(const Item& a, const Item& b) {
    return a.cost > b.cost;
}

int main() {
     const int NUM_ITEMS = 8;
    Item items[NUM_ITEMS];

    float totalCost = 0.0f;

    std::cout << "Please enter details for " << NUM_ITEMS << " items.\n";
    for (int i = 0; i < NUM_ITEMS; ++i) {
        std::cout << "\n--- Item " << (i + 1) << " ---\n";
       
        std::cout << "Enter ID: ";
        std::cin >> items[i].id;

        std::cout << "Enter Cost: ";
        std::cin >> items[i].cost;

       
        totalCost += items[i].cost;

       
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter Name: ";
        std::getline(std::cin, items[i].name);
    }
    std::sort(items, items + NUM_ITEMS, compareByCostDescending);
    std::cout << "\n--- Items Sorted by Cost (Descending) ---\n";
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < NUM_ITEMS; ++i) {
        std::cout << "ID: " << items[i].id
                  << ", Name: " << items[i].name
                  << ", Cost: " << items[i].cost << std::endl;
    }

    float averageCost = totalCost / NUM_ITEMS;
    std::cout << "\n----------------------------------------\n";
    std::cout << "Average Cost of all items: " << averageCost << std::endl;

    return 0;
}
	
