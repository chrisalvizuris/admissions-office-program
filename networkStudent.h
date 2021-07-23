#pragma once
#include <string>
#include "degree.h"
#include "student.h"


class NetworkStudent : public Student {
public:


    
    //full constructor
    NetworkStudent(string ID, string firstName, string lastName, string email, int age, int numDays[], DegreeType degreeType);

    //virtual method to get degree type (overrides student class)
    DegreeType getDegreeType(); 
    void print(); 

    //destructor
    ~NetworkStudent();

    private: 
        DegreeType dType;
};



