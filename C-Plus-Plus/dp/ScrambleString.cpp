/*
  Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
  We can scramble a string s to get a string t using the following algorithm:
  If the length of the string is 1, stop.
  If the length of the string is > 1, do the following:
  Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
  Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
  Apply step 1 recursively on each of the two substrings x and y.
  Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
  Given string str, we can represent it as a binary tree by partitioning it to two non-empty substrings recursively.
*/
#include<bits/stdc++.h>
using namespace std;

// function which check if s2 is scrambled form of s1 or not
int isScramble(string s1,string s2){
	 int length1 = s1.length();
	 
    if (s1 == s2)  //Base Condition
        return true;

    bool scrambled[length1][length1][length1];//creating a dp 3D matrix
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length1; ++j) {
            scrambled[i][j][0] = (s1[i] == s2[j]);
        }
    }

    for (int k = 1; k < length1; ++k) {
        for (int i = 0; i < length1 - k; ++i) {
            for (int j = 0; j < length1 - k; ++j) {
                scrambled[i][j][k] = false;
                for (int p = 0; p < k; ++p) {
                    if ((scrambled[i][j][p] && scrambled[i + p + 1][j + p + 1][k - p - 1]) || (scrambled[i][j + k - p][p] && scrambled[i + p + 1][j][k - p - 1])) {
                        scrambled[i][j][k] = true;
                        break;
                    }
                }
            }
        }
    }
    return scrambled[0][0][length1 - 1];
}

//Drivers Code
int main() {
	cout<<"Enter string s1 and s2:";
	string s1,s2;
	cin>>s1>>s2; // s1 and s2 are the strings which are needed to check weather they are scrambled or not
	int ans=isScramble(s1,s2); //isScramble functions checks if one string is scrambled form of other string or not
	if(ans==0)
	cout<<"Strings s2 is not scrambled form of s1"<<endl;
	else
	cout<<"Strings s2 is scrambled form of s1"<<endl;
	return 0;
}

/* 
   Time Complexity: O(N^4)
   Auxilary Space Complexity: O(N^3)
   
   Test Case 1:
   Enter String s1 and s2:we ew	
   Output:Strings s2 is scrambled form of s1
   
   Test Case 2:
   Enter String s1 and s2:phqtrnilf ilthnqrpf	
   Strings s2 is not scrambled form of s1
	
*/