/******************************************************************************
Author: @Suvraneel Bhuin

* Lee's Algorithm *
The objective is to find the length of the shortest path in a maze from a given source to a given destination,
Given the maze in form of a binary rectangular matrix.

-> Modify as required: 
    Definitions of ROW, COL
    Input `maze`, `src`, `dest` in main function
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
// define no. of rows & columns
#define ROW 10
#define COL 10

// Node Structure
// consists of x, y coordinates and the distance 
struct Node{
    int x, y, distance;
};
 
// movement in 4 directions
int direction[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
 
// check whether a valid position (i.e, within grid & is unvisited).
bool check(int mat[][COL], bool visited[][COL], int row, int col){
    return mat[row][col] && (row > -1) && (row <= ROW-1) && (col > -1) && (col <= COL-1) && !visited[row][col];
}

// shortest possible route
int bfs(int mat[][COL], int startX, int startY, int endX, int endY){
    // Queue to keep track of all the cells accounted for in the path so far
    queue<Node> Q;
    bool visited[ROW][COL];
    // mark all boxes unvisited initially
    // memset: sets memory pointed to by first `sizeof(visited)` characters of array `visited` to 0
    memset(visited, 0, sizeof(visited));
    // set the starting cell as visited and enqueue cell
    visited[startX][startY] = 1;
    Q.push({startX, startY, 0});
    // stores shortest path as of yet
    // initialised to INT_MAX so that any value can replace it
    int ans = INT_MAX;

    while (!Q.empty()){
        Node cell = Q.front();
        Q.pop();
        int i = cell.x, j = cell.y, distance = cell.distance;
 
        // if the destination is found, update minimum distance & break while loop
        if (i == endX && j == endY){
            // tracks minimum distance on the fly
            ans = distance;
            return ans;
        }
 
        // check for all possible movements
        for (int k = 0; k < 4; k++){
            // check if movement is valid (ie, within grid & unvisited)
            if (check(mat, visited, i + direction[k][0], j + direction[k][1])){
                // mark next cell as visited and enqueue it
                visited[i + direction[k][0]][j + direction[k][1]] = 1;
                Q.push({ i + direction[k][0], j + direction[k][1], distance + 1 });
            }
        }
    }
    // return -1 incase destination cannot be reached (i.e, path blocked)
    return -1;
}

// driver code
int main()
{
    // input maze here
    int maze[ROW][COL] = {
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
        { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };
    // input source cell & destination cell here
    int src[2]  = { 0, 0};
    int dest[2] = { 8, 9};

    // Find the shortest path from source to destination by calling bfs
    int res = bfs(maze, src[0], src[1], dest[0], dest[1]);
    //ouput
	if (res != -1)
		cout<< "Length of the Shortest Path is =>  "<< res << " units." ;
	else
		cout<< "Path from source to destination doesn't exist !";

    return 0;
}

/*
    Output:
    Length of the Shortest Path is =>  17 units.

    Time Complexity = O(ROW*COL)
    Space Complexity = O(ROW*COL)
*/
