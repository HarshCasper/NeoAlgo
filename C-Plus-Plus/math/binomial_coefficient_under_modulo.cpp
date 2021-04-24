#include<bits/stdc++.h>
using namespace std;

/*
This algorithm is used to calculate ncr under some mod.
ncr = factorial(n)/(factorial(r)*factorial(n-r))
ncr%mod = factorial(n)*inverse(factorial(r))%mod*inverse(factorial(n-r)%mod)%mod (here inverse is modinverse)

We use Fermat's little theorem to calculate modinverse of a value
According to Fermat's little theorem 
num^(p-1)=1(mod p)
Multiplying by side by num^-1, we get
num^(p-2)=num^-1(mod p)

So, to get inverse, we need to calulate (mod-2)th power of num under modulo mod.
*/

long long inverse(long long val,long long mod)
{
    long long power=mod-2;
    long long answer=1;
    while(power>0)
    {
        if(power%2==1)
        {
            answer=(answer*val)%mod;
        }
        val=(val*val)%mod;
        power=power/2;
    }
    return answer;
}

long long ncr(long long n,long long r,long long mod)
{
    long long facn,facr,facnr;
    long long curr_value=1;
    for(int i=1;i<=n;++i)
    {
        curr_value=curr_value*i;
        if(i==n)
        {
            facn=curr_value;
        }
        if(i==r)
        {
            facr=curr_value;
        }
        if(i==n-r)
        {
            facnr=curr_value;
        }
    }
    long long answer=facn*inverse(facr,mod)%mod*inverse(facnr%mod,mod)%mod;
    return answer;
}

int main()
{
    long long n,r,mod;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Enter value of r: ";
    cin>>r;
    cout<<"Enter value of mod: ";
    cin>>mod;
    cout<<"ncr%mod = "<<ncr(n,r,mod)<<"\n";
}

/*
Sample I/0

1. 
    INPUT 
    Enter value of n: 3
    Enter value of r: 2
    Enter value of mod: 1
    OUTPUT
    ncr%mod = 0
2.
    INPUT
    Enter value of n: 11
    Enter value of r: 7 
    Enter value of mod: 13
    OUTPUT
    ncr%mod = 5
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

