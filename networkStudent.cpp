#include "networkStudent.h"
#include <iostream>
#include <string>

using namespace std;



NetworkStudent::NetworkStudent(string ID, string firstName, string lastName, string email, int age, int numDays[], DegreeType degreeType)
    :Student(ID, firstName, lastName, email, age, numDays)
{
    dType = NETWORKING;
}

DegreeType NetworkStudent::getDegreeType(){

    return NETWORKING;
}

void NetworkStudent::print(){
    
    
    cout << "Student ID: " << getID() << "\t" << endl;
    cout << "First Name: " << getFirstName() << "\t" << endl;
    cout << "Last Name: " << getLastName() << "\t" << endl;
    cout << "Email: " << getEmail() << "\t" << endl;
    cout << "Age: " << getAge() << "\t" << endl;
    cout << "daysInCourse: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << '}' << "\t" << endl;
    cout << "Degree Program: Network\t" << endl;
}


//destroyer
    
NetworkStudent::~NetworkStudent() {}


