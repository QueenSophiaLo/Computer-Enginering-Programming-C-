#include "doublylinkedlist.h"


// Extend your class to a "template" class so that you can use any data type,
// rather than just integers to hold data.


template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
 head = nullptr;
 tail = nullptr;
 numElements = 0;
}


// Add a destructor to your class that cleans up any data allocated via "new" to
// prevent memory leaks
template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
 std::cout << "Destructor Called!" << std::endl;
 while (numElements > 0)
   pop();
}


// Add copy constructors
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T> &objToCopy) {
 std::cout << "Copy Constructor Called!" << std::endl;


 head = nullptr;
 tail = nullptr;
 numElements = 0;
 for (int i = 0; i < objToCopy.size(); i++) {
   push(objToCopy.at(i));
 }
}


// overrides the copy assignment operator to prevent shallow copies
template <typename T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> &objToCopy) {
 std::cout << "Copy Assignment Override Called!" << std::endl;


 while (numElements > 0)
   pop();


 for (int i = 0; i < objToCopy.size(); i++) {
   push(objToCopy.at(i));
 }
 return;
}


// appends a new node on the end of the list
template <typename T> void DoublyLinkedList<T>::push(T newData) {
   node<T> *last = tail;
   node<T> *newLast = new node<T>;   // define new node
   newLast->data = newData;      // assigns the new data in node1


   if (head == nullptr) {
     head = newLast;
     tail = newLast;
     numElements++;
     return;
   }


   newLast->prev = tail;
   tail->next = newLast;
   newLast->next = nullptr;
   tail = tail->next;
   numElements++;
   return;
}


// removes the last element of the list
template <typename T> void DoublyLinkedList<T>::pop() {
 // check if list has 0 nodes (do nothing)
 if(numElements == 0) {
   return;
 }


 // check if list has 1 node
 if(numElements == 1) {
   tail = nullptr;
   head = nullptr;    // (set head/tail to default and decrement numElements)
   numElements = 0;
   return;
 }


 // check if list has 2+ nodes
 if(numElements >= 2) {
   node<T> *last = tail->prev;   // define the second to last node on the list
   delete last->next;    // delete the last element off the list
   last->next = nullptr;   // the new last node's "next" points to null
   tail = last;
   numElements--;
   return;
 }
 return;   // just in case ;)
}


// returns the number of elements in the list
template <typename T> int DoublyLinkedList<T>::size() {
   return numElements;
}


// prints all elements in the list to the console
template <typename T> void DoublyLinkedList<T>::print() {
 if(head == nullptr) {return;}         // exits loop when the node points to nullptr (0 nodes)


 node<T> *curr = head;
 while (curr->next != nullptr) {     // when curr->next = nullptr, curr is tail
   std::cout << curr->data << std::endl;
   curr = curr->next;
 }
 std::cout << curr->data << std::endl;        // prints out very last element
 return;
}


// returns a reference to the data at the requested index, "idx"
template <typename T> T &DoublyLinkedList<T>::at(int idx) {
 if(idx > numElements) {
   std::cout << "Index invalid- returning final element." << std::endl;
   return tail->data;    // requested index does not exist
 }


 node<T> *curr = head;
 for (int i = 0; i < idx; i++) {
   curr = curr->next;      // iterate till requested index
 }
 return curr->data;   
}


// insert a node into the list at a given position
template <typename T> void DoublyLinkedList<T>::insert(T newdata, int pos) {
 node<T> *newNode = new node<T>;
 newNode->data = newdata;      // create a new node and populate the data


 // pos is invalid
 if((pos > numElements) || (pos < 0)) {
   std::cout << "Position is out of bounds" << std::endl;
   return;
 }


 // no pre-existing elements in list
 if(numElements == 0) {
   newNode->prev = nullptr;
   head = newNode;
   tail = newNode;
   numElements++;
   return;
 }


 // insert a node at the begining of list
 if(pos == 0) {
     head->prev = newNode;
     newNode->next = head;
     head = newNode;
     head->prev = nullptr;
     numElements++;
     return;
 }


 // insert at end of list
 if(pos == numElements) {
   push(newdata);
   return;
 }


 // insert at middle of list
 if((pos > 0) && (pos < numElements)) {
   node<T> *curr = new node<T>;
   curr = head;
   for(int i = 0; i < pos; i++) {    // iterate till current node (the desired position)
     curr = curr->next;
   }
   newNode->prev = curr->prev;     // insert node before current node
   newNode->next = curr;
   curr->prev->next = newNode;
   curr->prev = newNode;
   numElements++;
   return;
 }
 return;   // just in case ;)
}
 template <typename T> void DoublyLinkedList<T>::remove(int pos) {
 node<T> *nodeX = head;
  // pos does not exist
 if((pos > (numElements - 1)) || (pos < 0)) {
 std::cout << "Position is out of bounds" << std::endl;
 return;
 }


 // pos is the last node in the list
 if(pos == (numElements - 1)) {
   pop();
   return;
 }


 // pos is the head
 if(pos == 0) {
   head = nodeX->next;    // node to be omitted is now before "head"
   head->prev->next = nullptr;
   delete head->prev;
   head->prev = nullptr;
   numElements--;
   return;
 }


 // pos is in the middle of the list
 if((pos > 0) && (pos < numElements - 1)) {
   node<T> *curr = new node<T>;
   curr = head;
   for(int i = 0; i < pos; i++) {    // iterate till current node (the desired position)
     curr = curr->next;
   }
   curr->next->prev = curr->prev;    // redirect pointers to skip current
   curr->prev->next = curr->next;
   curr->next = nullptr;
   curr->prev = nullptr;
   delete curr;
   numElements--;
   return;
 }
 return;   // just in case ;)
}
