#include <iostream>

using namespace std;

int main(){
	int x = 5;		// set x equal to 5
	int* p = &x;		// set p equal to the address of variable x
	cout << p << endl;	// output: 0x7ffe1588e5ac
	
	int x = 5;		// This code does not work
	int* p = x;		// becuase the variable "x" needs a "&" before it
	cout << p << endl;

	int x = 5;
	int* p = &x;
	p = (int*)5;		// to be able to do the above funtions
	cout << p << endl;	// 0x5o
	
	int x = 5;
	int y = 10;
	int* px = (int*)&x;
	int* py = (int*)&y;
	cout << px << endl;
	cout << py << endl;

	long long int x = 5;
	long long int y = 10;
	long long int* px = (long long int*)&x;
	long long int* py = (long long int*)&y;
	cout << px << endl;	// 0x7ffc3e8a09b8
	cout << py << endl;	// 0x7ffc3e8a09c0

	return 0;
}

POINTERS
a special type of variable that "points" to another variable
a pointer accomplishes that by storing the address to another variable
each variable has an adress associated with it

MEMORY AND ADDRESSES
represented by a large block, divided into many seperate regions based on their functions
text- where the program is stored
data and BSS - where global variables are stored
stack - where variables declared within functions are stored
(There are more regions but these are the important ones for now)

STACK
memory is divided into 8-bit sections, each given a number to represent location
this number is the address of that location in memory
these address are represented with 64-bit hex numbers

MEMORY AND ADDRESSES
	int main(){ // x goes into the memory address 
	int x=5;}
when we declare a new variable inside the function, this variable gets stored inside the stack
the location on the stack is automatically assigned (hence automatic variable)
stack starts at a higher address and fills in to lower addresses
"5" took up 4 8-bit locations

these variables get automatically popped on and off the stack as they appear in function calls

POINTER SYNTAX
int*p; // pointer declaration, indicated that this variable hold the address to an int

int x = 5;
int* p = &x; // pulls the value of the variable out and assigns it to p (NOT PASSBY REFERENCE!!)

1) space for "p" is made on the stack
2) the address of "x" gets extracted and assigned to "p"
3) "p" is now pointing to "x"

int x = 5;
int* p = &x; // points to x
*p = 10 + *p; // adds 10 and writes it back to the variable "p" points to
cout << x << endl; // outputs 15... adding 5 to 10 then it writes 15 to x


