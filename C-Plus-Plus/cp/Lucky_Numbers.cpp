/*

Link to problem: https://codeforces.com/problemset/problem/630/C

The numbers of all offices in the new building of the Tax Office of IT City will have lucky numbers.

Lucky number is a number that consists of digits 7 and 8 only. 
Find the maximum number of offices in the new building of the Tax Office given that a door-plate can hold a number not longer than n digits.
*/

/*Input-
The only line of input contains one integer n (1 ≤ n ≤ 55) — the maximum length of a number that a door-plate can hold.
*/

/*Output-
Output one integer — the maximum number of offices, than can have unique lucky numbers not longer than n digits.
*/

/*
Logic of the below code:

Any lucky number can only consist of '7' or '8' which means each digit in a number can be either '7' or '8'. 
Each digit in a number has therefore 2 choices('7' or '8').
  
So for the length n the amount of lucky numbers of the length exactly n is 2^n. 
But in the problem we need the amount of lucky numbers of length not greater than n. 
Let's sum up them.
2^1 = 2, 2^1 + 2^2 = 2 + 4 = 6, 2^1 + 2^2 + 2^3 = 2 + 4 + 8 = 14, 2^1 + 2^2 + 2^3 + 2^4 = 2 + 4 + 8 + 16 = 30. 

Time complexity : O(N)
Space Complexity: O(1)

*/
    #include <iostream>
    using namespace std;
    int main()
    {
    int n;//store the number of digits
    long long a=1, sum=0;
	int i;
    cin>>i;
    /*Loop to increse the number of digits from 1 to n*/
	for(int k=1; k<=i; k++)
	{
	a = a*2;	//Number of choices an k digit number has 	
	sum +=  a;  //Calculate sum
	}
	cout<<sum;
}

/*I/O Example-
Input
2

Output
6
*/