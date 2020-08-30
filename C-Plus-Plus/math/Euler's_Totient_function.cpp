// Euler's Totient Function represented by F(n)
// denotes the no. of coprime of n from 1 to n
#include <bits/stdc++.h>
using namespace std;
int F(int n){
    int arr[n + 1], i, j;
    arr[0] = 0, arr[1] = 1;     // as 1 is coprime with itself
    for(i = 2; i <= n; i ++){
     arr[i] = i;    // initialising arr[i] with i
     }  
    for(i = 2; i <= n; i ++){
        if(arr[i] == i){
            for(j = i; j <= n; j += i){
                arr[j] -= (arr[j] / i); // just like sieve of eratosthenes we are decreasing values of multiple of primes
            }  
        }
    }
    return arr[n];  //  here each arr[i] is giving number of coprimes of i from 1 to i
}

int main(){
    int n;
    cout<<"Enter a integer: " ;
    cin>>n;   // taking input as integer n
    cout<<F(n); // printing Euler's Totient Function for int n
return 0;
}
// time complexity O(nloglogn) same as sieve of eratosthenes
/*
Sample Input: 4
Sample Output: 2
Explanation: As 4 is coprime with 1 and 2 only so its Euler's Totient function value is 2;

Sample Input: 5
Sample Output: 4
Explanation: As 5 is a prime no. so it is coprime with all 1, 2, 3 & 4.
             So, its Euler's Totient Function value is 4;

*/
