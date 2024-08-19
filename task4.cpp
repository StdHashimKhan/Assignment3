#include <iostream>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    string address;

public:
    // Constructor to initialize name and address
    Person(string n, string a) : name(n), address(a) {
        cout << "Person constructor called. Name: " << name << ", Address: " << address << endl;
    }

    // Function to display person details
    void displayPersonInfo() const {
        cout << "Name: " << name << ", Address: " << address << endl;
    }
};

// Base class Employee
class Employee {
protected:
    int employeeID;
    double salary;

public:
    // Constructor to initialize employeeID and salary
    Employee(int id, double sal) : employeeID(id), salary(sal) {
        cout << "Employee constructor called. Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }

    // Function to display employee details
    void displayEmployeeInfo() const {
        cout << "Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }
};

// Derived class Teacher inheriting from both Person and Employee
class Teacher : public Person, public Employee {
private:
    string subject;

public:
    // Constructor chaining to initialize name, address, employeeID, salary, and subject
    Teacher(string n, string a, int id, double sal, string subj)
        : Person(n, a), Employee(id, sal), subject(subj) {
        cout << "Teacher constructor called. Subject: " << subject << endl;
    }

    // Function to display teacher details
    void displayTeacherInfo() const {
        displayPersonInfo();
        displayEmployeeInfo();
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    // Creating a Teacher object
    Teacher teacher("John Doe", "123 Maple St", 1001, 55000.0, "Mathematics");

    // Accessing members of all classes
    cout << "\nTeacher's Full Details:" << endl;
    teacher.displayTeacherInfo();

    return 0;
}
