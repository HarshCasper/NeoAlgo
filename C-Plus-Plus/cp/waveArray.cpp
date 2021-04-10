/*	Given an array of integers, return the array which is sorted into a wave like array.
 *	In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5...
 *
 *	Example:
 *	Given [1, 2, 3, 4]
 *	One possible answer : [2, 1, 4, 3]
 *	Another possible answer : [4, 1, 3, 2]
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> waveArray(int n, vector<int> a){
    sort(a.begin(), a.end());
    for(int curr = 0; curr < n - 1; curr += 2){
        swap(a[curr], a[curr + 1]);
    }
    return a;
}

int main(){
    int size, val;
    vector <int> v;
    cout << "Enter the size of the array: ";
    cin >> size;
			    
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> val;
        v.push_back(val);
    }
				        
    v = waveArray(size, v);
    cout << "Wave Array: ";			        
    for(int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;
}

/*
 * 	Sample Output:
 *
 *  	Enter the size of the array: 5
 *      Enter the elements of the array:
 *      1
 *      2
 *      3
 *      4
 *      5
 *      Output:
 *      Wave Array: 2 1 4 3 5
 *
 *      Time Complexity: O(nlogn)
 *      Space Complexity: O(1)
 *
 */

