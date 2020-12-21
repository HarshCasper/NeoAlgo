/**
Josephus problem is a famous problem.
In each iteration we kill the every kth 
person in a circular arrangement of n persons.
Find the person who is alive at the end.
0-based indexing
link to the problem : https://en.wikipedia.org/wiki/Josephus_problem
**/

#include <iostream>
using namespace std;

int solution(int n, int k){
    if(n == 1)
      return 0;
    return (k+solution(n-1,k))%n;
}

int main() {
    int people, gap;
    cin >> people >> gap;
    cout << solution(people, gap) << '\n'; 
    return 0;
}

/**

Input : 
4 2 
Output :
0 

Time Complexity : O(n)
Space Complexity : O(1)

**/