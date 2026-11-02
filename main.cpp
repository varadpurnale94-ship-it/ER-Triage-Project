
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Patient {
    int id, age, oxygen, pain, priority;
    string name, problem;
};

vector<Patient> patients;

void addPatient() {
    Patient p;
    p.id = patients.size() + 1;

    cout << "\nEnter patient name: ";
    cin >> p.name;
    cout << "Enter age: ";
    cin >> p.age;
    cout << "Enter oxygen level: ";
    cin >> p.oxygen;
    cout << "Enter pain score (1-10): ";
    cin >> p.pain;
    cout << "Enter problem: ";
    cin >> p.problem;

    p.priority = (p.oxygen < 90 ? 100 : 0)
               + (p.pain * 5)
               + (p.age >= 65 ? 20 : 0);

    patients.push_back(p);
    cout << "\nPatient registered successfully!\n";
}

void showPatients() {
    sort(patients.begin(), patients.end(),
         [](Patient a, Patient b) {
             return a.priority > b.priority;
         });

    cout << "\n--- PATIENT PRIORITY QUEUE ---\n";
    for (auto p : patients) {
        cout << "\nID: " << p.id
             << "\nName: " << p.name
             << "\nProblem: " << p.problem
             << "\nPriority Score: " << p.priority
             << "\n";
    }
}

void allocatePatient() {
    if (patients.empty()) {
        cout << "\nNo patients available!\n";
        return;
    }

    sort(patients.begin(), patients.end(),
         [](Patient a, Patient b) {
             return a.priority > b.priority;
         });

    cout << "\nBed allocated to: " << patients[0].name;
    cout << "\nDoctor assigned successfully!\n";

    patients.erase(patients.begin());
}

int main() {
    int choice;

    do {
        cout << "\n===== ER TRIAGE & PATIENT PRIORITY MANAGER =====";
        cout << "\n1. Register Patient";
        cout << "\n2. View Priority Queue";
        cout << "\n3. Allocate Bed and Doctor";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: showPatients(); break;
            case 3: allocatePatient(); break;
            case 4: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
