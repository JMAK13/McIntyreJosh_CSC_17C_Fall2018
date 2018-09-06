/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 3, 2018, 1:17 AM
 */

//Global Constants

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Function Prototypes

//Main Function
int main(int argc, char** argv) {

    //Declare Variables & Arrays
    int xVals[37]={};
    float yVals[37]={};
    int xSum=0,xxSum=0;
    float ySum=0,xySum=0,slope,yIntcpt;
    
    //Map DataFiles to Arrays
    fstream xInput("DegreeF_X.txt",ios::in);
    for(int i=0;i<37;i++){
        xInput>>xVals[i];
        xSum+=xVals[i];
        xxSum+=(xVals[i]*xVals[i]);
    }
    xInput.close();
    
    fstream yInput("DegreeC_Y.txt",ios::in);
    for(int i=0;i<37;i++){
        yInput>>yVals[i];
        ySum+=yVals[i];
        xySum+=(xVals[i]*yVals[i]);
    }
    yInput.close();
    
    //Perform Calculations
    slope=((ySum*xSum/37)-xySum)/((xSum*xSum/37)-xxSum);
    yIntcpt=yVals[0]-(slope*xVals[0]);
    
    //Display Output
    cout<<"Calculated Slope     = "<<slope<<endl;
    cout<<"Calculated Intercept = "<<yIntcpt<<endl;
    
    //Exit Program
    return 0;
}