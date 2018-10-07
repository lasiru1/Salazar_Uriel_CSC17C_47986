/* 
@file:      main.cpp
@author:    Uriel Salazar
@date:      September 26th, 2018
@section:   47986
@brief:     Combinations and Permutations
 */

//System Libraries
#include <cstdlib>  //General utilites library
#include <iostream> //Input/Output library
#include <fstream>  //File input/output library
#include <math.h>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int factorial(int);
int permWRplc(int, int);
int perm(int, int);
int combWRplc(int, int);
int comb(int);



//Execution begins here
int main()
{
    //Declare variables
    int N = 5;
    int m = 0;
    
    cout << "Permutation with replacement:" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << permWRplc(N, i) << "\n";
    }
    
    
    
    
    
    
    
    

    //Exit program
    return 0;
}

//Factorial Function
int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

//Permutation w/ replacement
int permWRplc(int N, int m)
{
    int result = pow(N, m);
    return result;
}

//Permutation
int perm(int N, int m)
{
    int result = factorial(N) / (factorial(N - m));
    return result;
}

//Combination w/ replacement
int combWRplc(int N, int m)
{
    int result = factorial(N + m -1) / (factorial(N-1) * factorial(m));
    return result;
}

//Combination
int comb(int N, int m)
{
    int result = factorial(N) / (factorial(N-m) * factorial(m));
    return result;
}