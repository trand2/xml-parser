// Project:  XML
// Name: Tyler Randolph
// Submitted: 10/3/2019
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying source
// code from any other source, providing source code to another student,
// or leaving my code on a public web site constitutes cheating.
// I acknowledge that  If I am found in violation of this policy this may result
// in a zero grade, a permanent record on file and possibly immediate failure of the class.

/* Reflection (1-2 paragraphs):  I really enjoyed writing this program, but had trouble with throwing the right exceptions. I thought I had to do a whole try, throw, and catch, but all I really needed was runtime_error(exception). I learned about throwing exceptions with runtime_error will stop the program when before when I had a try, throw and catch statement I was having to use exit(0) to end the program. Otherwise it would cotinue to run  */

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <fstream>
#include <vector>


class Employee {
    

public:
    std::string name;
    int id;
    std::string address;
    std::string city;
    std::string state;
    std::string country;
    std::string phone;
    double salary;
    Employee* employee;
    
    
//    enum {ID, NAME, ADDRESS, CITY, STATE, COUNTRY, PHONE, SALARY, NUM_FIELDS}; // bit IDs
//    static std::bitset<NUM_FIELDS> found;
//    static std::string fieldName[NUM_FIELDS];
    
    Employee();
    
    Employee(std::string name, int id, std::string address, std::string city, std::string state, std::string
             country, std::string phone, double salary);
    
    static Employee* fromXML(std::istream&); // Read the XML record from a stream
    void display(std::ostream&) const; // Write a readable Employee representation to a stream
    
//    void checkField(int index);
    
    int compareNoCase(const std::string&, const std::string&);
    
    std::string getName();
    std::string getAddress();
    std::string getCity();
    std::string getState();
    std::string getPhone();
    int getID();
    double getSalary();
    
    
};

#endif /* Employee_hpp */
