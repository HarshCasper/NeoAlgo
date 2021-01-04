/* Z Algorithm- A linear time pattern searching algorithm */
/* An algorithm to find all occurances of a pattern in a text in linear time O(n) */

#include<bits/stdc++.h>
using namespace std;

// Function to create the Z-array
void createZarray(string s,int z[])
{
    int n = s.length();
    int l,r,k;
    l=r=0;
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;

            while(r<n && (s[r-l]==s[r]))
            {
                r++;
            }
            z[i]=r-l;
            r--;
        }
    }
}

// Function to search the array for the pattern
void searcharray(string t, string p)
{
    string c = p + "$" + t;
    int length = c.length();

    int z[length];
    createZarray(c,z);

    for(int i=0;i<length;i++)
    {
        if(z[i]==p.length())
        {
            cout<<"Pattern found at index "<<i-p.length()-1<<endl;
        }
    }
}
// The main function
int main()
{
    string t;
    cin>>t;
    string p;
    cin>>p;
    searcharray(t,p);
    
    return 0;
}