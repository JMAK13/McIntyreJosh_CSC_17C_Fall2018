/* 
 * File:   Card.cpp
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

//Include System Libraries
#include <vector>

//Include User Libraries
#include "AbstractCard.h"
#include "Card.h"
using namespace std;

//Default Card Constructor
Card::Card() : AbstractCard(){
}

//Overloaded Card Constructor
Card::Card(int v) : AbstractCard(){
    if(v<0) throw Card::NegativeValue();
    if(v<=13&&v>=1) data.first=v;
    else {v%=13; v==0?data.first=13:data.first=v;}
}

//Card Copy Constructor
Card::Card(Card &card){
    data.second=card.data.second;
    data.first=card.data.first;
}

//Card Destructor
Card::~Card(){
}

//Suit Mutator Member Function
void Card::setSuit(string s){
    int tmp=1;
    vector<string> array{"Spades","Clubs","Hearts","Diamonds"};
    if(s!=array[0]&&s!=array[1]&&s!=array[2]&&s!=array[3]) throw Card::InvalidSuit();
    for(auto it=array.begin();it<array.end();it++){
        if(s.compare(*it)==0) data.second=s;
    }
}

//Value Mutator Member Function
void Card::setVal(int v){
    if(v<0) throw Card::NegativeValue();
    if(v<=13&&v>=1) data.first=v;
    else {v%=13; v==0?data.first=13:data.first=v;}
}

//Name Accessor Member Function
string Card::getName(int v){
    if(v<1) throw Card::NegativeValue();
    string s;
    if(v==1)s="Ace";
    else if(v==2)s="Two";
    else if(v==3)s="Three";
    else if(v==4)s="Four";
    else if(v==5)s="Five";
    else if(v==6)s="Six";
    else if(v==7)s="Seven";
    else if(v==8)s="Eight";
    else if(v==9)s="Nine";
    else if(v==10)s="Ten";
    else if(v==11)s="Jack";
    else if(v==12)s="Queen";
    else if(v==13)s="King";
    return s;
}

//Overloaded > Operator Function
bool Card::operator > (const Card &right){
    if(data.first==right.getVal()) return false;
    else if(data.first==1&&right.getVal()>1) return true;
    else if(data.first>1&&right.getVal()==1) return false;
    else return data.first>right.getVal();
}

//Overloaded < Operator Function
bool Card::operator < (const Card &right){
    if(data.first==right.getVal()) return false;
    else if(data.first==1&&right.getVal()>1) return false;
    else if(data.first>1&&right.getVal()==1) return true;
    else return data.first<right.getVal();
}

//Overloaded == Operator Function
bool Card::operator == (const Card &right){
    if(data.first==right.getVal()) return true;
    else return false;
}
