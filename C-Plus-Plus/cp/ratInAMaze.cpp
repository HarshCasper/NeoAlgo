/*There is a rat who is at the starting point of a matrix and wants to reach
 to the ending point i.e at the last coordinate of the matrix.
 1 denotes the point where it is possible for the mouse to go and
 0 denotes the dead end */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 //checking whether safe to move
bool issafetomove(int** arr, int x, int y, int row, int col)    
{
    if(x<row && y<col && arr[x][y]==1)
    {
        return true;
    }
    return false;
}


bool ratInMaze(int** arr, int x,int y,int row, int col, int** solution)
{
//base condition
    if(x==row-1 && y==col-1)
    {
        solution[x][y]=1;
        return true;
    }

    if(issafetomove(arr,x,y,row,col))
    {
        solution[x][y]=1;

/*moving in right direction */
    if(ratInMaze(arr,x+1,y,row,col,solution))
    {
        return true;
    }

/*moving in down direction*/
        if(ratInMaze(arr,x,y+1,row,col,solution))
    {
        return true;
    }

/*backtracking  */
    solution[x][y]=0;
    return false;
    }


    return false;
}


int main()
{
    int row, col;
    cout<<"enter the rows and columns of the  matrix\n";
    cin>>row>>col;

    int** arr=new int*[row];
    for(int x=0;x<row;x++)
    {
        arr[x]=new int[col];
    }

    cout<<"enter the elements of the array\n";


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** solution=new int*[row];
     for(int i=0;i<row;i++)
    {
        solution[i]=new int[col];
        for(int j=0;j<col;j++)
        {
            solution[i][j]=0;

        }
    }


    if(ratInMaze(arr,0,0,row,col,solution))
    {
        cout<<"The path obtained is as follows\n";

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }


    }

    return 0;
}



//Output
/*enter the rows and columns of the  matrix
3 4
enter the elements of the array
1 1 1 1
1 0 0 0
1 1 1 1

The path obtained is as follows
1 0 0 0
1 0 0 0
1 1 1 1
*/
