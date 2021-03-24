/*
Author - Nikitha Reddy [Github ID - Nikitha2309]

Introduction 
Given a number determine whether it is even or odd, without using Arithmetic Operators
    
Argument/Return Type
Input of a number is taken , 
Function returns the string "Odd", if it is odd 
and "Even", If it is even
Finally the output is printed
*/

//  Code / Solution

#include <bits/stdc++.h> 
using namespace std;

// Function to determine whether given number is even or odd (using bitwise operator)
string EvenOrOdd(int a)
{
    // Result of any number&1 , will give us the LSB(Least Significant Bit) of k 
    //i.e mathematically , k & 1 = LSB of k

    //A odd number will always have LSB - 1
    //While a even number will have LSB - 0

    if(a&1)  // if a&1 = LSB of a = 1 , then the given number is odd
       return "Odd";
    else     // if a&1 = LSB of a = 0 , then the given number is even
       return "Even";
    
    //return string "Even" if it is even and "Odd" if it is odd
}
int main()
{
    //define int
    int a;
    // Ask input from user
    cout<<"Enter a number : ";
    //Take the input from user
    cin>>a;
    //Print the result by calling the function 
    cout<<"The given number is "<<EvenOrOdd(a);
    return 0;
}
    
/*
Input:
0 <= Number Entered < 1000000000
Sample Test Case      

Input Format : 
Example :
Enter a number : 6723

Output Format :
Example : ( Output to the above input example ) 
The given number is Odd

Time/Space Complexity
Time Complexity : O(1)
Space Complexity : O(1) -  No additional space is required
*/
