/*Problem: Given a number, find the number of digits in its factorial
[For large numbers]Using Kamenetsky’s formula: f(x) = log10(((n/e)^n) * sqrt(2*pi*n))
Using log properties: f(x) = n*log10((n/e)) + log10(2*pi*n)/2 
*/
#include <bits/stdc++.h>
using namespace std;
 
//A function to calculate number of digits in factorial
long long factDigit(int num)
{
    // for n>=0, calculate factorial
    if (num < 0)
        return 0;
    if (num <= 1)
        return 1;
    //calculate digits,where M_E=2.71828182845904523536 and M_PI=3.14159265358979323846 are defined constants
    double digit = ((num * log10(num / M_E) + log10(2 * M_PI * num) / 2.0));
    return floor(digit) + 1;
}

int main()
{
    int number;
    cout<<"Enter number,to find no. of digits in its factorial:  ";
    cin>>number;
    cout <<number<<" factorial has " <<factDigit(number) <<" digits"<< endl;
    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)

Sample Test Case:
Enter number,to find no. of digits in its factorial: 101
101 factorial has 160 digits

*/
