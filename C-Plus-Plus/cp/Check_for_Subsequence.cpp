#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int i = 0, j = 0;                                  //i will point str1 and j will point str2
		string str1, str2;                                 //str1 is substring
		cin >> str1 >> str2;                               //str2 is full string
		while (i < str1.length() && j < str2.length()) {
			if (str1[i] == str2[j]) {
				i++;
			}
			j++;
		}
		if (i == str1.length()) {
			cout << "Yes, str1 is substring of str2";
		} else {
			cout << "No, str1 is not substring of str2";
		}
		cout << endl;
	}
	return 0;
}

/*Time Complexity: O(n)
Input:
2
WGA AWRGNA
QBR EQVBA
Output:
Yes, str1 is substring of str2
No, str1 is not substring of str2
*/