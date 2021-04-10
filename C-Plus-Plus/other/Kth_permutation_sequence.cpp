/* 
Kth - Permutation Sequence 

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence in the string type.

*/

#include <bits/stdc++.h>
using namespace std;

string Solve(int n, int k)
{
    // factorial is the variable to store the n!
    long long int factorial = 1;
    // vector to store the number from 1 to n
    vector<int> num;
    for(int i = 1;i < n;i++)
    {
        factorial = factorial * i;
        num.push_back(i);
    }
    num.push_back(n);
    // str variable to store the ans or kth sequence
    string str = "";
    k = k - 1;
    while(true){
        // adding the k / factorial number in the string
        str += to_string(num[k / factorial]);
        // erasing the element from the vector as it is already added in the string
        num.erase(num.begin() + k / factorial);
        if(num.size() == 0){
            break;
        }
        // updating the k
        k %= factorial;
        // updating the factorial
        factorial /= num.size();
    }
    return str;
}

int main()
{
    int testCases;
    cout << "Enter the number of testcases: ";
    cin >> testCases;
    while(testCases--){
        //n is the size of the each permutation
        int n; 
        cout<<"Enter the number n: ";
        cin>>n;
        // k is the kth - permutation in the set of n!
        int k;
        cout<<"Enter the number k: ";
        cin>>k;
        string ans = Solve(n,k);
        cout<<"The kth permutation is: '"<<ans<<"'"<<endl;
    }
    return 0;
}

/*

FOR EXAMPLE:--

Example 1:
Input:-
Enter the number of testcases: 2
Enter the number n: 4
Enter the number of k: 17
Enter the number n: 3
Enter the number k: 2
Output:-
The kth permutation is: '3412'
The kth permutation is: '132'


SPACE COMPLEXITY = O(n)(Storing the ans string)
TIME COMPLEXITY = O(n ^ 2)

*/
