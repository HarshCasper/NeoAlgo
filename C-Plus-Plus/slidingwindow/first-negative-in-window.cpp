/*
    Problem: First Negative Integer in Every Window of Size K
    Language: C++
    Author: <Umang Chandra>
    Description: Print the first negative number in each window of size K using a queue.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove elements outside the window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Add negative numbers
        if (arr[i] < 0)
            dq.push_back(i);

        // Start adding results after the first k elements
        if (i >= k - 1) {
            if (!dq.empty())
                result.push_back(arr[dq.front()]);
            else
                result.push_back(0);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> res = firstNegativeInWindow(arr, k);
    cout << "First negative integers in every window of size " << k << ":\n";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Sample Output:
First negative integers in every window of size 3:
-1 -1 -7 -15 -15 0
*/
