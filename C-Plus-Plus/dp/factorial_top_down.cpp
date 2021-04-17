#include <bits/stdc++.h>
using namespace std;

/*
 Factorial is calculated using recursive formula : n! = n * (n-1)!
 We will initially save Factorial of 0 and 1 as 1. Then  we will
 recursively call Factorial on the lower numbers and save its data in array
*/
int fac[100];
int Factorial(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if(fac[n] != 0)
        return fac[n];
    return (fac[n] = n * Factorial(n-1));
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
    Space Complexity: O(n)
*/
