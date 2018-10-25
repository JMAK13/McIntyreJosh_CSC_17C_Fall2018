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
#include "Player.h"

//Default Player Constructor
Player::Player(){
    isPl=true;
    name="Player Name";
    inHand=0;
    maxHand=52;
    for(int i=0; i<maxHand; i++)
        hand.push_back(-1);
}

//Overloaded Player Constructor
Player::Player(string s){
    isPl=true;
    name=s;
    inHand=0;
    maxHand=52;
    for(int i=0; i<maxHand; i++)
        hand.push_back(-1);
}

//Player Copy Constructor
Player::Player(Player &player){
    name=player.name;
    hand=player.hand;
    inHand=player.inHand;
}

//Player Destructor
Player::~Player(){
    hand.clear();
}

//Index Mutator Member Function
void Player::setHand(int i, int v){
    list<int>::iterator it = hand.begin();
    if(i>=0){
        advance(it, i);
        *it=v;
    }
    else throw Player::BadIndex();
}

//Counts Indexes in Player's List
int Player::cntHand(){
    list<int>::iterator it;
    int count=0;
    for(it=hand.begin(); it!=hand.end(); ++it){
        if(count==52) return count;
        else if((*it)>=0) count++;
    }
        
    return count;
}

//Gets Index at Top of Player's List
int Player::getTop(){
    for(int i=0; i<maxHand; i++)
        if(getHand(i+1)==-1) return getHand(i);
}

//Sets Index at Top of Player's Vector to -1
void Player::setTop(){
    for(int i=0; i<maxHand; i++){
        try{
            if(getHand(i+1)==-1) setHand(i,-1);
        }
        catch(Player::BadIndex){
            std::cout<<"Invalid index has been entered.\n";
        }
    }
}

//Moves Top Card of Player's Hand to Bottom
void Player::toBot(int c){
    hand.push_front(c);
}
