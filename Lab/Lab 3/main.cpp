/* 
@file:      main.cpp
@author:    Uriel Salazar
@date:      September 30, 2018
@section:   47986
@brief:     Simple Vector; push and pop functions on a singular linked list
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Link.h"
#include "Stack.h"

//Global Constants (Physics/Mathematics/Conversions)

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv)
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Stack stk;
    
    //Test push and pop functions on linked list
    cout << "Testing the linked list...\n\n";
    for(int i = 0; i < 5; i++)
    {
       stk.push(1 + (rand() % 9)); 
    }
    stk.displayStackInfo();
    for(int j = 0; j < 4; j++)
    {
        stk.pop();
        stk.displayStackInfo();
    }
    for(int i = 0; i < 5; i++)
    {
       stk.push(1 + (rand() % 9)); 
    }
    stk.displayStackInfo();
     for(int j = 0; j < 6; j++)
    {
        stk.pop();
        stk.displayStackInfo();
    }
        
    //Exit program
    return 0;
}