/* This is a use of Sieve of Eratosthenes algorithm.
In this We can find all unique prime factor of any number n.For example if n is 12 then output will be 2,3
In this first we store all prime factor of numbers till n and then print prime factors of n. */

#include <bits/stdc++.h>
using namespace std;

void unique_prime(int n){
  int arr[n+1];
  memset(arr , 1 , n+1);
  //first find all prime factors till n by sieves method 
  for(int i = 2 ; i <= sqrt(n) ; i++) {
    if(arr[i]==0){
      continue;
    } 
      for(int j = i*i ; j <=n ; j += i){
        arr[j] = 0;
      
    }
  }
  //now check which prime number are factor of n
  cout<<"All unique prime factors of "<<n<<" are: ";
  for(int i=2; i<=n; i++){  
    if(arr[i] == 0 && n%i == 0 ) {
      cout << i <<"  ";
    }
  }
}

int main() {
  int num;
  cout<<"Enter the number: ";
  cin >> num;
  unique_prime(num);
}

/* Sample Input
   Enter the number: 5446
   Sample output
   All Unique prime factors of 5446 are: 2  7  389 
*/
/* Time complaxity : O(n + n(log(logn)))
   Space Complaxity : O(n)
*/
