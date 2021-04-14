//C++ Program to calculate Fibonacci numbers without using recursion
#include <bits/stdc++.h>
using namespace std;

// We will only store the last and second last number
// as Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
// initially we will store first and second value i.e. 1
// and run the loop from third place till the number given
int Fibonacci(int n)
{
    int a = 1 , b = 1 , sum , i;

    for(i=2 ; i<n ; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main()
{
    int n = 5;
    cout<<"Fibonacci : "<<Fibonacci(5);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)

    Outputs:
    when n=9 --> Fibonacci : 34
    when n=5 --> Fibonacci : 5
*/
