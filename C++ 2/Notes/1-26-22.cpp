#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"

using namespace std;

class Student{
  public:
    void setGpa(double num){     // called a mutator (mutates the value)
        if(num < 0.0) {         // getters
            num = 0.0;
        }
        if(num > 4.0) {
            num = 4.0;
        }    
        gpa = num;
    }

    void setName(string n){     // set the function name as the thing you're trying to mutate for easy readability
        name = n;
    }
    
    double getGpa() const {     // constant functions are not allowed to modify data
        return gpa;
    }
    
    string getName() const {
        // name = "this is a bug"     a constant function doesn't allow you to change anything, prevents accidental rewriting
        return name;
    }
    
  private:
  string name;
  double gpa;
  
};

int main(){
  
  Student s1;
  s1.setName(Sam Shue);
  s1.setGpa(1.5);

  Student s2;
  s2.setName(Phil Cole);
  s2.setGpa(4.0);
  
  vector<Student>students;
  students.push_back(s1);
  students.push_back(s2);
  
  for (int i = 0; i < students.size(); i++) {
   cout << (students.at(i)).getName() << endl; // both of these syntax are acceptable
   cout << (students.at(i)).getGpa() << endl;
  }
 
return 0;
}



look at posted code online




#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"
#include "student.h"


using namespace std;

int main(){
  
  Student s1;
  s1.setName(Sam Shue);
  s1.setGpa(1.5);

  Student s2;
  s2.setName(Phil Cole);
  s2.setGpa(4.0);
  
  vector<Student>students;
  students.push_back(s1);
  students.push_back(s2);
  
  for (int i = 0; i < students.size(); i++) {
   cout << (students.at(i)).getName() << endl; // both of these syntax are acceptable
   cout << (students.at(i)).getGpa() << endl;
  }
 
return 0;
}
