/*Problem Statement:
Sequence (ai) of natural numbers is defined as follows:
ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)
where bj and cj are given natural numbers for 1<=j<=k.
Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and 
output it modulo a given positive integer p. */

#include<bits/stdc++.h>
using namespace std;

int k;
vector<int> a,b,c;
vector<vector<int> > product_elements(vector<vector<int> > A,vector<vector<int> > B )
{
    vector<vector<int> > C(k+1,vector<int>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x=1;x<=k;x++)
            {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j]));
            }

        }
    }
    return C;
}

vector<vector<int> >  power(vector<vector<int> > A,int p)
{
    if(p==1)
    {
        return A;
    }
    if(p&1)
    {
        return product_elements(A, power(A,p-1));
    }
    else
    {
        vector<vector<int> > X = power(A,p/2);
        return product_elements(X,X);
    }

}

int special_sequence(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<=k)
    {
        return b[n-1];
    }
    vector<int> F1(k+1);
    for(int i=1;i<=k;i++)
    {
        F1[i] = b[i-1];
    }
    vector<vector<int> > T(k+1,vector<int>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            // every row except the last one has either 0 or 1 in it
            if(i<k)
            {
                if(j==i+1)
                {
                    T[i][j] = 1;
                }
                else
                {
                    T[i][j] = 0;
                }
                continue;
            }
            //storing the Coefficients in reverse order
            T[i][j] = c[k-j];
        }
    }
    T = power(T,n-1);
    int res = 0;
    for(int i=1;i<=k;i++){
        res = (res + (T[1][i]*F1[i]));
    }
    return res;
}

int main() 
{
    int n,m,p,num;
    cout<<"Enter total number of elements: "<<endl;
    cin>>k;
    cout<<"Enter k natural nos(bj): "<<endl;
    for(int i=0;i<k;i++)
    {
        cin>>num;
        b.push_back(num);
    }
    cout<<"Enter k natural nos(cj): "<<endl;
    for(int i=0;i<k;i++)
    {
        cin>>num;
        c.push_back(num);
    }
    cout<<"Enter the value of m,n,p as per question: "<<endl;
    cin>>m>>n>>p;      
    int ans1 = special_sequence(m+1)%p;
    int ans2 = special_sequence(n+2)%p;
    int ans = (ans2-ans1); 
    if(ans<0)
    {
        ans=(ans+p)%p;
        cout<<"Sum of the special sequence: "<<ans%p<<endl;
    }
    else
    {
        cout<<"Sum of the special sequence: "<<ans%p<<endl;
    }
    return 0;
}
/*Example:-

Input:-
Enter total number of elements: 
2
Enter k natural nos(bj): 
1 1
Enter k natural nos(cj): 
1 1
Enter the value of m,n,p as per question: 
2 10 1000003

Output:-
Sum of the special sequence: 142

Time Complexity: O(n)
Space Complexity: O(n)
*/

