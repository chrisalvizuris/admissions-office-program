#pragma once
#include <string>
#include <iostream>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"



class Roster {
public:
    
    //empty constructor
    Roster();
    
    //this next constructor does the same as above but sets the max capacity
    Roster(int maxSize);
    
    //commenting out the below unless I find out I really need it
    /*
    Student* getStudentAt(int lastStudentIndex);
     * 
     */
    
    //Used to add students to array
    void parseThenAdd(string datarow);
    
    //sets instance variables and updates roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType);
    
    //removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found
    void remove(string studentID);
    
    //prints a complete tab-separated list of student data using accessor functions
    void printAll();
    
    //prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    void printDaysInCourse(string studentID);
    
    //verifies student email addresses and displays all invalid email addresses to the user
    void printInvalidEmails();
    
    //prints out student info by degree program
    void printByDegreeProgram(DegreeType degreeProgram);
    
    Student* getStudentAt(int index);
    
    //destroyer
    ~Roster();
    
    
private:
    int lastStudentIndex; //index of last student in the roster. This basically records how many entries are in the roster
    int maxSize; //sets the max size of the roster
    Student** classRosterArray; //array of pointers

};



