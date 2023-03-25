#include <iostream>


using namespace std;


void swap(int* x, int* y) {
       int temp = *x;      // temporary storing value created
       *x = *y;            // swap values
       *y = temp;
}


void bubbleSort(int* a, int size) {


   if(a != nullptr) {      // when function is passed "nullptr" for the value of a, function exits
       for(int i = 0; i < size - 1; i++) {
         for(int j = 0; j < size - i - 1; j++) {
             if(*(a + j) > *(a + j + 1)) {         // if element 2 < element 1
                 swap(*(a + j), *(a + j + 1));     // swap spots
             }
         }
      }
   }   
}


int main(){
   const int SIZE = 5;
   int a1[] = {3, 4, 8, 2, 1};
   int* p = nullptr;


   bubbleSort(a1, SIZE);       // creates the array a1 with the # of elements described in SIZE
  
   for(int i = 0; i < SIZE; i++){      // array is printed in a "for" loop to verify correctly sorted data
       cout << a1[i] << endl;
   }


   bubbleSort(nullptr, SIZE);      // creates a nullptr to pass to the function to test its ability to handle nullptr values being passed
  
   return 0;
}
