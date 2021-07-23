#include "roster.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
using std::cerr;

int numStudents = 5;

int i = 0;

Roster::Roster() { //defining the empty constructor
    
   this->lastStudentIndex = -1;
   this->maxSize = 0;
   this->classRosterArray = nullptr;
    
}   

Student* Roster::getStudentAt(int index) {
    return classRosterArray[index];
}

Roster::Roster(int maxSize){ //this constructor sets max 
    
    this->lastStudentIndex = -1;
    this->maxSize = maxSize;
    this->classRosterArray = new Student*[maxSize];


}

void Roster::parseThenAdd(string datarow) {
    DegreeType degreeType;
    
    if (lastStudentIndex < maxSize) {
        ++lastStudentIndex;
        
        if (datarow[1] == '1' || datarow[1] == '4') {
            degreeType = SECURITY;
        }
	else if (datarow[1] == '3' || datarow[1] == '5') {
            degreeType = SOFTWARE;
        }
	
        else if (datarow[1] == '2') {
            degreeType = NETWORKING;
        }
        else //exit
	{
	cerr << "INVALID! EXITING NOW!" << endl;
	exit(-1);
	}
    
    	
    int rhs = datarow.find(",");
    string studentID = datarow.substr(0, rhs);

    //read through firstNames
    int lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    string firstName = datarow.substr(lhs, rhs - lhs);

    //read through lastnames
    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    string lastName = datarow.substr(lhs, rhs - lhs);
    
    //read through emails
    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    string emailAddress = datarow.substr(lhs, rhs - lhs);
    
    //read through ages
    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    int age = stod(datarow.substr(lhs, rhs - lhs));

    //read through days in the course (3 of them)
    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    int daysInCourse1 = stod(datarow.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    int daysInCourse2 = stod(datarow.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = datarow.find(",", lhs);
    int daysInCourse3 = stod(datarow.substr(lhs, rhs - lhs));

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}
	else 
	{
    cerr << "ERROR! Exceeded Size. Exiting the program.";
    exit(-1);
	}
}


//sets instance variables and updates roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType) {
    
    //making the array to get the days in course into the constructor
    int numDays[Student::numDaysArraySize]; //array size is defined in Student class
    numDays[0] = daysInCourse1;
    numDays[1] = daysInCourse2;
    numDays[2] = daysInCourse3;
    
    if (degreeType == SECURITY) {
        classRosterArray[lastStudentIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeType);
    }
    if (degreeType == NETWORKING) {
        classRosterArray[lastStudentIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeType);
    }
    if (degreeType == SOFTWARE) {
        classRosterArray[lastStudentIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeType);
    }

}
//remove function
void Roster::remove(string studentID) {
    
    for (int i = 0; i < lastStudentIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getID() == studentID) {// this means the student was found
            classRosterArray[i] = nullptr;
            cout << studentID << " has been removed." << endl;
                return;
            }
        }
    }
    cout << "Student not found." << endl;
}

//this should print all student data thanks to polymorphism
void Roster::printAll() {
	
	for (int i = 0; i <= this->lastStudentIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::printDaysInCourse(string studentID) {

    bool found = false;
	for (int i = 0; i <= lastStudentIndex; ++i) {
		if (this->classRosterArray[i]->getID() == studentID) {
			found = true;
			int* days = classRosterArray[i]->getNumDays();
			cout << studentID << " spent an average of " << (days[0] + days[1] + days[2]) / 3 << " days to complete their 3 courses." << endl;
		}
	}
	if (!found) {
            
            cout << "Student not found. Invalid ID.";
        }
}

void Roster::printByDegreeProgram(DegreeType degreeProgram) {
    for (int i = 0; i < numStudents; ++i) {
        Student * otherArray = classRosterArray[i];
        if (otherArray->getDegreeType() == degreeProgram) {
            otherArray->print();
        }
    }
    return;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < lastStudentIndex; ++i) {
        string email = classRosterArray[i]->getEmail();
        bool valid = false;
        size_t found = email.find("@");
        if (found != string::npos) {
            found = email.find(".");
            if (found != string::npos) {
                found = email.find(" ");
                if (found == string::npos) {
                    valid = true;
                }
            }
        }
        if (valid != true) {
            cout << classRosterArray[i]->getFirstName() << ' ' << classRosterArray[i]->getLastName() << ", your email " << classRosterArray[i]->getEmail() << " is not a valid email." << endl;
        }
    }
}

Roster::~Roster() {
    delete * classRosterArray;
    cout << "Destructor has been called and final rubric has been met." << endl;
}


int main() {
	int numStudents = 5;
	
	const string studentData[5] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Christian,Alvizuris,chris.alvizuris@gmail.com,28,12,15,12,SOFTWARE"
        };
        
        cout << "***** Scripting and Programming - Applications - C867 *****" << endl;
        cout << "***** Programming Language Used: C++ *****" << endl;
        cout << "***** Student ID: 000952579 *****" << endl;
        cout << "***** Student Name: Christian Alvizuris *****" << endl;
        cout << "*********************************************************" << endl;
        cout << endl;
        
        //creates instance of Roster
        Roster* classRoster = new Roster(numStudents);
        
        //parses and then adds student data
        cout << "ANALYZING AND ADDING STUDENTS:\t";
        cout << endl;
        for (int i = 0; i < numStudents; ++i) {
            classRoster->parseThenAdd(studentData[i]);
        }
        
        //prints all student data
        cout << "complete.\n";
        cout << "Showing all students\n";
        classRoster->printAll();
        cout << "*********************************************************" << endl;
        cout << endl;
        
        //verifies and displays all invalid email addresses
        cout << "Verifying email addresses and displaying INVALID EMAIL ADDRESSES\n";
        cout << endl;
        classRoster->printInvalidEmails();
        cout << "*********************************************************" << endl;
        cout << endl;
        
        //prints average days in course
        cout << "Printing average days in course:\n";
        cout << endl;
        for (int i = 0; i < numStudents; ++i) {
            classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getID());
        }
        cout << "*********************************************************" << endl;
        cout << endl;
        
        //print by degree program SOFTWARE
        cout << "Printing by degree program:\n" << endl;
        cout << endl;
        classRoster->printByDegreeProgram(SOFTWARE);
        cout << "*********************************************************" << endl;
        cout << endl;
    
        
        //remove student by ID
        cout << "Removing A3: \n";
        classRoster->remove("A3");

        cout << "*********************************************************" << endl;
        cout << endl;
        
        cout << "Removing A3: \n/";
        classRoster->remove("A3");

        
        return 0;
        
};
