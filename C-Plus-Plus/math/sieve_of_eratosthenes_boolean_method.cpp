#include <iostream>
#include <cstring>
using namespace std;
/*  
    Seive of Eratosthenes is the best method to find prime nubers till integer n.    
    The basic logic behind the method is to consider a boolean array of numbers till n,
    where initailly every number is considered to be prime(i.e, true).
    It iteratively marks the multiple of each prime number false(i.e,composite),
    starting from the first prime number 2.The multiples of a given prime number are marked in a sequnce starting from the square of the given prime number,
    with a constant difference between them which is equal to the prime number.

    Example:- Till n=50 we want to find the list of all prime numbers.
    __ 02 03 04 05 06 07 08 09 10
    11 12 13 14 15 16 17 18 19 20
    21 22 23 24 25 26 27 28 29 30
    31 32 33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48 49 50

Intially all numbers are considered prime.
Iteration 1:- We will start with 02, find all the multiples of 02 and mark them false.
Therefore starting from the square of the given prime number that is 04 in this case, making a jump of 02 and marking every multiple of 02 false.
Hence 04,06,08,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50 are marked false. 

Iteration 2:- We will move to the next prime number that is 03.
Notice that multiples of 03 like 06,12,...etc are already marked false by 02.That's why we start with the square multiple of the prime number.
Therefore starting with 09, making jumps of 03 and marking 09,15,21,27,33,39,45 false.

Iteration 3:- We will move to the next prime number 05 and start with its square, making jumps of 05 nad keep marking the multiples of 05 false.
Therefore 25,35, is marked false.

Iteration 4:-We will move to the next prime number 07 and start with its square, making jumps of 07 nad keep marking the multiples of 05 false.
Therefore 49 is marked false.

Finally we are left with only prime numbers,i.e, 02, 03, 05, 07, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47.

@author Anish Singh

*/
//Function
void seive_of_eratosthenes(int n)
{
    //Creating a boolean array of size n+1 where n is user given.
    bool prime[n + 1];
    //All values of the array are initially true.prime[i] will be false if i is a composite number.
    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= n; i++)
    {
        //Checking whether prime[i]==true,otherwise skip if it is marked false. 
        if (prime[i] == true)
        {
            //Checking for the multiples of i,starting from i^2 and making jumps of +i.
            for (int j = i * i; j <= n; j += i)
            {
                
                prime[j] = false;
            }
        }
    }
    //Printing all prime numbers.
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
        {
            cout << i << endl;
        }
    }
}

//Driver Function
int main()
{
    //code
    //Taking an input from user.
    int n;
    cout<<"Enter an integer value till where all the prime equal to or less than will be printed.:-   ";
    cin >> n;
    //Calling the function.
    seive_of_eratosthenes(n);
    return 0;
}


/*
    Time Complexity:- O(nlog(log(n)))
*/