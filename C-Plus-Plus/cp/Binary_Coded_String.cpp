/*
Given a binary string s and an
integer k.
Print True if every binary code
of length k is a substring of s.
Otherwise, Print False.

Constraints:
1 <= s.length <= 5 * 10^5
s consists of 0's and 1's only.
1 <= k <= 20
*/

#include<bits/stdc++.h>
using namespace std;

/*
This Function will check all string 
of length k present in given string 
s or not.
*/

bool hasAllCodes(string s, int k) 
{
    int length,totalBinaryString,Z,i;
    length=s.length();
    totalBinaryString=pow(2,k);
    int A[2022600]={0};
    Z=0;
    for(i=0;i<k;i++)
    {
        if(i!=0  &&  Z!=0)
            Z=(Z<<1);
        if(s[i]=='1')
            Z++;
    }
    A[Z]=1;
    for(i=k;i<length;i++)
    {
        if(Z>=(pow(2,k-1)))
            Z-=(pow(2,k-1));
        if(Z!=0)
            Z=(Z<<1);
        if(s[i]=='1')
            Z++;
        A[Z]=1;
    }
    for(i=0;i<totalBinaryString;i++)
    {
        if(A[i]==0)
            return false;
    }
    return true;
}

int main()
{
    string S;
    int K;
    cout<<"Enter an String"<<endl;
    cin>>S;
    cout<<"Enter the integer"<<endl;
    cin>>K;
    bool Ans=hasAllCodes(S,K);
    if(Ans==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

/*
Time Complexity=O(N)
Space Complexity=O(2^K)
where N is the length of the given 
string and K is the given integer.

Sample Input Output
Input:
Enter an String
00110
Enter the integer
2
Output:
Yes
*/

