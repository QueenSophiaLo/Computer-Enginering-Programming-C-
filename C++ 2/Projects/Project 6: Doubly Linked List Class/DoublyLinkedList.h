#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


#include <iostream>


template <typename T> struct node {
 T data;                  // data item
 node<T> *prev;    // a pointer to the previous struct node
 node<T> *next = nullptr; // points to nullptr
};


template <typename T> class DoublyLinkedList {
public:
 DoublyLinkedList();
 ~DoublyLinkedList();
 DoublyLinkedList(DoublyLinkedList<T> &objToCopy);


 void operator=(DoublyLinkedList<T> &objToCopy);


 void push(T data);
 void pop();
 int size();
 void print();
 T &at(int idx);
 void insert(T data, int pos);
 void remove(int pos);
 node<T> *head;
 node<T> *tail;
 int numElements;
};


#endif
