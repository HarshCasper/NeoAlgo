/*
This problem is solved using backtracking.
Rat starts from 1st position of the grid and we have to find the path to reach at the end.
*/
#include <iostream>
using namespace std;

// We will check whether the current box is safe to move the rat or not
bool isSafe(int x, int y, int** arr,int n){
    if(x<n && y<n && arr[x][y] == 1){
        return true;
    }
    return false;
}

// A recursive function to solve rat maze problem
bool ratInMaze(int x,int y,int** arr,int n,int** solArr){
    //base case
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1;
        return true;
    }

    //recursive case
    if(isSafe(x,y,arr,n)){
    // if it is safe to place at current cell then change it from 0 to 1
    solArr[x][y] = 1;
    if(ratInMaze(x+1,y,arr,n,solArr)){
        return true;
    }
    if(ratInMaze(x,y+1,arr,n,solArr)){
        return true;
    }

    // if we are not able to move rat then backtrack
    solArr[x][y] = 0;
    return false;
    }
    return false;
}

// driver code
int main() {
    // size of the maze
    int n;
    cin>>n;

    // dynamic allocation of array
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    // dynamic allocation od solArr
    int** solArr = new int*[n];
    for(int i=0;i<n;i++){
        solArr[i] = new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j] = 0;
        }
    }

     // if path is found then print the solution
    if(ratInMaze(0,0,arr,n,solArr)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solArr[i][j]<<" ";
        }
        cout<<endl;
    }
    }

    return 0;
}
/*
INPUT-
5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

OUTPUT -
1 0 0 0 0 
1 1 1 1 0 
0 0 0 1 0 
0 0 0 1 1 
0 0 0 0 1 

Time Complexity - O(2^(n^2))
Space Complexity - O(n^2)
*/
