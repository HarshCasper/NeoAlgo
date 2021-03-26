//This is a use of Sieve of Eratosthenes algorithm.
//In this We can find all unique prime factor of any number n.For example if n is 12 then output will be 2,3
//In this first we store all prime factor of numbers till n and then print prime factors of n.

#include<bits/stdc++.h>
using namespace std;
void unique_prime(int num) {
  int arr[num+1];
  for(int i = 1 ; i <= num ; i++) {
    arr[i]=1;
  }
  map<int ,vector<int>> m;
  //now store all prime factor in vector of respective key in map
  for(int i=2 ; i <= num ; i++) {
    if(arr[i] == 0) {
      continue;
    }
    for(int j=i ; j <= num ; j=j+i) {
      m[j].push_back(i);
      arr[j]=0;
    }
  }
  //print vector when key is n
  for(int i=0 ; i < (m[num].size()) ; i++){
    cout<<m[num][i]<<"  ";
  }
  return;
}
int main(){
  int n;
  cin>>n;
  unique_prime(n);
  
}

/* Sample Input: 24
   Sample output: 2  3

   Test case_1 Input: 111
   Test case_1 Output: 3  37

   Test case_2 Input:5446
   Test case_2 Output: 2  7  389
*/
/* Time complaxity : O(n*n)
   Space Complaxity : O(n*n)
*/
