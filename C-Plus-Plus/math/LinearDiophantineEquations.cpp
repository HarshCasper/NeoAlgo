#include <bits/stdc++.h>
using namespace std;
 
// function to find the GCD of two numbers
int gcd(int a, int b)
{
    return (a%b == 0)? abs(b) : gcd(b,a%b);
}
 
//function checks if integral solutions are possible
bool isPossible(int a, int b, int c)
{
    return (c%gcd(a,b) == 0);
}
 
int main()
{
    // First example
    int a = 3, b = 6, c = 9;
    isPossible(a, b, c)? cout << "Possible\n" :
                        cout << "Not Possible\n";
 
    // Second example
    a = 3, b = 6, c = 8;
    isPossible(a, b, c)? cout << "Possible\n" :
                       cout << "Not Possible\n";
 
    // Third example
    a = 2, b = 5, c = 1;
    isPossible(a, b, c)? cout << "Possible\n" :
                       cout << "Not Possible\n";
 
    return 0;
}