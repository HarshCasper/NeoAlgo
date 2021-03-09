/*
Top K frequent Elements
======================================
Given a non-empty array of integers, return the k most frequent elements.


Steps:
1.We will build a map and store frequency of every element in the array.
2.We will push all the elements of map along with their frequencies in a maxHeap as a pair. 
3.Now, elements are sorted in descending order based on the first element of the pair.
4.Therefore, we will make the pair as {frequency of the element, element}.
5.We will run a loop till k is greater than 0 and maxHeap is not empty, pop the elements and print them.

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
*/

#include <bits/stdc++.h>
using namespace std;

void topKFrequent(vector<int>& nums, int k) {
 map<int,int>m;
 priority_queue<pair<int,int>> pq;
        
 for(int i: nums){
 m[i]++;
 }
        
 for(auto i : m){
 pq.push({i.second, i.first});
 }

 while(k-- && !pq.empty()){
 cout<<pq.top().second<<" ";
 pq.pop();   
 }
}

// Driver code
int main() {

 // Take input
 int n; 
 cin >> n;
 vector<int> nums(n);
 for(int i = 0; i<n; i++){
 cin >> nums[i];
 }
 int k;
 cin >> k;
 topKFrequent(nums, k);
}

/*
Time Complexity: O(nlogn)
Space Complexity: O(n)

Input: 
n = 8
nums = [1,1,7,4,2,2,2,3]
k = 2
Output: [2,1]

Explanation:
Top 2 frequent elements are 2 and 1 as 2 occurs 3 times and 1 occurs 2 times.
*/

