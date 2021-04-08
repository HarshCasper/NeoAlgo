/* This algorithm will represent a number n(>1) as product of prime numbers.
 For example, if the input is 12 then output will be 2 2 3 , if input is 28 then output will be (2,2,7).
 Two concepts are used here. Firstly , through sieve of erathosthenes we will find all the prime numbers till n.
 Then we will check which prime numbers can divide n and for how many times*/

#include<iostream>
#include <cmath>
using namespace std;

void prime_factors(int n)
{
    //Applying sieve of erathosthenes to store the prime numbers till n
    int arr[n+1]={0};
    arr[1]=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(arr[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0)    //checking if i is prime
        {
         while(n%i==0)   //while i divides n, print i and keep on dividing n by i
         {
            cout<<i<<" ";
            n=n/i;
         }
        }
    }  
     return;
}
//Driver Code
int main()
{
    int num;
    cin>>num;
    prime_factors(num);
     return 0;
}
/* sample input: 12
   sample output: 2 2 3

   sample input: 24
   sample output: 2 2 2 3

   Time Complexity: O(n*log(log(n)) + log(n) + n)
   for sieve of erathrosthenes => O(n*log(log(n)))
   for printing the prime factors => O(n+ log(n))
   Space Complexity: O(n) */
