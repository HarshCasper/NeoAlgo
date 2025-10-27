/*
    Problem: Longest Substring with K Distinct Characters
    Language: C++
    Author: <Umang Chandra>
    Description: Use Sliding Window with HashMap to track character frequency and expand/shrink window dynamically.
*/

#include <bits/stdc++.h>
using namespace std;

int longestKDistinct(string s, int k) {
    int n = s.size();
    if (k == 0 || n == 0) return 0;

    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        // Shrink window if distinct count > k
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "eceba";
    int k = 2;
    cout << "Length of longest substring with at most " << k << " distinct characters: "
         << longestKDistinct(s, k) << endl;
    return 0;
}

/*
Sample Output:
Length of longest substring with at most 2 distinct characters: 3
*/
