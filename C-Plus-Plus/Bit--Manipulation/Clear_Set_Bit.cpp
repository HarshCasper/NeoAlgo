/* we need to clear the set bit at the given position */
#include <bits/stdc++.h>
using namespace std;

int clear_set_bit_using_xor(int n, int pos)
{
	// since xor is odd one out operator so 1^1=0
//left shift 1 till the given position
	int m = (1 << pos);
	return (n ^ m);
}
int clear_set_bit_using_and(int n, int pos)
{
	// since 0 & 1 = 0 this clears set bit
	//we create a mask such that at given position we have 0 and rest are 1's
	int m = ~(1 << pos);
	return (n & m);
}
int main()
{
	int number;
	cin >> number;
	int position_of_set_bit;
	cin >> position_of_set_bit;
	cout << clear_set_bit_using_xor(number, position_of_set_bit);
	cout << '\n';
	cout << clear_set_bit_using_xor(number, position_of_set_bit);
	cout << '\n';
	return 0;
}
