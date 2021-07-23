#pragma once
#include <string>
#include "degree.h"
#include "student.h"


class SecurityStudent : public Student {
public:


    
    //full constructor
    SecurityStudent(string ID, string firstName, string lastName, string email, int age, int numDays[], DegreeType degreeType);

    //virtual method to get degree type (overrides student class)
    DegreeType getDegreeType(); 
    void print(); 

    //destructor
    ~SecurityStudent();
    
private:
        DegreeType dType;

};



