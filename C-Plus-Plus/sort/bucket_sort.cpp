// Usecase : if all the elements are in a given range 
// as in the case we perform counting sort.
// As in this example, assume all elements are between
// 0 - 99. We select a fair bucket size, as in this case 
// 10
// average time complexity : O(nlog(n/k)), where k is #buckets
// worst case time complexity : O(nlogn)
// space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int>& arr) {
	int n = arr.size(), k = 10;
	// create a bucket
	vector<vector<int>> bucket(k);
	for(int e : arr)
	    bucket[e/k].push_back(e);
	for(int i = 0; i < k; i++)
		sort(bucket[i].begin(), bucket[i].end());
	int ptr = 0, i = 0;
	// copy the elts back to arr
	while(ptr < k) {
		for(int j = 0; j < bucket[ptr].size(); j++)
			arr[i+j] = bucket[ptr][j];
		i += bucket[ptr].size();
		ptr ++;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	// taking ip
	for(int i=0; i<n; i++)
		cin >> arr[i];
	bucket_sort(arr);
	// taking ip
	for(int i=0; i<n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}
