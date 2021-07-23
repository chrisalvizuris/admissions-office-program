#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using std::cout;
using std::left;
using std::setw;

using namespace std;

Student::Student() { // empty constructor
    
    this->ID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < numDaysArraySize; ++i) this->numDays[i] = 0;
    
}

Student::Student(string ID, string firstName, string lastName,  string email, int age, int numDays[]) {
    
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < numDaysArraySize; ++i) this->numDays[i] = numDays[i];
   
}

//accessors (getters) for student class

string Student::getID() {

    return ID;
}

string Student::getFirstName() {

    return firstName;
}

string Student::getLastName() {

    return lastName;
}

string Student::getEmail() {

    return email;
}

int Student::getAge() {

    return age;
}

int* Student::getNumDays() {

    return numDays;
}




//mutators (setters) for student class

void Student::setID(string ID) {

    this->ID = ID;
}

void Student::setFirstName(string firstName) {

    this->firstName = firstName;
}

void Student::setLastName(string lastName) {

    this->lastName = lastName;
}

void Student::setEmail(string email) {

    this->email = email;
}

void Student::setAge(int age) {

    this->age = age;
}

void Student::setNumDays(int numDays[]) {

    for (int i = 0; i < numDaysArraySize; ++i)
        this->numDays[i] = numDays[i];
}


//virtual print function to print student data


//destructor for student class
Student::~Student() {
    
    //nothing new is created in this class, so there really isn't anything to destruct
    
}

