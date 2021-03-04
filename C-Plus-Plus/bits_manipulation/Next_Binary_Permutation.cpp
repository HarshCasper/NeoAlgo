// Next Binary Permutation
/*
For given N return the smallest next higher integer with the same number of 1s as n in binary representation.

Input
n = 3
Output
5
*/

#include<bits/stdc++.h> 
using namespace std;

// This code will work only for n < 10^9, further time lime exceeded. 

// int solve(int n) {
//     int ans = __builtin_popcount(n);
//     int res;
//     for(int i=n+1;;i++){
//         if(__builtin_popcount(i) == ans){
//             res = i;
//             break;
//         }
//     }
//     return res;
// }


// Efficient Approach: Using lsb (n&-n)
int solve(int n) {
    if (n == 0)
            return n;
    int sum = 0;
    while (n-(n&-n)>0) {
        int lsb = -n&n;
        n -= lsb;
        if(2*lsb!=(-n&n))
            return sum+n+2*lsb;
        sum = sum*2+1;
    }
    return sum+2*n;
}

int main(){
    int n; cin>>n;
    cout<<solve(n)<<endl;
}

/* n = 536870915 
output = 536870917

for the above testcases, time lime exceeded by first approach 
*/