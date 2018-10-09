// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include "Link.h"    // Linked List infile
using namespace std;

template <class T>
class SimpleVector
{
private:
   Link<T> *start;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { start = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   // Push function to append value to front of vector
   void push(T);
   
   // Pop function to remove last value of vector
   void pop();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    //Initialize Member Variables
    arraySize = s;
    int tmp=s;
    
    //Initialize Vector
    try
    {
        start=new Link<T>(rand()%90+10);
        Link<T> *prev=start;
        do{
            Link<T> *end=new Link<T>(rand()%90+10);
            end->setNext(NULL);
            prev->setNext(end);
            prev=end;
            tmp--;
        }while(tmp>0);
        
    }
    catch (bad_alloc)
    {
       memError();
    }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

//NOTE--> Gives Error in Pop Function !!!!!!!!!!!!!!!!!!!!!
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;
    
    //Copy Vector
    start=obj.start;
    
    if (start == 0)
        memError();
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    Link<T> *tmp=start;
    
    if(!start->getNext()) delete start;
    while(start->getNext()){
        start=start->getNext();
        delete tmp;
        tmp=start;
    }
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    Link<T> *tmp=start;
    
    if (sub < 0 || sub >= arraySize)
       subError();
    for(int i=0; i<sub; i++)
       tmp=tmp->getNext();
    
    return tmp->getValue();
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    Link<T> *tmp=start;
    
    if (sub < 0 || sub >= arraySize)
       subError();
    for(int i=0; i<sub; i++)
       tmp=tmp->getNext();
    
    return tmp->getValue();
}

//*******************************************************
// Push function to add value to front of the vector.   *
//*******************************************************

template <class T>
void SimpleVector<T>::push(T val){
    Link<T> *tmp=start;
    
    arraySize++;
    T tmp2[arraySize]={};
    
    for(int i=0; i<arraySize-1; i++){
        tmp2[i+1]=tmp->getValue();
        tmp=tmp->getNext();
    }
    
    tmp=start;
    
    for(int i=0; i<arraySize; i++){
        tmp->setValue(tmp2[i]);
        tmp=tmp->getNext();
    }
    
    start->setValue(val);
}

//*******************************************************
// Pop function to insert value to front of the vector. *
//*******************************************************

template <class T>
void SimpleVector<T>::pop(){
    Link<T> *tmp=start;
    
    arraySize--;
    
    while(tmp->getNext())
        tmp=tmp->getNext();
    delete tmp->getNext();
}
#endif