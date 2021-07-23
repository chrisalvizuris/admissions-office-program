#pragma once
#include "degree.h"
#include <string>

using namespace std;

class Student {
public:
    Student(); //empty constructor
    
    const static int numDaysArraySize = 3;
    
    //full constructor
    Student(string ID, string firstName, string lastName, string email, int age, int numDays[]);
    
    //accessors
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumDays();
    virtual DegreeType getDegreeType() = 0;
    
    //mutators
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(int numDays[]);
    
    virtual void print() = 0;
    
    //destructor
    ~Student();
    
private:
    string ID;
    string firstName;
    string lastName;
    string email;
    int age;
    int numDays[numDaysArraySize];
    
    


};


