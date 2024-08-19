#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    string name;
    int roll_number;
    float marks;

public:
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_number;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << ", Roll Number: " << roll_number << ", Marks: " << marks << endl;
    }

    int getRollNumber() {
        return roll_number;
    }

    void setMarks(float new_marks) {
        marks = new_marks;
    }
};

int main() {
    const int numberOfStudents = 5;
    Student students[numberOfStudents];

    ofstream outFile("students.txt", ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Enter details for 5 students:" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        students[i].input();
        outFile.write((char*)&students[i], sizeof(students[i]));
    }
    outFile.close();

    ifstream inFile("students.txt", ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nStudent data from file:" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        inFile.read((char*)&students[i], sizeof(students[i]));
        students[i].display();
    }
    inFile.close();

    fstream file("students.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int targetRollNumber;
    float newMarks;
    cout << "\nEnter the roll number of the student whose marks you want to modify: ";
    cin >> targetRollNumber;
    cout << "Enter the new marks: ";
    cin >> newMarks;

    for (int i = 0; i < numberOfStudents; i++) {
        file.read((char*)&students[i], sizeof(students[i]));
        if (students[i].getRollNumber() == targetRollNumber) {
            students[i].setMarks(newMarks);
            file.seekp(-sizeof(students[i]), ios::cur);
            file.write((char*)&students[i], sizeof(students[i]));
            cout << "Marks updated successfully!" << endl;
            break;
        }
    }

    file.close();
    return 0;
}
