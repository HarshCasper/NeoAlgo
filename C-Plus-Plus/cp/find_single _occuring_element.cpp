/*
 Given an array of N elements, where each element occurs twice except one.
 we can found that element with the help of Bitwise XOR operator.
 Bitwise operations are best because they perform the operation in least possible time.
*/

#include <bits/stdc++.h>
using namespace std;

int single_occurs_element(int ar[], int N) {
	int x = 0;
	for (int i = 0; i < N; i++) {
		/*  we know how bitwise xor works that is
		bitwise xor of a number with itself is 0.
		bitwise xor of a number with 0 is number itself.
		so the single element will be in the x finally.
		*/
		x ^= ar[i];

	}
	return x;
}

int main() {
	cout << "Enter the size of the array : \n";
	int N;
	cin >> N;
	int ar[N + 1];
	cout << "Enter array elements :\n";
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}
	int single_element = single_occurs_element(ar, N);
	cout << "Single occurring element in the array is : \n";
	cout << single_element << endl;

}

/*
Standard Input and Output

Enter the size of the array :
9
Enter array elements :
1 2 3 4 1 2 3 5 4

Single occurring element in the array is :
5

Time Complexity : O(N)
Space Complexity : O(1)
*/
