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
#include "SimpleVector.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare All Variables and Initialize Here
    SimpleVector<int> v(9);
    
    //Print Vector Values
    cout<<"Original Vector:"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v.getElementAt(i)<<" ";
        if((i+1)%5==0) cout<<endl;
    }
    
    //Append Values to Vector
    v.push(9);
    
    //Print Augmented Vector
    cout<<endl<<endl<<"Appended Vector:"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v.getElementAt(i)<<" ";
        if((i+1)%5==0) cout<<endl;
    }
    
    //Delete Last Value of Vector
    v.pop();
    
    //Print Augmented Vector
    cout<<endl<<"Decremented Vector:"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v.getElementAt(i)<<" ";
        if((i+1)%5==0) cout<<endl;
    }
    
    //Exit
    return 0;
}