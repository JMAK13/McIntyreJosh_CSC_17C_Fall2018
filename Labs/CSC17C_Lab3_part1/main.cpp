/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 19th, 2018, 9:07 PM
 * Purpose:  Mode Setup
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Link.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Link *fillLst(int);
void prntLst(Link *,int);
void dstLst(Link *);
Link *endLst(Link *);
void addLnk(Link *, int);
void delLnk(Link *);
int  findLnk(Link *);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables and initialize Here
    Link *lnkList;
    int howMany=100;
    int perLine=10;
    
    //Print the resulting array
    lnkList=fillLst(howMany);
    
    //Print the list
    prntLst(lnkList,perLine);
    
    //Add to list
    addLnk(lnkList,420);
    
    //Print the list after element appended
    prntLst(lnkList,perLine);
    
    //Delete from list
    delLnk(lnkList);
    
    //Print the list after last element deleted
    prntLst(lnkList,perLine);
    
    //Clean Memory
    dstLst(lnkList);

    //Exit
    return 0;
}
Link *fillLst(int n){
    Link *front=new Link;
    Link *prev=front;
    prev->data=n--;
    prev->linkPtr=NULL;
    do{
        Link *end=new Link;
        end->data=n--;
        end->linkPtr=NULL;
        prev->linkPtr=end;
        prev=end;
    }while(n>0);
    return front;
}
void prntLst(Link *front,int perLine){
    int colCnt=0;
    Link *next=front;
    cout<<endl;
    do{
        cout<<setw(4)<<next->data<<" ";
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->linkPtr;
    }while(next!=NULL);
    cout<<endl;
}
void dstLst(Link *front){
    if(front==NULL)return;
    do{
        Link *temp=front->linkPtr;
        delete front;
        front=temp;
    }while(front!=NULL);
}
Link *endLst(Link *front){
    Link *next=front;
    
    while(next->linkPtr!=NULL)
        next=next->linkPtr;
        
    return next;
    
}
void addLnk(Link *front, int val){
    Link *next;
    Link *newLnk=new Link;
    newLnk->linkPtr=NULL;
    newLnk->data=val;
    if(front==NULL) front=newLnk;
    else{
        next=front;
        while(next->linkPtr!=NULL)
            next=next->linkPtr;
        
        next->linkPtr=newLnk;
    }
}
void delLnk(Link *front){
    Link *next=front;
    
    while(next->linkPtr!=endLst(front))
        next=next->linkPtr;
    
    
    next->linkPtr=NULL;
    delete next->linkPtr;
    
}
int findLnk(Link *link){
    if(link) return link->data;
}