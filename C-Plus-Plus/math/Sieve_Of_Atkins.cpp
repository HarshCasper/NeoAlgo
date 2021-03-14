/*
	Sieve of Atkin is a modern algorithm for finding all prime numbers up to a
	specified integer. Compared with the ancient Sieve of Eratosthenes, which
	marks off multiples of primes, the Sieve of Atkin does some preliminary work
	and then marks off multiples of squares of primes, thus achieving a better 
	theoretical asymptotic complexity.
 	
 	We are going to check the following condition and according to that we
 	decide prime numbers
 	a) a = (4*i*i)+(j*j) has odd number of  
       solutions, i.e., there exist 
       odd number of distinct pairs (i, j)  
       that satisfy the equation and 
        n % 12 = 1 or n % 12 = 5. 
    b) n = (3*i*i)+(j*j) has odd number of  
       solutions and n % 12 = 7 
    c) n = (3*i*i)-(j*j) has odd number of  
       solutions, i > j and n % 12 = 11 
	   
*/


#include<iostream>		//Header file
using namespace std;	//For cin and cout


int Sieve_Of_Atkin(int n) 
{ 
    // Printing 2 and 3 as prime numbers 
    if (n > 2) 
        cout << 2 << " "; 
    if (n > 3) 
        cout << 3 << " "; 
    // Creating a array of boolean type of size n and
	// initialize it with false value    
    bool sieve[n]; 
    for (int i = 0; i < n; i++) 
        sieve[i] = false; 
		
	// Iterating over the numbers
	//If it is prime we make sieve[a]=true  
    for (int i = 1; i * i < n; i++) { 
        for (int j = 1; j * j < n; j++) { 
              
            // Making equations for prime numbers 
            int a = (4 * i * i) + (j * j); 
            if (a <= n && (a % 12 == 1 || a % 12 == 5)) 
                sieve[a] = true; 
  
            a = (3 * i * i) + (j * j); 
            if (a <= n && a % 12 == 7) 
                sieve[a] = true; 
  
            a = (3 * i * i) - (j * j); 
            if (i > j && a <= n && a % 12 == 11) 
                sieve[a] = true; 
        } 
    } 
  
    // Mark all multiples of squares as non-prime 
    for (int k = 5; k * k < n; k++) { 
        if (sieve[k]) { 
            for (int i = k * k; i < n; i += k * k) 
                sieve[i] = false; 
        } 
    } 
  
    // Printing prime numbers greater than 3
    for (int i = 5; i < n; i++) 
        if (sieve[i]) 
            cout << i << " "; 
} 
  
// Main() Function 
int main() 
{ 
    int n;
	cin>>n;					        //Taking input from user
    Sieve_Of_Atkin(n); 		//Calling function
    return 0; 
} 


/*
	Sample input :
 	43
 	Sample output:
 	2 3 5 7 11 13 17 19 23 29 31 37 41
	Time Complexity -O(n/(log(logn)))
	Space Complexity-O(n^0.5)
	
*/

