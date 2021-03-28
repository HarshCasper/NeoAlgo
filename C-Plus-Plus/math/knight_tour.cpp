/*
This problem is a knight tour problem which is solved using backtracking.
we are given n*n board where knight is placed in the first cell. We will move the knight position according to it's nature.
Then we will print all the positions of board taken by knight
*/
#include <bits/stdc++.h>
using namespace std;

/* 
We will check whether the knight has already visited the particular position or not.
And we will also check that knight has not moven outside from the board
*/
bool isSafe(int x,int y,int sol[8][8],int n){
    if(x>=0 && x<n && y>=0 && y<n && sol[x][y] == -1){
        return true;
    }
    return false;
}

// print function
void print(int sol[8][8],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(2)<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Recurseive function to solve knight tour problem
bool moveKnight(int xi, int yi, int movei, int x[8], int y[8], int n, int sol[8][8]){
    int x2,y2;
    if(movei == n*n){
        return true;
    }

    // We will try all the move from the coordinates xi, and yi
    for(int i=0;i<8;i++){
        x2 = xi + x[i];
        y2 = yi + y[i];
        // if box is safe then we will initialise that particular box with movei
        if(isSafe(x2,y2,sol,n)){
            sol[x2][y2] = movei;
            if(moveKnight(x2,y2,movei+1,x,y,n,sol) == 1){
                return true;
            }
            // is not able to move then we will backtrack
            else{
                sol[x2][y2] = -1;
            }
        }
    }
    return false;
}

/*
this function will help us solving knight tour problem using backtracking.
if no complete tour is possible then it will return false
else it will print the solution
*/
bool solveKnight(int n){
    //define solution matrix
    int sol[8][8];
    // initialise the solution matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sol[i][j] = -1;
        }
    }
   
   /* 
   All the possible move that can be made by a knight
   in x and y direction. 
   */
    int x[8] = {2,1,-1,-2,-2,-1,1,2};
    int y[8] = {1,2,2,1,-1,-2,-2,-1};

    // knight is initially in the first box therefor it's position will be initialised with 0
    sol[0][0] = 0;
    // moveKnight will help us to go to every possible position 
    if(moveKnight(0,0,1,x,y,n,sol) == 0){
        cout<<"Result cannot be find";
        return false;
    }
    else{
        print(sol,n);
    }
    return true;
}

// driver code
int main() {
    //size of the box
    int n;
    cin>>n;
    //recursive call
    solveKnight(n);
    return 0;
}
/*
Input - 8
Output - 
 0 59 38 33 30 17  8 63 
37 34 31 60  9 62 29 16 
58  1 36 39 32 27 18  7 
35 48 41 26 61 10 15 28 
42 57  2 49 40 23  6 19 
47 50 45 54 25 20 11 14 
56 43 52  3 22 13 24  5 
51 46 55 44 53  4 21 12 

Time Complexity - O(n*n)
*/
