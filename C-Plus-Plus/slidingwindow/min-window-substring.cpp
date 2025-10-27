/*
    Problem: Minimum Window Substring
    Language: C++
    Author: <Umang Chandra>
    Description: Find the smallest substring of s containing all characters of t using Sliding Window.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> freqT, window;
    for (char c : t) freqT[c]++;

    int have = 0, need = freqT.size();
    int left = 0, minLen = INT_MAX;
    int resL = 0, resR = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (freqT.count(c) && window[c] == freqT[c])
            have++;

        // Try to shrink window
        while (have == need) {
            // Update result
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                resL = left;
                resR = right;
            }

            // Shrink from left
            window[s[left]]--;
            if (freqT.count(s[left]) && window[s[left]] < freqT[s[left]])
                have--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(resL, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window substring: " << minWindow(s, t) << endl;
    return 0;
}

/*
Sample Output:
Minimum window substring: BANC
*/
