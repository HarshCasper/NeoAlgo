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
    if(n == 0 || n == 1)
        return 1;

    fac[0] = 1;
    fac[1] = 1;

    for(int i=2 ; i<=n ; i++)
    {
        fac[i] = i * fac[i-1];
    }
    return(fac[n]);
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


