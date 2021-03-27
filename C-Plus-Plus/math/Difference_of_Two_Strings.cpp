/*
DIFFERENCE OF TWO STRINGS
Problem Statement
    Given 2 strings a and b. String b has one more char added and shuffled. Find the char added in the string b.
Implementation 
    a. Using Hashmap (Slow approach and extra space)
    b. Using Bits Manipulation (Efficient Approach and no extra space)
*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Approach (Space - O(1) and time - O(N))
char bits_diff(string a, string b)
{
    char xorr = 0;
    int i = 0;
    for(i=0;i<a.size();i++){
        xorr ^= (a[i] ^ b[i]);
    }
    return xorr ^ b[i];
}

// Space - O(N) and Time - O(M+N) where m and n are the size of the 2 strings
char map_diff(string a, string b) {
    unordered_map<char,int> mp1, mp2;
    for(auto x:a) 
        mp1[x]++;
    for(auto y:b)
        mp2[y]++;
        
    for(auto x:b)
    {
        if(mp1.find(x)==mp2.end()) // finds the char of mp1 in mp2 
            return x;
        else if(mp1[x]!=mp2[x])  // a = 's' and b = 'ss' for the same char but diff count ans = 's'
            return x;
    }
    return b[(b.size())-1];
}

int main()
{
    string a,b; 
    cin>>a>>b;
    cout<< bits_diff(a,b) << endl;
    cout<< map_diff(a,b) << endl;
    return 0;
}

/*
Input 
    a = "abc"
    b = "abcd"
Output: d

Input 
    a = ""
    b = "c"
Output: c

Input 
    a = "zz"
    b = "zzz"
Output: z
*/