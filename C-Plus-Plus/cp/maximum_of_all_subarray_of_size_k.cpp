/**
 * Maximum of All Subarrays of Size k
 * Cpp program to find the maximum integer in each subarray of 
 * fixed size k, given an array of integers, using the 'Sliding 
 * Window Technique'. 
 */

#include <bits/stdc++.h>
using namespace std;

void MaximumEachSubarray(int len, int arr[], int k)
{
    //Deque stores indices of useful elements for each window.
    //These elments are sorted in decreasing order, so that for each
    //window, maximum element is at the front.
    deque<int> maxElement;
    vector<int> ans;
    //Edge case
    //If len is smaller than k, push maximum element into the answer
    if (k > len) {
        ans.push_back(*max_element(arr, arr + len));
    }
    //Two pointer one pointing to start and other to the end of current window
    int start = 0, end = 0;
    //The same process is repeated over all windows of length k.
    while (end < len) {
        //For any element, all elements smaller than it and to its left in
        //the window are useless as they cannot be the maximum for that
        //window. Hence, we remove them from rear of deque.
        while (maxElement.size() > 0 && maxElement.back() < arr[end])
            maxElement.pop_back();
        //Adding newest element to rear of deque
        maxElement.push_back(arr[end]);
        //If window size is not reached,increment end pointer
        if (end - start + 1 < k)
            end++;
        else if (end - start + 1 == k) { //Adding front element to ans
            //If front element equals 1st element
            //of current window, we remove it from deque
            ans.push_back(maxElement.front());
            if (maxElement.front() == arr[start])
                maxElement.pop_front();
            //slide the window
            start++;
            end++;
        }
    }
    cout << "Array of maximum integers in all k-sized subarrays: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    //Taking input from user
    int len;
    cout << "Enter length of array of integers: ";
    cin >> len;
    int arr[len];
    cout << "Enter array of integers: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int k;
    cout << "Enter size of window: ";
    cin >> k;
    MaximumEachSubarray(len, arr, k);
    return 0;
}

/*
	Test cases:

	INPUT:-
	Enter length of array of integers: 8
    Enter array of integers: 12 3 -7 8 -15 39 15 20
	Enter size of window: 3
	OUTPUT:-
	Array of maximum integers in all k-sized subarrays: 12 8 8 39 39 39

	INPUT:-
	Enter length of array of integers: 4
	Enter array of integers: 3 2 1 5
	Enter size of window: 3
	OUTPUT:-
	Array of maximum integers in all k-sized subarrays: 3 5

	Time complexity: O(N)
	Space complexity: O(k)

*/
