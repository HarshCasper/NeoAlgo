/*
Given a binary string s and
an integer k.Print True if
every binary code of length
k is a substring of s.
Otherwise, Print False.

Constraints:
1 <= s.length <= 5 * 10^5
s consists of 0's and 1's only.
1 <= k <= 20
*/

#include<bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k) {
        int X,Y,Z,i;
        X=s.length();
        Y=pow(2,k);
        int A[2022600]={0};
        Z=0;
        for(i=0;i<k;i++)
        {
            if(i!=0  &&  Z!=0)
            Z=(Z<<1);
            if(s[i]=='1')
            {
                Z++;
            }
        }
        A[Z]=1;
        for(i=k;i<X;i++)
        {
            if(Z>=(pow(2,k-1)))
                Z-=(pow(2,k-1));
            if(Z!=0)
                Z=(Z<<1);
            if(s[i]=='1')
                Z++;
            A[Z]=1;
        }
        for(i=0;i<Y;i++)
        {
            if(A[i]==0)
                return false;
        }
        return true;
    }
int main()
{
#ifndef ONLINE_JUDGE
  freopen("C:\\Users\\NCS\\Desktop\\Coding_Problems\\Input.txt","r",stdin); 
  freopen("C:\\Users\\NCS\\Desktop\\Coding_Problems\\Ans.txt","w",stdout);
#endif 
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
Time Complexity: O(N)
Space Complexity: O(N)
where N is the length of
the given string.

Sample I/O
Input: s = "00110", k = 2
Output: true
It has "01","11","00","10".
*/
