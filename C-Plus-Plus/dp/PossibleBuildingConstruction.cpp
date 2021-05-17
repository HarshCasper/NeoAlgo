/*
Possible Building Construction

You are given the number of sections with
each section having two plots on either sides 
of the road. Your task is to find all possible ways,
to construct buildings in plots in such a way that there 
is a space present between any two buildings.
*/

#include <bits/stdc++.h>

using namespace std;

//function to find all possible ways,
//to construct buildings
int possibleWays(int n)
{
    int noofwaysBuildings = 1, res, total;
    int noofwaysSpace = 0, lastBuildingCount, lastSpaceCount;

    //if the number of section is 1 then 
    //we have 2 sides, and on one side we can consruct 2 plots so
    // we have total 4 ways that is either building on both sides, 
    //no building on any side, one building on one side, 
    //or one building on other side
    if(n == 1)
    {
        return (4);
    }

    else
    {
       for(int pass = 2; pass < n+1; pass++)
       {
           lastBuildingCount = noofwaysBuildings;
           lastSpaceCount = noofwaysSpace;
           //updating the number of spaces and buildings
           noofwaysBuildings = lastSpaceCount;
           noofwaysSpace = lastBuildingCount + lastSpaceCount;
       }

       //calculating no of ways buildings on each side
        res = noofwaysBuildings + noofwaysSpace;
        //so finall result will be calculated for both the sides
        total = res * res;
        //returning the total result calculated
        return total;
    }
}

int main()
{
    // taking input
    int n;
    cout << "Enter the number of sections : ";
    cin >> n;
    cout << endl;

    //for output
    cout << "Number of ways to construct building are : ";
    cout << possibleWays(n);
    cout << endl;

    return 0;
}

/*
EXAMPLE:--
INPUT--
Enter the number of sections : 3
OUTPUT--
Number of ways to construct building are : 25

i.e. 3 sections means each section can have 5 options 
building-space-building, space-building-space ,
space-space-building, building-space-space, space-space-space,
and each section has 5 other options so output becomes 25

TIME COMPLEXITY -- > O(n)
SPACE COMPLEXITY -- > o(1)
*/
