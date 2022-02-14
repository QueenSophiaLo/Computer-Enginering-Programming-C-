#include <iostream>

using namespace std;

/*
Write a function ,void sort2(double* p, double* q), 
that receives two pointers and sorts the values to 
which they point. If you callsort2(&x, &y) then x <= y after the call. */
void sort2(double* p, double* q){
	if(*p > *q){
	 double temp = *p;
	 *p = *q;
	 *q = temp;
 }
}

/*
Write a function ,double replace_if_greater(double* p, double x), that 
replaces the value to which p points with x if x is greater. Return the 
old value to which p pointed. 
*/

double replace_if_greater(double* p, double x){
	double oldVal = *p;
 
	if(*p < x){
	*p = x;
 }
 
	 return oldVal;
}
void doubleUp(int* p){
	if(p == nullptr) {
	return;		// null pointer used to indicate that something hasn't been initialized yet
	}
 	*p = *p * 2;
}
int main(){
 	double x = 5.0;
	double y = 1.0;
 
	int a[] = {1, 2, 3};
	cout << a << endl;	// a pointer to the beginning of the array
	cout << &a[0] << endl;	// grabbing the index of the first element of the array
	cout << &a[2] << endl;	// look at index a and do 2*4 bytes off the base address and output it
	cout << *(a + 2) << endl;	// prints out 3
	cout << a[2] << endl;	// prints out 3

        int* p = nullptr;	// null pointer, points to nothing, initialized to null
	
	if(p == nullptr) {

	}


	//sort2(&x, &y);
	double o = replace_if_greater(&x, 10.0);
 
	cout << x << ", " << o << endl;
	return 0;
}

/* Write a function that returns a pointer to the naximum value of an array of floating point data: double* maximum(double* a, int size)
 if size = 0, return nullptr  */

double* maximum(double* a, int size) {
	if(size == 0) {
	return nullptr;	

	double* max = (a + 0);		// initialize max value to whatever the first index was
	for(int i = 0; i < size; i++) {
		if(*max < *(a + i)) {
		max = (a + i);
	}
	}
	
}

int main() {
	double x = 5.0;
	double y = 1.0;

	int a[] = {1, 2, 3};

	cout << maximum(a, 3) << endl;		// address of the index
	cout << *maximum(a, 3) << endl;		// when you dereference it, you can see that 3 is being stored at that location


}

/* Write a function that returns a pointer to the first occurance of the character c in the string "s" or nullptr if there is no match.
 char* find(char s[], char c) 
   */

char* find(char s[], char c) {
	int i = 0;
	bool matchFound = false;
	while(*(s + i) != '\0') {
		if(*(s + i) == c) {
		  break;
		}
	  	i++;
	}
	if(matchfound) {
		return(s + i);
	} else {
	  return nullptr;
	}
}

int main() {
	double x = 5.0;
	double y = 1.0;

	int a[] = {1, 2, 3};

	cout << maximum(a, 3) << endl;	
	cout << *maximum(a, 3) << endl;		

	char s[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	cout << find(s, 'e') << endl;		// outputs "ello", finds the address where 'e' exists and prints out the characters from that address
	cout << (void*) (s, 'e') << endl;	// prints out the address
}
