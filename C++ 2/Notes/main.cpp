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



