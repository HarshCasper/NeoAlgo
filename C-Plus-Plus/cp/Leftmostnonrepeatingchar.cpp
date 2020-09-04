// Description: This program finds the leftmost non repeating character in a string.
// For example: s = "aabcdb", output should be: 3 (index of c)
#include<bits/stdc++.h>
using namespace std;

int leftmostnonrepeatingchar(string s){
    int res = numeric_limits<int>::max();  //Initialised res to infinity
    int fi[256];                           //An array to store first indices of string characters(size is 256 because there are 256 ascii characters)
    for(int i = 0; i < 256; i++){          //Initialising all elements to -1
        fi[i] = -1;
    }
    for(int i = 0; i < s.size(); i++){     //Traversing through string   
        if(fi[s[i]] == -1){                //If this position in array is -1, that means its a non repeating element
            fi[s[i]] = i;
        }else{
            fi[s[i]] = -2;                 //If it is -2 that means this element has already been repeated before
        }
    }
    for(int i = 0; i < 256; i++){
        if(fi[i] >= 0){
            res = min(res, fi[i]);         //finding the leftmost non repeating char index
        }
    }
    return (res == numeric_limits<int>::max())? -1: res;
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "The leftmost non repeating character in the string is: " << leftmostnonrepeatingchar(s);
    return 0;
}
// Sample test case:
// s = "aabcdb", all elements of fi array are initialised as -1
// After traversing through string, our res would become 3 

