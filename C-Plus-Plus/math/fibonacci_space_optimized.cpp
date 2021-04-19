//C++ Program to calculate Fibonacci numbers without using recursion
/*
 As we know, Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2). Rather than
 storing each value, we will only store the last and second
 last number of the Fibonacci series.
 Initially we will store first and second value
 and run the loop from third place till the number given.
*/
#include <bits/stdc++.h>
using namespace std;

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
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Fibonacci : "<<Fibonacci(n);
    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)

    Sample Outputs:
    
    Test Case - 1:
    Enter number : 5
    Fibonacci : 5

    Test Case - 2:
    Enter number : 9
    Fibonacci : 34

*/
