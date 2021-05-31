#include<bits/stdc++.h>
using namespace std;

int nr[6000][6000];


int  ncr(int n,int r)
{
    if(nr[n][r] != -1)
    {
        return nr[n][r];
    }

    if(n == 1)
    {
        nr[n][r] = 1 ;
        return nr[n][r];
    }

    if(r == 0 || r == n)
    {
        nr[n][r] = 1;
        return nr[n][r];
    }

    nr[n][r] = (ncr(n-1,r) + ncr(n-1,r-1));
    return nr[n][r];
}

int main()
{
    memset(nr,-1,sizeof(nr));

    int n = 10, r = 2;

    cout<< ncr(n,r);
}
