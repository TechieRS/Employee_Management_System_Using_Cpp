#include <iostream>
using namespace std;

class Employee {
private:
    int employeeID;
    string name;
    double salary;

public:
    Employee() {
        employeeID = 0;
        name = "";
        salary = 0.0;
    }

    Employee(int id, string empName, double empSalary) {
        employeeID = id;
        name = empName;
        salary = empSalary;
    }

    ~Employee() {
        cout << "Employee object destroyed" << endl;
    }

    void setEmployeeID(int id) {
        employeeID = id;
    }

    void setName(string empName) {
        name = empName;
    }

    void setSalary(double empSalary) {
        salary = empSalary;
    }

    int getEmployeeID() {
        return employeeID;
    }

    string getName() {
        return name;
    }

    double getSalary() {
        return salary;
    }

    void display() {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        cout << "1. Add New Employee\n2. Display Employee Details\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < MAX_EMPLOYEES) {
                int id;
                string name;
                double salary;
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Salary: ";
                cin >> salary;
                employees[count] = Employee(id, name, salary);
                count++;
            } else {
                cout << "Employee storage full." << endl;
            }
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                employees[i].display();
            }
        }
    } while (choice != 3);
    
    return 0;
}
