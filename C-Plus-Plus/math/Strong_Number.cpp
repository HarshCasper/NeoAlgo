//Strong number is a special number whose sum of factorial of digits is equal to the original number.
//For example: 145 is strong number. Since, 1! + 4! + 5! = 145

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int num, n, factorial=1, sum=0;
    int i, digit;
    cout<<"Enter a number to check whether it is a strong number or not: ";
    cin>>num;
    n=num;
    for(n=num; n>0; n=n/10)
    {
        digit=n%10;     //digit of the number
        if(digit!=0)
        {
            factorial=1;
            for(i=1; i<=digit; i++)
                factorial*=i;    //code for calculating factorial of digits
        }
        else
            digit=1;
        sum+=factorial;     //sum of factorial of digits
    }
    if(sum==num)
        cout<<sum<<" is a strong number."<<endl;
    else
        cout<<num<<" is not a strong number."<<endl;
    return 0;
}

/*
Time Complexity: O(n*9)
Space Complexity: O(1)

sample 1:
Input: Enter a number to check whether it is a strong number or not:  145
Output: 145 is a strong number.
sample 2:
Input: Enter a number to check whether it is a strong number or not: 2
output: 2 is not a strong number.
*/ 
