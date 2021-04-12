/*
PROBLEM STATEMENT:
Given a floor of size 2Xn and tiles of size 2X1. We've to find the number number of ways in which the floor can be tiled using tiles of size 2X1. 
A tile can be either placed horizontally or vertically.
*/

#include<stdio.h>

int NoOfWays(int n){
	int tiles[n+1];
	for(int i = 0; i <= n; i++){
		//Base cases
		if(i == 0)
			tiles[i] = 0;
		else if(i == 1)
			tiles[i] = 1;
		//Adding the solutions that we get by placing first tile vertically and by placing first tile horizontally 
		else
			tiles[i] = tiles[i-1] + tiles[i-2];
	}
	//returning the ways in which floor of size 2Xn can be tiled
	return tiles[n];
}

//Driver function
int main(){
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);
	printf("Total no. of ways in which floor of size 2X%d can be tiled are: %d", n, NoOfWays(n));
	return 0;
}

/*
TEST CASE:
Input: 4
Output: 3

TIME COMPLEXITY: O(n), due to the single for loop used
SPACE COMPLEXITY: O(n), due to the additional dp array created
where 'n' denotes the breadth of the floor as entered by the user
*/
