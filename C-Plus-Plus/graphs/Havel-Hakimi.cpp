// Use Havel-Hakimi theorem and check whether the given degree sequence is graphical or not.

// Include all libraries
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check whether the degree sequence is graphical or not
bool havel_hakimi(vector <int> v) {
	while(1) {
		int n = v.size();
		vector <int>::iterator it;
		it = v.begin();

		// Insuficient degrees
		if(v[0] > n - 1) return false;

		// Subtract 1
		for(int i = 1; i <= v[0]; i++) v[i]--;

		// Remove first element
		v.erase(it);

		// Resorting
		sort(v.begin(), v.end(), greater<int>());

		// Check if vector contains all zeros
		if(all_of(v.begin(), v.end(), [](int i) { return i == 0; })) return true;

		// Return false if any element becomes -1
		if(all_of(v.begin(), v.end(), [](int i) { return i == -1; })) return false;
	}
}

int main() {
	cout<<"Enter the degree sequence of the graph (-1 to end) : ";
	vector <int> degree_sequence; 

	// Insert degree sequence
	while(1) {
		int element; cin>>element;
		if(element == -1) break;
		degree_sequence.push_back(element);
	}

	// Sort in descending order
	sort(degree_sequence.begin(), degree_sequence.end(), greater<int>());

	// Apply Havel Hakimi
	bool check = havel_hakimi(degree_sequence);
	if(check == false) cout<<"\nThe degree sequence is not graphical";
	else cout<<"\nThe degree sequence is graphical";
}

// 7, 6, 5, 4, 4, 3, 2, 1 - Graphical
// 6, 6, 6, 6, 3, 3, 2, 2 - Non-graphical
// 7, 6, 6, 4, 4, 3, 2, 2 - Graphical
// 8, 7, 7, 6, 4, 2, 1, 1 - Non-graphical

/* Output:

Enter the degree sequence of the graph (-1 to end) : 7
6
5
4
4
3
2
1
-1

The degree sequence is graphical

*/