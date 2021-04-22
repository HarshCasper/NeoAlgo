#include <bits/stdc++.h>
using namespace std;

/*
 Factorial is calculated using recursive formula : n! = n * (n-1)!
 Iteratively, it can be calculated by multiplying the current product
 by the next number. Initially current product will be 1.
*/
int Factorial(int n)
{
    int prod = 1;
    for(int i=2 ; i<=n ; i++)
    {
        prod *= i;
    }
    return prod;
}

int main()
{
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is : "<<Factorial(n);

    return 0;
}

/*
    Sample Input-Output:
    Enter number : 5
    Factorial of 5 is : 120

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
