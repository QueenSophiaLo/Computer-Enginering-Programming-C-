#include <iostream>
#include <string>   // include the string class (names are strings)
#include <vector>   // I want to use vectors.. so I include the vector class

using namespace std;    // using standard namespace

#define SOME_NUMBER 4

int main()(
    const int LENGTH = 4:
    string names[LENGTH];   // limit of arrays... you are restricted to thie length of an array (cannot be changed)
    double gpa[LENGTH];     // arrays r stupid :(
    

    string name[3];     // creating an array of names

    names[0] = "Sam Shue";      // first place in the array starts at place 0
    gpa[0] = 1.0;
    
    names[1] = "Jack Jackson";      // assigning array values (names are the values)
    gpa[1] = 2.5;
  
    names[2] = "Cleetus Smith";
    gpa[2] = 4.0;
    
    names[3] = "Another Guy";
    gpa[3] = 3.0;

    for(int i = 0; i < 3 ; i++) {
        cout << names[i] << endl;
        cout << gpa[i] << endl;
    }

return 0;
)




#include <iostream>
#include <string>   // a string is a sucession of characters
#include <vector>  

using namespace std;   

#define SOME_NUMBER 4

int main()(
    const int LENGTH = 4:
    vector<string> names;
    vector<double> gpa;

// vector<string> names = {"Samuel Samuelson", Yousef Yousefson", "Phil Cole"};
// vector<double> gpa = {1.0, 2.0, 4.0};    // can allocate values to vectors and arrays

    names.pushback[0] = "Sam Shue";
    gpa.pushback = 1.0;
    
    names.push_back = "Jack Jackson";      
    gpa.push_back = 2.5;
  
    names.push_back = "Cleetus Smith";
    gpa.push_back = 4.0;
    
    names.pop_back();    //  It erases the last element of the vector reducing its length by one
    gpa.pop_back();

    for(int i = 0; i < names.size() ; i++) {    // name.size doesnt have a hardcoded value and can dynamically change to the size of your vecctor
        cout << names.[i] << endl;  // used to access a specific space in the memory
        cout << gpa.at(i) << endl;  // function call used with vectors (this is preferred)
    }
    
    names.push_back("Bob Bobson");    // allows us to push back the vector spaces to insert a new name
    gpa.push_back(3.0);     // vector size for gpas is 5
    
return 0;
)





#include <iostream>
#include <string> 
#include <vector>

using namespace std;   

#define SOME_NUMBER 4

int main()(
    const int LENGTH = 4:
    vector<string> names;
    vector<double> gpa;

    char c = "A"; //char typically holds letters
    char s[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // strings terminated with a null character (\0) to indicate its end

// strings are a character array

    string str = "Hello";   // a character array that the string class holds

    cout << c << endl;
    
    int i = atoi(str.c_str());  // rooting through the string and pulling the first integer it comes across
    cout << i << endl;
    
return 0;
)
