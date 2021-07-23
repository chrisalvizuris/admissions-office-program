#include <iostream>
#include <string>
#include "softwareStudent.h"

using namespace std;


SoftwareStudent::SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int numDays[], DegreeType degreeType)
    :Student(ID, firstName, lastName, email, age, numDays)
{
    dType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType(){

    return SOFTWARE;
}

void SoftwareStudent::print(){
    cout << "Student ID: " << getID() << "\t" << endl;
    cout << "First Name: " << getFirstName() << "\t" << endl;
    cout << "Last Name: " << getLastName() << "\t" << endl;
    cout << "Email: " << getEmail() << "\t" << endl;
    cout << "Age: " << getAge() << "\t" << endl;
    cout << "daysInCourse: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << '}' << "\t" << endl;
    cout << "Degree Program: Software\t" << endl;
}


//destroyer
    
SoftwareStudent::~SoftwareStudent() {}


