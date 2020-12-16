//Question Print all possible subset using recursion

#include <iostream>
using namespace std;

void printSubset(string word, string subset){
   if(word.length() == 0){
       cout << subset <<" ";
       return;
   }
   
   string subset2 = subset + word[0];
   
   word.erase(word.begin() + 0);
   
   printSubset(word, subset);
   printSubset(word, subset2);
}

int main()
{
    cout << "Enter the String : ";
    
    string input, subset="";
    cin >> input;

    printSubset(input, subset);
    
    return 0;
   
}

/*
Input 
abc

Output
a c b bc ac ab abc


Space complexity => O(1) 
Time complexity => O(2^n-1) if 'n' is the length of string
*/