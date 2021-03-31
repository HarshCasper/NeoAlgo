/*
Given a non-empty string containing
an out-of-order English representation
of digits 0-9, output the digits in 
ascending order.
Note:
Input contains only lowercase English
letters.
Input is guaranteed to be valid and 
can be transformed to its original 
digits.That means invalid inputs such
as "abc" or "zerone" are not permitted.
*/

#include<bits/stdc++.h>
using namespace std;

string EnglishToDigit(string English)
{
	long long int X,i,Z,U,Max;
    string S,Ans;
    vector<pair<string,int>> M;
    X=English.length();
    int A[26]={0};
    for(i=0;i<X;i++)
    {
        A[English[i]-'a']++;
    }
    M.push_back({"six",6});
    M.push_back({"zero",0});
    M.push_back({"seven",7});
    M.push_back({"eight",8});
    M.push_back({"five",5});
    M.push_back({"four",4});
    M.push_back({"three",3});
    M.push_back({"two",2});
    M.push_back({"one",1});
    M.push_back({"nine",9});
    for(auto it=M.begin();it!=M.end();it++)
    {
        Max=INT_MAX;
        S=it->first;
        Z=S.length();
        U=0;
        for(i=0;i<Z;i++)
        {
            if(A[S[i]-'a']<Max)
            {
                Max=A[S[i]-'a'];
            }
        }
        for(i=0;i<Max;i++)
        {
            Ans+=('0'+it->second);
        }
        for(i=0;i<Z;i++)
        {
            A[S[i]-'a']-=Max;
        }
    }
    sort(Ans.begin(),Ans.end());
    return Ans;
}

int main()
{
	string S,Ans;
	cout<<"Enter the String"<<endl;
	cin>>S;
	Ans=EnglishToDigit(S);
	cout<<"Coverted String"<<endl;
	cout<<Ans<<endl;
	return 0;
}

/*
Time Complexity:O(N)
Space Complexity:O(1)
Where N is the length
of the string.

Sample I/O
Input:
Enter the String
owoztneoer
Output:
Coverted String
012
*/

