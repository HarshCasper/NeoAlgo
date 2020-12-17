//Print N-bit binary numbers having more 1s than 0s using recursion

#include <iostream>
using namespace std;

void solve(int number,int one,int zero,string digit){
    if(number == 0){
        cout << digit <<" ";
        return;
    }
    
    string digit2 = digit;
    digit2.push_back('1');
    solve(number-1, one+1, zero, digit2);
    
    if(one > zero){
        string digit2 = digit;
        digit2.push_back('0');

        solve(number-1, one, zero+1, digit2);
    }

}

int main()
{
    int number;
    cin >> number;
    
    int one=0, zero=0;
    string digit="";
    solve(number, one, zero, digit);
    
    return 0;
}

/*
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than or equal 1's than 0's

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more than or equal 1's than 0's

Time complexity O(2^n)
Space complexity O(2^n)

*/