//C++ Program to print all subsets of a given distinct array of positive integers
#include <bits/stdc++.h>
using namespace std;

void GetSubsets(vector<int> inputArray, vector<int> subsetArray, int pos)
{
	if (pos == inputArray.size())
	{
		//the input array has been traversed when pos = array size
		cout << "[";
		for (int i = 0; i < subsetArray.size(); i++)
		{
			if (subsetArray[i] != 0)	//ignoring empty values
				cout << subsetArray[i] << ",";
		}

		cout << "]\n";
	}
	else
	{
		GetSubsets(inputArray, subsetArray, pos + 1);	//Recursion tree branch 1

		subsetArray[pos] = inputArray[pos];
		GetSubsets(inputArray, subsetArray, pos + 1);	//Recursion tree branch 2
	}
}

//DRIVER FUNCTION
int main()
{
	int size;
	cout << "Enter size of the array: ";
	cin >> size;
	vector<int> inputArray(size);	//initializing input array with user-given size
	for (int i = 0; i < size; i++)
	{
		cin >> inputArray[i];
	}

	vector<int> subsetArray(size);	//empty array for storing subsets
	cout << "[";
	GetSubsets(inputArray, subsetArray, 0);	//prints the subsets
	cout << "]";
}

/*Sample IO

Input:
3
1 2 3
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

TIME COMPLEXITY - O(2^n)
SPACE COMPLEXITY - O(n)

/*