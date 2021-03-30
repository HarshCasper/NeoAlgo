/*
PROBLEM STATEMENT:
Given a floor of size 2Xn and tiles of size 2X1. We've to find the number number of ways in which
the floor can be tiled using tiles of size 2X1. A tile can be either placed horizontally or vertically.
*/

#include<stdio.h>

//A function that uses DP approach to find the total number of ways to tile the floor.
int NoOfWays(int n){
	//An array, tiles of size n+1 which stores the no. of ways in which the floor of size 2Xi can be tiled
    int tiles[n+1];
    for(int i = 0; i <= n; i++){
    	//Base cases
	    if(i == 0)
		    tiles[i] = 0;
    	else if(i == 1)
    		tiles[i] = 1;

    	//Adding the solutions that we get by placing first tile vertically and by placing first tile horizontally 
    	else
    		tiles[i] = (tiles[i-1] + tiles[i-2]);
    }
    //returning the ways in which floor of size 2Xn can be tiled
    return tiles[n];
}

//Driver function
int main(){
		int n;
		printf("Enter value of n: ");
		//user input for value of n
		scanf("%d",&n);
		//function call to NoOfWays
		printf("Total no. of ways in which floor of size 2X%d can be tiled are: %d", n, NoOfWays(n));
	
	return 0;
}

/*
TEST CASES:
1.
Input: 4
Output: 3

2.
Input: 1
Output: 1

3.
Input: 8
Output: 21

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/