#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    string name;

public:
    // Constructor to initialize name
    Animal(string n) : name(n) {
        cout << "Animal constructor called. Name: " << name << endl;
    }

    // Function to get name
    string getName() const {
        return name;
    }
};

// Derived class from Animal
class Mammal : public Animal {
protected:
    int numberOfLegs;

public:
    // Constructor chaining to initialize name and numberOfLegs
    Mammal(string n, int legs) : Animal(n), numberOfLegs(legs) {
        cout << "Mammal constructor called. Number of Legs: " << numberOfLegs << endl;
    }

    // Function to get the number of legs
    int getNumberOfLegs() const {
        return numberOfLegs;
    }
};

// Derived class from Mammal
class Dog : public Mammal {
public:
    // Constructor chaining to initialize name and numberOfLegs
    Dog(string n) : Mammal(n, 4) {
        cout << "Dog constructor called." << endl;
    }

    // Function to simulate barking
    void bark() const {
        cout << getName() << " is barking!" << endl;
    }
};

int main() {
    // Creating a Dog object
    Dog dog("Buddy");

    // Accessing members of all classes
    cout << "Name: " << dog.getName() << endl;
    cout << "Number of Legs: " << dog.getNumberOfLegs() << endl;

    // Calling the bark function
    dog.bark();

    return 0;
}
