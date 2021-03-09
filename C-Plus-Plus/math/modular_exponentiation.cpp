#include<bits/stdc++.h>
using namespace std;

/* 
Normal power algorithm would take O(power) time to calculate the answer.
But here we use the fact that every number can be represented in power of 2!
Consider 3^25

Normal calculation = (3*3*... 14 Times)
Modular exponentiation = (3^8)*(3^4)*(3^2)*(3^1)

We use this power of 2s to our advantage.
(3^2)=(3^1)^2
(3^4)=(3^2)^2 
(3^8)=(3^4)^2 
So, this reduces the number of multiplication, as we only need to sqaure the number (squaring is just single multiplication operation).

So, overall
Time Complexity: O(log(power))
Space Complexity: O(1)
*/

long long modular_exponentiation(long long base,long long power,long long mod)
{
    base=base%mod;
    long long answer=1;
    while(power>0)
    {
        if(power%2==1) answer=(answer*base)%mod;
        base=(base*base)%mod;
        power=power/2;
    }
    return answer;
}

int main()
{
    long long base,power,mod;
    cout<<"Enter base: ";
    cin>>base;
    cout<<"Enter power: ";
    cin>>power;
    cout<<"Enter mod: ";
    cin>>mod;
    cout<<"power("<<base<<","<<power<<")%"<<mod<<" = "<<modular_exponentiation(base,power,mod)<<"\n";
}