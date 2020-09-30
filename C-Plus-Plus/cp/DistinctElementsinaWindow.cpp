//This program calculates the count of distinct elements in every window
#include <bits/stdc++.h>
using namespace std;

void CountDist(int arr[], int n, int k){  //O(n) time and O(n) aux space
    unordered_map<int, int> freq;  //this map is for storing the frequency of elements
    for(int i = 0; i < k; i++){
        freq[arr[i]]++;
    }
    cout << freq.size() << " ";  //This statement prints the number of first window's distinct elements
    for(int i = k; i < n; i++){  //For calculating the ans for other windows, we decrement the freq of the 1st element of prev 
        freq[arr[i - k]]--;      //window and add the freq of new element
        if(freq[arr[i - k]] == 0){
            freq.erase(arr[i - k]);
        }
        freq[arr[i]]++;
        cout << freq.size() << " ";
    }
}

int main() {
    int n;
    cout << "Enter size of array";
    cin >> n;
    int arr[n];
    cout << "Enter array elements";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the size of window";
    cin >> k;
    CountDist(arr, n, k);
    return 0;
}

/*Examples:
1. For arr[] = {10, 20, 20, 10, 30, 40, 10}, k = 4
   Output = 2 3 4 3
2. For arr[] = {10, 10, 10, 10}, k = 3
   Output: 1 1
3. For arr[] = {10, 20, 30, 40}, k = 3
   Output: 3 3 */



