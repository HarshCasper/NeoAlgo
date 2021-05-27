/*
The program will count the number of prime numbers less than a non-negative number, 
n and will also print the prime numbers.
*/

#include <iostream>
using namespace std;
int prime_sieve(int n)
{
    //creating a bool type array 
    bool prime[n+1];
    //assiging true value (prime) to all the indices
    for(int i=2;i<n;i++)
        prime[i]=true;
    //checking if the value of i is prime or not
    for(int i=2;i*i<n;i++)
    {
        //if it is prime then we will assign false value (not prime) to all the multiples of i
        if(prime[i])
        {
            for(int j=i*2;j<n;j+=i)
                prime[j]=false;
        }
    }
    //cnt will store the count of prime numbers
    int cnt=0;
    //counting the prime numbers
    for(int i=2;i<n;i++)
    {
        if(prime[i])
        {
            cnt++;
        }
    }
    //if the count of prime numbers is not 0 then print the prime numbers 
    if(cnt!=0)
    {
        cout<<"The prime numbers are : ";
        for(int i=2;i<n;i++)
        {
            if(prime[i])
            {
                cout<<i<<" ";
            }
        }
    }
    //returning the count of prime numbers
    return cnt;
}

int main() {
    //n will accept the of non negative integer upto which the prime numbers have to be evaluated
    int n;
    cout<<"Enter the non negative integer upto which prime number and its count has to be printed : ";
    cin>>n;
    //calling function so as to give the required output and storing the count of prime numbers in the variable count
    int count = prime_sieve(n);
    //printing the count of prime  numbers
    cout<<endl<<"There are "<<count<<" prime numbers.";
    return 0;
}

/*
Sample Input 1 : Enter the non negative integer upto which prime number and its count has to be printed : 10
Sample Output :  
The prime numbers are : 2 3 5 7 
There are 4 prime numbers. 

Sample Input 2 : Enter the non negative integer upto which prime number and its count has to be printed : 1
Sample Output : 
There are 0 prime numbers.
*/

/*
Time Complexity : O(N log (log N))
Space Complexity : O(N)
*/
