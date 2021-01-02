#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool issafetomove(int** arr, int x, int y, int m, int n)     //checking whether safe to move
{
    if(x<m && y<n && arr[x][y]==1)
    {
        return true;
    }
    return false;
}


bool ratInMaze(int** arr, int x,int y,int m, int n, int** solution)
{
    if(x==m-1 && y==n-1)             //base condition
    {
        solution[x][y]=1;
        return true;
    }

    if(issafetomove(arr,x,y,m,n))
    {
        solution[x][y]=1;
    if(ratInMaze(arr,x+1,y,m,n,solution))
    {
        return true;
    }
        if(ratInMaze(arr,x,y+1,m,n,solution))
    {
        return true;
    }
    solution[x][y]=0;                //backtracking
    return false;
    }


    return false;
}


int main()
{
    int m, n;
    cout<<"enter the rows and columns of the  matrix\n";
    cin>>m>>n;

    int** arr=new int*[m];
    for(int x=0;x<m;x++)
    {
        arr[x]=new int[n];
    }

    cout<<"enter the elements of the array\n";


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** solution=new int*[m];
     for(int i=0;i<m;i++)
    {
        solution[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            solution[i][j]=0;

        }
    }


    if(ratInMaze(arr,0,0,m,n,solution))
    {
        cout<<"The path obtained is as follows\n";

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }


    }

    return 0;
}
