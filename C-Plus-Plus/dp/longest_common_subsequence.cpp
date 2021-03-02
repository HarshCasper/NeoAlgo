/*
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
*/

#include <iostream>
#include <vector> // for 2D vector
using namespace std;

int lowest_common_subsequence(string &x, string &y)
{
    int len_x = x.length();
    int len_y = y.length();

    vector<vector<int> > dp (len_x+1, vector<int> (len_y+1,0));

    for(int i=1;i<=len_x;i++)
    {
        for(int j=1;j<=len_y;j++)
        {
            int q=0;

            if(x[i-1]==y[j-1]) //if matches
                q=1+dp[i-1][j-1];
            else     //if doesn't match
                q=max(dp[i-1][j],dp[i][j-1]);

        dp[i][j]=q;
        }
    }

    return dp[len_x][len_y]; //return last element
}

int main()
{
    string str1,str2;
    cout<<"Enter string1 and string2: ";
    cin>>str1>>str2;
    cout<<"output : "<<lowest_common_subsequence(str1,str2)<<endl;
}

/*
   Enter string1 and string2 : ABCDEFGH BDHCEG
   output : 4
*/

// Time and Space complexity : O(mn), where m = length of string1 and n = length of string2
