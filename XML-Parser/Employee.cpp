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

#include "Employee.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

vector < unique_ptr < Employee > > employeeVector;

Employee::Employee() {
  name = "";
  id = 0;
  address = "";
  city = "";
  state = "";
  country = "";
  phone = "";
  salary = 0.0;

}

Employee::Employee(string name, int id, string address = "", string city = "", string state = "", string country = "", string phone = "", double salary = 0.0) {

  

  employee->name = name;
  employee->id = id;
  employee->address = address;
  employee->city = city;
  employee->state = state;
  employee->country = country;
  employee->phone = phone;
  employee->salary = salary;
    
}

Employee * Employee::fromXML(istream & is) {
  string data = "";
  string tag = "";
  string exception = "";
  Employee * employee1 = new Employee;
  unique_ptr < Employee > newEmployee(new Employee);
  bool idExist = false;
  bool nameExist = false;
  bool employeeTagExist = false;
  bool employeeClosingTagExist = false;

  getline(is, data, '<');
  getline(is, tag, '>');
    
    if (employee1->compareNoCase(tag, "employee") != 0 && tag != "") {
      throw runtime_error("Missing <Employee> tag");
    } else {
      employeeTagExist = true;
    }

    while (is) {
        
      getline(is, data, '<');
      getline(is, tag, '>');
        
      if (employee1->compareNoCase(tag, "/employee") == 0) {
        employeeClosingTagExist = true;
        break;
          
      } else if (employee1->compareNoCase(tag, "salary") == 0) {
        getline(is, data, '<');
        if (newEmployee->salary != 0.0) {
          exception = "Multiple <Salary> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->salary = stod(data);
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/salary") != 0) {
          exception = "Missing </Salary> tag\n";
          throw runtime_error(exception);
        }
      } else if (employee1->compareNoCase(tag, "name") == 0) {
        getline(is, data, '<');
        if (newEmployee->name != "") {
          exception = "Multiple <Name> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->name = data;
          employee1->name = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/name") != 0) {
          exception = "Missing </Name> tag";
          throw runtime_error(exception);
        }
        nameExist = true;
      } else if (employee1->compareNoCase(tag, "id") == 0) {
        getline(is, data, '<');
        if (newEmployee->id != 0) {
          exception = "Multiple <Id> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->id = stoi(data);
          employee1->id = stoi(data);
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/id") != 0) {
          exception = "Missing </Id> tag\n";
          throw runtime_error(exception);
        }
        idExist = true;
      } else if (employee1->compareNoCase(tag, "address") == 0) {
        getline(is, data, '<');
        if (newEmployee->address != "") {
          exception = "Multiple <Address> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->address = data;
          employee1->address = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/address") != 0) {
          exception = "Missing </Address> tag\n";
          throw runtime_error(exception);
        }
      } else if (employee1->compareNoCase(tag, "city") == 0) {
        getline(is, data, '<');
        if (newEmployee->city != "") {
          exception = "Multiple <City> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->city = data;
          employee1->city = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/city") != 0) {
          exception = "Missing </City> tag\n";
          throw runtime_error(exception);
        }
      } else if (employee1->compareNoCase(tag, "state") == 0) {
        getline(is, data, '<');
        if (newEmployee->state != "") {
          exception = "Multiple <State> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->state = data;
          employee1->state = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/state") != 0) {
          exception = "Missing </State> tag\n";
          throw runtime_error(exception);
        }
      } else if (employee1->compareNoCase(tag, "country") == 0) {
        getline(is, data, '<');
        if (newEmployee->country != "") {
          exception = "Multiple <Country> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->country = data;
          employee1->country = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/country") != 0) {
          exception = "Missing </Country> tag\n";
          throw runtime_error(exception);
        }
      } else if (employee1->compareNoCase(tag, "phone") == 0) {
        getline(is, data, '<');
        if (newEmployee->phone != "") {
          exception = "Multiple <Phone> tags\n";
          throw runtime_error(exception);
        }
        newEmployee->phone = data;
          employee1->phone = data;
        getline(is, tag, '>');
        if (employee1->compareNoCase(tag, "/phone") != 0) {
          exception = "Missing </Phone> tag\n";
          throw runtime_error(exception);
        }
      } else if (tag == "") {
        continue;
      } else {
        exception = "Invalid tag: <" + tag + ">\n";
        throw runtime_error(exception);
      }
    }
  

  if (tag == "") {
    return nullptr;
  }

  if (employeeClosingTagExist == false) {
      throw runtime_error("Missing </Employee> tag");
  } else if (employeeTagExist == false) {
      throw runtime_error("Missing <Employee> tag");
  } else if (nameExist == false) {
    throw runtime_error("Missing <Name> tag");
  } else if (idExist == false) {
    throw runtime_error("Missing <Id> tag");
  }

  employeeVector.push_back(move(newEmployee));

  return employee1;
}

void Employee::display(ostream & os) const {
  int vectorSize = (int) employeeVector.size();
  for (int i = 0; i < vectorSize; i++) {
    os << "id: " << employeeVector[i]->id << endl;
    os << "name: " << employeeVector[i]->name << endl;
    os << "address: " << employeeVector[i]->address << endl;
    os << "city: " << employeeVector[i]->city << endl;
    os << "state: " << employeeVector[i]->state << endl;
    os << "country: " << employeeVector[i]->country << endl;
    os << "phone: " << employeeVector[i]->phone << endl;
    os << "salary: " << employeeVector[i]->salary << endl;
    os << endl;
    os.flush();
  }

}

int Employee::compareNoCase(const string& s1, const string& s2) {
   #if defined(_WIN32)
        return _stricmp(s1.c_str(), s2.c_str());
   #elif defined(__GNUC__)
      return strcasecmp(s1.c_str(), s2.c_str());
   #else
       #error Unsupported compiler.
  #endif

}

// Static initialization for Employee
//bitset<Employee::NUM_FIELDS> Employee::found;
//
//string Employee::fieldName[NUM_FIELDS] {
//    "ID", "Name", "Address", "City","State", "Country", "Phone", "Salary"
//};
//
//void Employee::checkField(int index)
//{
//    if (Employee::found.test(index))
//        cout << "field " << Employee::fieldName[index] << " was already found" << endl;
//    else
//        Employee::found.set(index); //if not found already, set bit
//}

string Employee::getName() {
  return name;
};
string Employee::getAddress() {
  return address;
};
string Employee::getCity() {
  return city;
};
string Employee::getState() {
  return state;
};
string Employee::getPhone() {
  return phone;
};
int Employee::getID() {
  return id;
};
double Employee::getSalary() {
  return salary;
};
