Arrays and vectors - when we have a list of a bunch of the same things
the previous example had names and GPAs (vectors are better becuase size is dynamically allocated)
C++ is object oriented (today will be talking about classes in C++)
  
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"

using namespace std;

class Student{    // tells me what a student is
  public:
  string name;
  double gpa;  
  private:
};

int main()(
  
  Student s1;
  s1.name = "Sam Shue";
  s1.gpa = 1.5;

  Student s2;
  s2.name = "Phil Cole';
  s2.gpa = 4.0;
  
  cout << s1.name << endl;
  cout << s1.gpa << endl;
  
  vector<Student>students;  // easiest to put all students in a vector
  students.push_back(s1);
  students.push_back(s2);
  
  for (int i = 0; i < students.size(); i++) {
   cout << (students.at(i)).name << endl; // both of these syntax are acceptable
   cout << students.at(i)gpa << endl;
  }

  // when you declare a variable inside a class, they are private variables so only the class can call on the,
  // they can be declared as public and anything that follows the word "public" will allow those variables to become priate
  
  /*
vector<string> names = {"Samuel Samuelson", Yousef Yousefson", "Phil Cole"};
vector<double> gpa = {1.0, 2.0, 4.0};
    // vector string = major = {"Biology", "CpE", "EE"}  // we can put these into objects and classes :"

    for(int i = 0; i < 3 ; i++) {
        cout << names[i] << endl;
        cout << gpa[i] << endl;
    }
    
    */

return 0;

)
