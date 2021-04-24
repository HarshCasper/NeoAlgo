/*
Given a 2 dimensional array consisting of integers. Print the array in the wave form.

Explanation: According to the problem, we are given the number of rows and columns
of the matrix alongwith its elements. So we have to print the matrix in wave form. 
*/

#include<bits/stdc++.h>
using namespace std;
void wave(int m,int n,int a[][1000])
{
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<m;j++)
                cout<<a[j][i]<<" ";
        }
        else
        {
            for(int j=m-1;j>=0;j--)
                cout<<a[j][i]<<" ";
        }
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns respectively : ";
    cin>>m>>n;
    int a[m][1000];
    cout<<"Enter the 2D matrix : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    cout<<"Array when printed in wave form is as follows : "<<endl;
    wave(m,n,a);
    return 0;
}

/*
Sample Input : 
Enter the number of rows and columns respectively : 3 4
Enter the 2D matrix :
1 2 3 4
5 6 7 8
9 10 11 12
Array when printed in wave form is as follows : 
1 5 9 10 6 2 3 7 11 12 8 4 
*/

/*
Time complexity : O(m*n)
Space complexity : O(1)
*/
