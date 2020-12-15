//Question Print all possible subset using recursion

#include <iostream>
using namespace std;

void printSubset(string input, string subset){
   if(input.length() == 0){
       cout << subset <<" ";
       return;
   }
   
   string subset2 = subset + input[0];
   
   input.erase(input.begin() + 0);
   
   printSubset(input, subset);
   printSubset(input, subset2);
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

*/