/* 
@file:      main.C
@author:    Uriel Salazar
@date:      September 9th, 2018
@section:   47986
@brief:     Calculate the slope and intercept of a first order equation.
 */

//System Libraries
#include <cstdlib>  //General utilites library
#include <iostream> //Input/Output library
#include <fstream>  //File input/output library
#include <vector>
#include <iterator>
#include <algorithm>

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here

int main()
{
    //Declare variables
    std::ifstream yIn ("DegreeC_Y.txt", std::ios::in);     //file for y values
    std::ifstream xIn ("DegreeF_X.txt", std::ios::in);     //file for x values
    std::ofstream fOut ("Solutions.txt", std::ios::out);   //file for m and b
    float slope;        //calculated slope
    float yIntercept;   //calculated y-intercept
    float N = 37;       //number of inputs
    float count;        //placeholder variable
    std::vector<float> yValues;     //vector for y values
    std::vector<float> xValues;     //vector for x values
    std::vector<float> xyValues;    //vector for x*y values
    std::vector<float> xxValues;    //vector for x*x values
    float sumY;     //sum of all y values
    float sumX;     //sum of all x values
    float sumXY;    //sum of all x*y values
    float sumXX;    //sum of all x*x values
    
    //Input y values into a vector
    while (yIn >> count)
    {
        yValues.push_back(count);
    }
    
    //Input x values into a vector
    while (xIn >> count)
    {
        xValues.push_back(count);
    }
    
    //Multiply xVector by yVector -> xyVector
    for(int i = 0; i < yValues.size(); i++)
    {
        xyValues.push_back(xValues[i] * yValues[i]);
    }
    
    //Multiply xVector by xVector -> xxVector
    for(int i = 0; i < xValues.size(); i++)
    {
        xxValues.push_back(xValues[i] * xValues[i]);
    }
    
    //Sum all elements within yVector
    for(std::vector<float>::iterator it = yValues.begin();
            it != yValues.end(); ++it)
    {
        sumY += *it;
    }
    
    //Sum all elements within xVector
    for(std::vector<float>::iterator it = xValues.begin();
            it != xValues.end(); ++it)
    {
        sumX += *it;
    }
    
    //Sum all elements within xyVector
    for(std::vector<float>::iterator it = xyValues.begin();
            it != xyValues.end(); ++it)
    {
        sumXY += *it;
    }
    
    //Sum all elements within xxVector
    for(std::vector<float>::iterator it = xxValues.begin();
            it != xxValues.end(); ++it)
    {
        sumXX += *it;
    }
    
    //Perform calculations
    slope = ((sumY * sumX) - (N * sumXY)) / ((sumX * sumX) - (N * sumXX));
    yIntercept = (sumY - (slope * sumX)) / N;
    
    //Output to file
    fOut << "m = " << slope << "\nb = " << yIntercept;
    
    //Close output file
    fOut.close();
    
    //Exit program
    return 0;
}
