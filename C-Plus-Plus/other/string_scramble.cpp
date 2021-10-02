/*

Problem: Scramble String

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, 
i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the 
same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a 
scrambled string of s1, otherwise, return false.

*/

// Code
class Solution {
public:
    bool helper(string s1, string s2, unordered_map<string, bool>& m) {
        string token = s1 + "," + s2;
        if (m.find(token) != m.end())
            return m[token];
        
        if (s1.size() == 1)
        {
            m[token] = s1 == s2;
            return m[token];
        }
        int n = s1.size();
        vector<int> counter(26, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            ++counter[s1[i] - 'a'];
            --counter[s2[i] - 'a'];
        }
        for (auto c: counter)
        {
            if (c)
            {
                m[token] = false;
                return false;
            }
        }
                
        for (int i = 1; i < s1.size(); ++i)
        {
            string s1_1 = s1.substr(0, i);
            string s1_2 = s1.substr(i);
            string s2_1 = s2.substr(0, i);
            string s2_2 = s2.substr(i);
            if (helper(s1_1, s2_1, m) && helper(s1_2, s2_2, m))
            {
                m[token] = true;
                return true;
            }
            s2_1 = s2.substr(n - i);
            s2_2 = s2.substr(0, n - i);
            if (helper(s1_1, s2_1, m) && helper(s1_2, s2_2, m))
            {
                m[token] = true;
                return true;
            }
        }
        m[token] = false;
        return false;
    }
    
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> m;
        return helper(s1, s2, m);
    }
};

/*

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is s2.
As there is one possible scenario that led s1 to be scrambled to s2, we return true.

*/