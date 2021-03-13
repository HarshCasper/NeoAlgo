/* C++ Program to find lexicographically largest palindrome subsequence  */

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string S,k,a,m;        
    int i,j,n,c,max;
    cin>>S;
    n=S.size();
    m="a";                               //initialising m with character "a"
    max=0;                               //initialising max with 0
    for(j=0;j<n;j++)
    {
        c=0;                             //initialising c with 0
        for(i=0;i<n;i++)
        {
            a=S[i];                      //assigning value of element with index 'i' to a
            if(a>=m)                     //this is for getting the lexicographically largest element (the one with largest ascii value)
            {
                m=a;                     //this will store a as m if a will be greater than m
            }
        }
    }
    for(i=0;i<n;i++)
    {
        k=S[i];                           //assigning value of element with index 'i' to a 
        if(k==m)
        {
            c++;                          //increament c when we find our lexicographically largest character in string more than one time
            if(c>max)
            {
                max=c;                    //for finding maximum frequency of character
            }
        } 
    }
    cout<<max<<" ";
    for(i=0;i<max;i++)
    {
        cout<<m;                         //printing subsequence of lexicographically largest character as output
    }
    return 0;
}

/* SAMPLE

Testcase 1
INPUT   startling
OUTPUT  2 tt

Testcase 2
INPUT   mississippi
OUTPUT  4 ssss

Testcase 3
INPUT   sausage
OUTPUT  1 u     */

//  Time Complexity is O(n^2)   where n is length of string
//  Space Complexity is O(1)