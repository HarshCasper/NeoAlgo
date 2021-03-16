#include <iostream>
using namespace std;

int Hash(int x, int s) {
	return x % s;
}
//Function to insert in hashtable.
void QuadProbe(int Q[], int s, int x) {
	int index = Hash(x, s);
	int i = 0;
	while (Q[index] != 0 && Q[index] != -1) {
		i++;
		index = (Hash(x, s) + (i * i)) % s;

	}
	Q[index] = x;
}
//Function to Search for an element in hashtable.
void QPSearch(int Q[], int s, int x) {
	int index = Hash(x, s);
	int i = 0;
	while (Q[index] != 0) {
		if (Q[index] == x) {
			cout << "Element found at index " << index << endl;
			return;
		}
		i++;
		index = (Hash(x, s) + (i * i)) % s;

	}
	cout << "Element not found " << endl;
}
//Function to Delete an element from Hashtable.
void QPDelete(int Q[], int s, int x) {
	int index = Hash(x, s);
	int i = 0;
	while (Q[index] != 0) {
		if (Q[index] == x) {
			cout << "Element deleted " << endl;
			Q[index] = -1;
			return;
		}
		i++;
		index = (Hash(x, s) + i) % s;

	}
	cout << "Element not found hence cant be deleted " << endl;

}
//Main Function
//Space Complexity: O(n)
//Time Complexity: O(m) - The algorithm would iterate through the array of size m to allocate the elements their proper positions.
int main() {
	int n, x;
	cout << "Hello world!" << endl;
	cout << "Enter number of elements " << endl;
	cin >> n;
	int s = 2 * n;
	int p = s;
	while (p > 0) {
		if ( ( ((p - 1) % 6 == 0) && ((p + 1) % 6 != 0) )  || ( ((p + 1) % 6 == 0) && ((p - 1) % 6 != 0) ))
			break;
		p--;
	}
	int L[s] = {0}, Q[s] = {0}, D[s] = {0};
	cout << "Enter elements for quad probing " << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;

		QuadProbe(Q, s, x);

	}
	cout << "The hash table is" << endl;
	for (int i = 0; i < s; i++) {
		cout << Q[i] << endl;
	}

	cout << "Enter element to be searched in QP : ";
	cin >> x;
	QPSearch(Q, s, x);
	cout << "Enter element to be deleted in QP : ";
	cin >> x;
	LPDelete(Q, s, x);
	cout << "The hash table is " << endl;
	for (int i = 0; i < s; i++) {
		cout <<< < Q[i] << endl;
	}
	cout << "Enter element to be added : ";
	cin >> x;
	QuadProbe(Q, s, x);
	cout << "The hash table is " << endl;
	for (int i = 0; i < s; i++) {
		cout <<< < Q[i] << endl;
	}
	return 0;
}
