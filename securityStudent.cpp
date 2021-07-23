#include <iostream>
#include <string>
#include "securityStudent.h"

using namespace std;


SecurityStudent::SecurityStudent(string ID, string firstName, string lastName, string email, int age, int numDays[], DegreeType degreeType)
    :Student(ID, firstName, lastName, email, age, numDays)
{
    dType = SECURITY;
}

DegreeType SecurityStudent::getDegreeType(){

    return SECURITY;
}

void SecurityStudent::print(){
 cout << "Student ID: " << getID() << "\t" << endl;
    cout << "First Name: " << getFirstName() << "\t" << endl;
    cout << "Last Name: " << getLastName() << "\t" << endl;
    cout << "Email: " << getEmail() << "\t" << endl;
    cout << "Age: " << getAge() << "\t" << endl;
    cout << "daysInCourse: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << '}' << "\t" << endl;
    cout << "Degree Program: Security\t" << endl;
}

//destroyer
    
SecurityStudent::~SecurityStudent() {}
