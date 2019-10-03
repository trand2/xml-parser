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
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include "Employee.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    string fileName;
    string name;
    string line;
    Employee* employee = new Employee;
    
    if (!argv[1]) {
        ifstream file(fileName);
        cout << "No file provided" << endl;
        exit(1);
    }
    
    fileName = argv[1];
    ifstream in(fileName);

    if (!in) {
        cout << "File does not exist" << endl;
        exit(1);
    }
    
    while (!in.eof()) {
        Employee::fromXML(in);
    }
    
//    employee->checkField(Employee::ID);
//    employee->checkField(Employee::NAME);
//
//    Employee::found.reset();
    
    ostream& objOstream = cout;
    
    employee->display(objOstream);
    
}
