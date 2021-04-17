/*Problem Statement
 clear the set bit at the given position (position_of_set_bit) for the given number
 */
/*There are two ways to do so . Ist is using "Xor" and other using "And" operator
Example:
Input
number = 5 (Binary of 5 = 101)
position_of_set_bit = 2
Output:
number = 1 (Binary of 1 = 001)
After removing the ith set bit the number obtatined is 1
Time Complexity = O(1)*/
#include <bits/stdc++.h>
using namespace std;

int clear_set_bit_using_xor(int n, int pos)
{
	/*since xor is odd one out operator so 1^1=0
	left shift 1 till the given position*/
	int m = (1 << pos);
	n =  (n ^ m);
	return n;
}
int clear_set_bit_using_and(int n, int pos)
{
	/*since 0 & 1 = 0 this clears set bit
	we create a mask such that at given position we have 0 and rest are 1's*/
	int m = ~(1 << pos);
	n = (n & m);
	return n;
}
int main()
{
	int number;
	cin >> number;
	int position_of_set_bit;
	cin >> position_of_set_bit;
	cout << clear_set_bit_using_xor(number, position_of_set_bit);
	cout << '\n';
	cout << clear_set_bit_using_and(number, position_of_set_bit);
	cout << '\n';
	return 0;
}
