/*
The next prime number p of a number n is a number such that
- p is greater than n.
- p is a prime number.
- There are no prime numbers between n and p.
*/

#include<bits/stdc++.h>
using namespace std;

int next_prime(int n){
    int p = n + 1;
    if(p<=1){
        return 2;
    }
    while(true){
        //consider that p is not a composite number
        bool flag = false;
        for(int i=2; i<=floor(n/2)+1; i++){
            //found a factor other than 1 or p
            if(p%i==0){
                p = p + 1;
                //p is composite
                flag = true;
                break;
            }
        }
        //p is prime
        if(flag==false){
            return p;
        }
    }
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Next prime number is "<<next_prime(n);
}

/* Sample I/O:
Enter a number : 55
Next prime number is 59

Time Complexity : O(n^2)
Space Complexity : O(1)
*/
