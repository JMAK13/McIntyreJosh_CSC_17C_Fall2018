/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 3, 2018, 8:05 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Link.h"

//Global Constants

//Function Prototypes
Link<int> *endLst(Link<int> *);         //Returns pointer to link at the end of the list
Link<int> *makeLst(int);                //Initializes list with random values
void prntLst(Link<int> *,int);          //Prints list's values
void dlocLst(Link<int> *);              //Deallocates list's memory
Link<int> *findLnk(Link<int> *,int);    //Query's a link and swaps it to beginning of list(prioritizing order)

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function w/ Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int SIZE=30;
    int perLine=10;
    Link<int> *start;
    
    //Initialize Linked List
    start=makeLst(SIZE);
    
    //Display Linked List
    cout<<"Sorted Doubley Linked List:"<<endl;
    prntLst(start,10);
    
    //Get Random Link in List and Search It
    int test=start->getHead()->getHead()->getHead()->getHead()->getValue();
    cout<<"Qeuried Value: "<<test<<endl;
    start=findLnk(start,test);
    
    //Display Prioritized Order Linked List
    cout<<endl<<"Prioritized Order Doubley Linked List:"<<endl;
    prntLst(start,10);
    
    //Deallocate Memory
    dlocLst(start);

    //Exit Program
    return 0;
}

//Returns Pointer to End of List
Link<int> *endLst(Link<int> *start){
    Link<int> *next=start;
    while(next->getHead())
        next=next->getHead();
    
    return next;
}

//Initializes Linked List
Link<int> *makeLst(int n){
    //Initialize First Two Links
    Link<int> *front=new Link<int>(rand()%90+10);
    Link<int> *second=new Link<int>(rand()%90+10);
    
    //Setup First Two Terms In Sorted Order
    if(second->getValue() >= front->getValue()){
                front->setHead(second);
                second->setTail(front);
    }else{
        front->setTail(second);
        second->setHead(front);
        front=front->getTail();
    }
    
    //Decrement by 2(First Two Terms Already Created)
    n-=2;
    do{
        Link<int> *next=new Link<int>(rand()%90+10);
        
        //Check to Insert at Beginning
        if(front->getValue() >= next->getValue()){
            next->setHead(front);
            front->setTail(next);
            front=front->getTail();
        }else{
            //Check to Insert at End
            if(endLst(front)->getValue() <= next->getValue()){
                next->setTail(endLst(front));
                endLst(front)->setHead(next);
            }else{
                //Check to Insert Somewhere Inside List
                Link<int> *temp=front;
                while(temp->getValue() < next->getValue())
                    temp=temp->getHead();
                
                if(temp->getValue() > next->getValue()) temp=temp->getTail();
                next->setHead(temp->getHead());
                next->setTail(temp);
                temp->getHead()->setTail(next);
                temp->setHead(next);
            }
        }
        n--;
    }while(n>0);
    
    return front;
}

//Prints Linked List
void prntLst(Link<int> *start, int perLine){
    int colCnt=0;
    Link<int> *next=start;
    cout<<endl;
    do{
        cout<<next->getValue()<<" ";
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->getHead();
    }while(next);
    cout<<endl;
}

//Deallocates Linked List
void dlocLst(Link<int> *start){
    if(!start)return;
    do{
        Link<int> *temp=start->getHead();
        delete start;
        start=temp;
    }while(start);
}

//Find Link
Link<int> *findLnk(Link<int> *start, int val){
    Link<int> *tmp=start;
    Link<int> *link;
    while(tmp->getValue()!=val) tmp=tmp->getHead();
    link=tmp;
    
    tmp->getTail()->setHead(tmp->getHead());
    tmp->getHead()->setTail(tmp->getTail());

    start->setTail(link);
    link->setHead(start);
    start=start->getTail();
    if(start->getTail()) start->setTail(nullptr);
    
    return start;
}

