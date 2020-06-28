#include<iostream>        //Header file
using namespace std;      //For cin and cout

/*
    Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
    It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with
    the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime,
    with constant difference between them that is equal to that prime.

    Sample Input : 
    10 
    Sample Output: 
    2 3 5 7

    @author Aditya Saxena
    @since 28-7-2020
*/

//Implement prime sieve function, it will store 0 in the primes array if that index is composite and 1 if prime
void prime_sieve( int primes[], int n){

    //Make 2 as prime (only prime even number)
    primes[2]= 1;

    //Put 1 at all odd positions starting from 3
    for( int i= 3; i< n; i += 2 ){
        primes[i]= 1;
    }

    //Make all multiples of odds as composite, i.e, 0
    for( int i= 3; i< n; i += 2 ){

        //Check prime(i.e, 1){
        if( primes[i] == 1 ){
               
            //Make all multiples of i as composite
            for( int j= i*i; j< n; j += i ){
                primes[j]= 0;
            }

        }
    }
    
    return;
}

//Driver Function
int main(){

    int n = 10;
    cout<<"Enter the number upto which prime numbers are to be computed: ";
    cin>>n;

    //Create an array of size n+1 initialized with 0 
    n++;
    int primes[n]= {0};

    //Call prime sieve function
    prime_sieve(primes, n);

    //Print all primes upto n
    cout<<endl;
    for( int i= 0; i< n; i++ ){
        if( primes[i] == 1 ){
            cout<<i<<" ";
        }
    }

    return 0;
}
