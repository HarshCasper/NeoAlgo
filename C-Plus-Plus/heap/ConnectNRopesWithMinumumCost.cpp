#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n){
	//Creating Priority Queue(Min Heap)
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);
	int output = 0;

	while (pq.size() > 1) {
		//Getting the 2 smallest ropes;
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		output += first + second;
		pq.push(first + second);
	}

	return output;
}

int main(){
	cout<<"Enter The number of Ropes:\n";
	int n;
	cin>>n;
	int ar[n];
	cout<<"Enter the Cost of each rope:\n";
	for(int i=0;i<n;i++){
		cin>>ar[i];	
	}
	cout << "Minimum cost for connecting ropes is " << minCost(ar,n);
	return 0;
}
