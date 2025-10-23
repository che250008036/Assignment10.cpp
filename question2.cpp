#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Marks {
    float math;
    float science;
    float english;
};


struct Student {
    int rollNo;
    string name;
    Marks marks;
};


float calculate_average(const Marks& marks) {
    return (marks.math + marks.science + marks.english) / 3.0;
}

int main() {
    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];
    float avgMarks[NUM_STUDENTS];

   
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter details for Student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cin.ignore();

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Enter marks for Math, Science, and English:\n";
        cout << "Math: ";
        cin >> students[i].marks.math;
        cout << "Science: ";
        cin >> students[i].marks.science;
        cout << "English: ";
        cin >> students[i].marks.english;

        
        avgMarks[i] = calculate_average(students[i].marks);
    }

    
    int highestIndex = 0, lowestIndex = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (avgMarks[i] > avgMarks[highestIndex]) {
            highestIndex = i;
        }
        if (avgMarks[i] < avgMarks[lowestIndex]) {
            lowestIndex = i;
        }
    }

    
    cout << "\nStudent with highest average marks:\n";
    cout << "Roll Number: " << students[highestIndex].rollNo << "\n";
    cout << "Name: " << students[highestIndex].name << "\n";
    cout << "Average Marks: " << fixed << setprecision(2) << avgMarks[highestIndex] << "\n";

    
    cout << "\nStudent with lowest average marks:\n";
    cout << "Roll Number: " << students[lowestIndex].rollNo << "\n";
    cout << "Name: " << students[lowestIndex].name << "\n";
    cout << "Average Marks: " << fixed << setprecision(2) << avgMarks[lowestIndex] << "\n";

    return 0;
}
