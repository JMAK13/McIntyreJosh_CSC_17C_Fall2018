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
        Link<T> *head;
        Link<T> *tail;
    public:
        Link();
        Link(T);
        ~Link();
        T getValue()const{return value;}
        Link<T>* getHead(){return head;}
        Link<T>* getTail(){return tail;}
        void setValue(T);
        void setHead(Link<T> *);
        void delHead();
        void setTail(Link<T> *);
        void delTail();
};

//Default Constructor
template <class T>
Link<T>::Link(){
    value=0;
    head=nullptr;
    tail=nullptr;
}

//Constructor
template <class T>
Link<T>::Link(T v){
    value=v;
    head=nullptr;
    tail=nullptr;
}

//Destructor
template <class T>
Link<T>::~Link(){
    
}

//Value Mutator
template <class T>
void Link<T>::setValue(T v){
    value=v;
}

//Head Link Setter
template <class T>
void Link<T>::setHead(Link<T> *link){
    if(link) head=link;
}

//Head Link Delete
template <class T>
void Link<T>::delHead(){
    if(head) delete head;
}

//Tail Link Setter
template <class T>
void Link<T>::setTail(Link<T> *link){
    if(link) tail=link;
}

//Tail Link Delete
template <class T>
void Link<T>::delTail(){
    if(tail) delete tail;
}

#endif /* LINK_H */

