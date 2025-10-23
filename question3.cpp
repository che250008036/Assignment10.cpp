#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

// Function to display all employee details
void displayEmployees(Employee employees[], int n) {
    cout << "\nEmployee Details:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Salary\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << employees[i].id
             << setw(20) << employees[i].name
             << setw(10) << fixed << setprecision(2) << employees[i].salary << endl;
    }
}

// Function to search for an employee by ID
void searchEmployee(Employee employees[], int n, int id) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            cout << "\nEmployee found:\n";
            cout << "ID: " << employees[i].id << "\n";
            cout << "Name: " << employees[i].name << "\n";
            cout << "Salary: ₹" << fixed << setprecision(2) << employees[i].salary << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nEmployee with ID " << id << " not found.\n";
    }
}

// Function to increase salary of employees earning less than ₹30,000
void increaseSalary(Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        if (employees[i].salary < 30000) {
            employees[i].salary += employees[i].salary * 0.10;  // Increase by 10%
        }
    }
    cout << "\nSalary of employees earning less than ₹30,000 has been increased by 10%.\n";
}

int main() {
    Employee employees[10];
    int choice, id;

    // Input employee details
    cout << "Enter details of 10 employees:\n";
    for (int i = 0; i < 10; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> employees[i].id;
        cin.ignore(); // To ignore the newline left by cin
        cout << "Enter Name: ";
        getline(cin, employees[i].name);
        cout << "Enter Salary: ₹";
        cin >> employees[i].salary;
    }

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Display all employee details\n";
        cout << "2. Search for an employee by ID\n";
        cout << "3. Increase salary for employees earning less than ₹30,000\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayEmployees(employees, 10);
                break;
            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                searchEmployee(employees, 10, id);
                break;
            case 3:
                increaseSalary(employees, 10);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


	
