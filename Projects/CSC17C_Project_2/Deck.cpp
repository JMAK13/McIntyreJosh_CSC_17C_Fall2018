/* 
 * File:   Player.cpp
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

//Included System Libraries
#include <iostream>
#include <iterator>
using namespace std;

//Included User Libraries
#include "Deck.h"

//Default Deck Constructor
Deck::Deck(){
    for(int i=0; i<nCards; i++){
        index.push_back(i);
        data.insert(pair<Card,int>(Card(i+1),i) );
    }
}

//Deck Destructor
Deck::~Deck(){
    data.clear();
    index.clear();
}

//Index Mutator Member Function
void Deck::setI(int i, int v){
    if(i>=0&&v>=0) {
        index[i]=v;
    }
    else throw InvalidIndex();
}

//Card Accessor Function
Card Deck::getCard(int i){
    map<Card,int>::iterator it;
    for(it=data.begin(); it!=data.end(); ++it)
        if((it->second)==i) return (it->first);
}
