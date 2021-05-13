/*Problem Statement: 
Theodore implements a new strategy game “Defense of a Kingdom”. 
On each level a player defends the Kingdom that is represented by a rectangular grid of cells. 
The player builds crossbow towers in some cells of the grid. 
The tower defends all the cells in the same row and the same column. 
No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. 
For example, the position shown on the picture has penalty 12.
Help Theodore write a program that calculates the penalty of the given position */

#include<bits/stdc++.h>
using namespace std;

int position(int x_points[], int y_points[],int n,int w,int h)
{
    int dx=x_points[0];
    int dy=y_points[0];
    for(int i=1;i<n;i++)
    {
        dx=max(dx,x_points[i]-x_points[i-1]);
        dy=max(dy,y_points[i]-y_points[i-1]);
    }
    dx=max(dx,w+1-x_points[n-1]);
    dy=max(dy,h+1-y_points[n-1]);
    int ans=(dx-1)*(dy-1);
    return ans;
}

int main()
{
    int w,h,n,x,y;
    int x_points[100],y_points[100];
    cout<<"Enter width, height and number of towers respectively: "<<endl;
    cin>>w>>h>>n;
    cout<<"Enter coordinates: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x_points[i];
        cin>>y_points[i];
    }
    sort(x_points,x_points+n);
    sort(y_points,y_points+n);
    cout<<"No of cells that can not be defended: "<<position(x_points,y_points,n,w,h)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter width, height and number of towers respectively:
15 8 3
Enter coordinates:
3 8
11 2
8 6

Output:-
No of cells that can not be defended: 12

Time Complexity: O(n)
Space Complexity: O(n)
*/

