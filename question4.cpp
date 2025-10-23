#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct SalesRecord {
    string month;
    float amount;
};

int main() {
    SalesRecord records[12];
    float totalSales = 0.0;
    string filename = "sales_data.txt";

   
    for (int i = 0; i < 12; i++) {
        cout << "Enter sales for " << (i + 1) << " month:\n";
        cout << "Month: ";
        cin >> records[i].month;
        cout << "Sales amount: ₹";
        cin >> records[i].amount;
        totalSales += records[i].amount;
    }

   
    ofstream outFile(filename);
    for (int i = 0; i < 12; i++) {
        outFile << records[i].month << " " << records[i].amount << endl;
    }
    outFile.close();

   
    float yearlyAvg = totalSales / 12;

   
    ifstream inFile(filename);
    cout << "\nMonths with sales above the yearly average (₹" << fixed << setprecision(2) << yearlyAvg << "):\n";
    SalesRecord temp;
    while (inFile >> temp.month >> temp.amount) {
        if (temp.amount > yearlyAvg) {
            cout << temp.month << " - ₹" << fixed << setprecision(2) << temp.amount << endl;
        }
    }
    inFile.close();

    return 0;
}


	
