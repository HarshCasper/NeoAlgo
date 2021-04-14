//C++ Program to calculate Fibonacci numbers without using recursion
#include <bits/stdc++.h>
using namespace std;

/*
 Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2). Rather than
 string each value, we will only store the last and second
 last number of the Fibonacci series.
 Initially we will store first and second value i.e. 1
 and run the loop from third place till the number given.
*/

int Fibonacci(int n)
{
    int a=1, b=1, sum=0;

    for(int i=2; i<n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<"Fibonacci : "<<Fibonacci(n);
    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)

    Sample Inputs and Outputs:

    (Input)  5
    (Output) Fibonacci : 5

    (Input)  9
    (Output) Fibonacci : 34
*/

