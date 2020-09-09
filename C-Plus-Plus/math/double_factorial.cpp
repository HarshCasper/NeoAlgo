//double factorial  of a number n (denoted by n!!) is the product of all the integers from 1 up to n that have the same parity(odd or even) as n.

//algorithm to find the double factorial of a number n in O(n) time complexity and O(1) space complexity

#include <bits/stdc++.h>
using namespace std;

int Recursive(int num)   //recursive approach
{
    if (num == 0 || num == 1) 
        {
            return 1;
        }
    return num * Recursive(num - 2);
}

int Iterative(int num)   // Iterative approach
{
    int ans = 1;
    for (int i = num; i >= 0; i = i - 2) 
    {
        if (i == 0 || i == 1) 
        {
            return ans;
        } 
        else 
        {
            ans*=i;
        }
    }
    return ans;
        
}

int main() {
    //taking input from the user
    int num;
    cout << "Please Enter a number\n";
    cin >> num;
    cout << "Which way would you like to use?\n";
    cout << "1. Iterative\n";
    cout << "2. Recursive\n";
    int way;
    cin >> way;
    if (way == 1)
    {
        cout << Iterative(num) << endl;
    }
    else if (way == 2)
    {
        cout << Recursive(num) << endl;
    }
    else
    {
        cout << "Invalid choice" << endl;
    }    
    
    
    return 0;
}

/*
  Sample input/output
  Enter the number:
  13
  Which way would you like to use?
  1 Iterative
  2 Recursive
  
  Output  = 135135
 */
