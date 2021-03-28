#include <iostream>
using namespace std;

int Hash(int x, int s) {
	return x % s;
}
int prime(int p, int x) {
	return p - (x % p);
}
//Function to insert element in the hash table
void DoubleHashing(int D[], int s, int x, int p) {
	int index = Hash(x, s);
	int i = 0;
	while (D[index] != 0 && D[index] != -1) {
		i++;
		index = (Hash(x, s) + ( i * prime(p, x) ) ) % s;

	}
	D[index] = x;

}
//Function to search for an element.
void DHSearch(int D[], int s, int x, int p) {
	int index = Hash(x, s);
	int i = 0;
	while (D[index] != 0) {
		if (D[index] == x) {
			cout << "Element found at index " << index << endl;
			return;
		}
		i++;
		index = (Hash(x, s) + ( i * prime(p, x) ) ) % s;

	}
	cout << "Element not found " << endl;
}
//Function to delete an element from the Hash Table.
void DHDelete(int D[], int s, int x, int p) {
	int index = Hash(x, s);
	int i = 0;
	while (D[index] != 0) {
		if (D[index] == x) {
			cout << "Element deleted " << endl;
			D[index] = -1;
			return;
		}
		i++;
		index = (Hash(x, s) + ( i * prime(p, x) ) ) % s;

	}
	cout << "Element not found " << endl;
}

//Main Function
//Space Complexity: O(n) - Array for the hash table.
//Time Complexity: O(m) ; Where m is the size of hashtable the algorithm will scan to allocate the elements their correct position.
int main() {
	int n, x;
	cout << "Hello world!" << endl;
	//Enter number of elements you want to insert.
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
	//Enter the elements that you want to insert.
	cout << "Enter elements " << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		DoubleHashing(D, s, x, p);
	}
	cout << "Hash Table " << endl;
	for (int i = 0; i < s; i++) {
		cout << D[i] << endl;
	}
	cout << "Enter element to be searched in DH : ";
	cin >> x;
	DHSearch(D, s, x, p);
	cout << "Enter element to be deleted in DH : ";
	cin >> x;
	DHDelete(D, s, x, p);
	cout << "The Hash Table is " << endl;
	for (int i = 0; i < s; i++) {
		cout << D[i] << endl;
	}
	cout << "Enter element to be added : ";
	cin >> x;
	DoubleHashing(D, s, x, p);
	for (int i = 0; i < s; i++) {
		cout << D[i] << endl;
	}
	return 0;
}
