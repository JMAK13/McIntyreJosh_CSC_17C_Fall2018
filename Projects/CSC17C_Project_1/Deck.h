/* 
 * File:   Deck.h
 * Author: Josh McIntyre
 * Created on May 14, 2018, 6:15 PM
 */

#ifndef DECK_H
#define DECK_H

//Include System Libraries
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <utility>
using namespace std;

//Deck Templated Class
template <class T>
class Deck{
    private:
        T **card;
        vector<int> index;
        map<T,int> data;   //NEW
        static const int nCards=52;
        int delt;
    public:
        //Constructor Taking Number of Cards as Parameter
        Deck();
        
        //Destructor
        ~Deck();
        
        //Card Accessor Member Function
        //T *getCard(int i)const{return card[i];}
        T *getCard(int i);  //NEW
        
        
        //Card Index Accessor Member Function
        //int getI(int i)const{return index[i];}
        int getI(int);  //NEW
        
        //Card Index Mutator Member Function
        void setI(int,int);
        
        //Gets Number of Cards in Deck
        int numCards()const{return nCards;}
        
        //Delt Accessor Member Function
        int getDelt()const{return delt;}
        
        //Delt Mutator Member Function
        inline void setDelt(int i){
            if(i>=0) delt=i;
        };
        
        //Invalid Index Exception
        class InvalidIndex
            {   };
};

//Default Deck Constructor
template <class T>
Deck<T>::Deck(){
    //Sets Default Variable Values
    /*card=new T*[nCards];
    delt=0;
    //Allocates Memory for Cards
    for(int i=0; i<nCards; i++){
        card[i]=new T(i+1);
        index.push_back(i);
    }*/
    
    //NEW
    for(int i=0; i<nCards; i++){
        data[T(i+1)]=i;
    }
    
    typename map<T,int>::iterator it;

    for(it=data.begin(); it!=data.end(); ++it)
        cout<<it->first<<"   "<<it->second<<endl;
}

//Deck Destructor
template <class T>
Deck<T>::~Deck(){
    //Deallocates Memory
    /*for(int i=0; i<nCards; i++)
        delete card[i];
        
    delete []card;*/
    
    //NEW
    data.clear();
}

//Index Mutator Member Function
template <class T>
void Deck<T>::setI(int i, int v){
    //if(i>=0&&v>=0) index[i]=v;
    //else throw InvalidIndex();
    
    //NEW
    if(i>=0&&v>=0){
        typename map<T,int>::iterator it=data.begin();
        
        for(it=data.begin(); it!=data.end(); ++it){
            if(it->second==i) it->second=v;
        }
    }
    else throw InvalidIndex();
}

//NEW
template <class T>
int Deck<T>::getI(int i){
    typename map<T,int>::iterator it;
    int x=0;
    for(it=data.begin(); it!=data.end(); ++it){
        if(x==i) return it->second;
        else x++;
    }
}

template <class T>
T *Deck<T>::getCard(int i){
    typename map<T,int>::iterator it;
    int x=0;
    for(it=data.begin(); it!=data.end(); ++it){
        if(x==i) return it->first;
        else x++;
    }
}
#endif /* DECK_H */

