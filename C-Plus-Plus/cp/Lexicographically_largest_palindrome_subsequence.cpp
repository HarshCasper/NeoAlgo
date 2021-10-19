/* C++ Program to find lexicographically largest palindrome subsequence 
In this Program only input line contains a non-empty string S consisting of lowercase English letters only. Its length does not exceed 10.
Here, Characters in the strings are compared according to their ASCII codes and the one with largest ASCII code is lexicographically largest. 
And output contain frequency and all the reoccurrence of that character in string S in a single line.
*/     
#include<iostream>
#include<string>
using namespace std;

void Lexicographically_largest_palindrome_subsequence(string String) {
    string  assign, maxAscii;
    int i, j, counter, maxFrequency;
    //initialising maxAscii with character "a"                                
    maxAscii = "a";                         
    maxFrequency = 0;                     
    for(j = 0; j < String.size(); j++) {
        //initialising c with 0         
        counter = 0;                             
        for(i = 0; i < String.size(); i++) {
            //assigning value of element with index 'i' to a           
            assign = String[i];
            //this is for getting the lexicographically largest element (the one with largest ascii value)                  
            if(assign >= maxAscii)                       
            	maxAscii = assign;                     
        }
    }   
    for(i = 0; i < String.size(); i++) {
        assign = String[i];                           
        if(assign == maxAscii) {
            //increament c when we find our lexicographically largest character in string more than one time                  
            counter++;
            //for finding maximum frequency of character                              
            if(counter > maxFrequency) 
                maxFrequency = counter;                    
        } 
    }
    cout << maxFrequency << " ";
    for(i = 0; i < maxFrequency; i++) {  
        //printing subsequence of lexicographically largest character as output                        
        cout << maxAscii; 
    }
    return ;
}
int main() {
    string inputString;
    //getting user input as string        
    cin >> inputString;
    //calling function to perform the task
    Lexicographically_largest_palindrome_subsequence(inputString);
    return 0;
}

/* SAMPLE
Testcase 1
INPUT   startling
OUTPUT  2 tt
Testcase 2
INPUT   mississippi
OUTPUT  4 ssss
Testcase 3
INPUT   sausage
OUTPUT  1 u   
Time Complexity is O(n^2)   where n is length of string
Space Complexity is O(1)   */

