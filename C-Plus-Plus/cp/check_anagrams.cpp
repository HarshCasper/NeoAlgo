// Description: Given two strings, check if they are anagrams or not.
// An anagram of a string is another string that contains same characters, only the order of characters can be different.
// For example: 'word' and 'ordw' are anagrams, 'abcd' and 'abcdb' are not anagrams.
#include <bits/stdc++.h>
using namespace std;

bool check_anagrams(string s1, string s2){
    if(s1.size() != s2.size()){          //If two strings don't have equal length, that means they are not anagrams.
        return false;
    }
    int count[256] = {0};               //Take a count array of size 256(because of 256 ascii characters) and set all the positions to 0 initially
    for(int i = 0; i < s1.size(); i++){ //We are traversing through s1 and incrementing each s1's character frequency
        count[s1[i]]++;
    }
    for(int i = 0; i < s2.size(); i++){ //Here, we are traversing through s2 and decrementing s2's character frequency
        count[s2[i]]--;
    }
    for(int i = 0; i < 256; i++){       //Traversing through the count array
        if(count[i] != 0){              //If two strings are anagrams, all the count elements should be zero, and if they are not zero, we return false
            return false; 
        }
    }
    return true;                       //If all elements of count array are zero, s1 and s2 are anagrams
}

int main(){
    string s1, s2;
    cout << "Enter s1";
    getline(cin, s1);
    cout << "Enter s2";
    getline(cin, s2);
    cout << "Anagrams or not: ";
    if(check_anagrams(s1, s2)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}
// Sample test case:
// s1 = 'abcd' and s2 = 'abcdb'
// count of a, b, c, d become 1 while traversing through s1
// count of a, b, c, d become 0, -1, 0, 0 respectively, while traversing through s2
// Since one element of count array is not 0, we return false
