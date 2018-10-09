/* 
 * File:   Link.h
 * Author: Josh McIntyre
 * Created on October 3, 2018, 8:08 PM
 */

#ifndef LINK_H
#define LINK_H

//Templated Link Object for Linked Lists
template <class T>
class Link {
    private:
        T value;
        Link<T> *next;
    public:
        Link();
        Link(T);
        ~Link();
        T getValue()const{return value;}
        void setValue(T val){value=val;}
        Link<T>* getNext(){return next;}
        void setNext(Link<T> *newLnk){next=newLnk;}
        void append(Link<T> *);
        void pop();
};

//Default Constructor
template <class T>
Link<T>::Link(){
    value=0;
    next=nullptr;
}

//Constructor
template <class T>
Link<T>::Link(T v){
    value=v;
    next=nullptr;
}

//Destructor
template <class T>
Link<T>::~Link(){
    
}

//Append Function
template <class T>
void Link<T>::append(Link<T> *newLnk){
    Link<T> *tmp=this;
    while(next)
        tmp=tmp->getNext();
    tmp->next=newLnk;
}

//Removal Function
template <class T>
void Link<T>::pop(){
    if(next) next=nullptr;
}

#endif /* LINK_H */

