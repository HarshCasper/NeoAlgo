#include <bits/stdc++.h>
using namespace std;

void print(vector<int> chosen) {           // printing the subset values
	for(auto x:chosen) cout << x << " ";
	cout << endl;
}

void subset(vector<int> &choices, vector<int> &chosen, int index) {
    if(index < 0) {                                                 //base case to check for index
	print(chosen);
	return;
    }
    chosen.push_back(choices[index]);                              // choose the current element and move further in array to index-1
    subset(choices, chosen, index - 1);                    
    chosen.pop_back();                                             // we have removed the inserted element,this is done to get all sequences without this value
    subset(choices, chosen, index - 1);
}

int main() {
	vector<int> choices ;

	for (int i = 1; i <= 3; i++)  // take input for array
        choices.push_back(i); 

	vector<int> chosen;
	subset(choices, chosen, choices.size()-1);
}

/*
We always have two options whether to choose the current element or not. This is what we will do. First, find all subsets with including it and then find all subsets without including it.

Sample Test Case

Input: nums = [1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*/
