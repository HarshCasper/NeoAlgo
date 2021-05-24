/*****

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
3→10→5→16→8→4→2→1

Your task is to simulate the execution of the algorithm for a given value of n.

Input

The only input line contains an integer n.

Output

Print a line that contains all values of n during the algorithm.

Example :
Input:
3

Output:
3 10 5 16 8 4 2 1

*****/


#include<iostream>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    while(true)
    {
        cout << n << " "; 
        // breaking here coz finally we have to reach here
        if (n == 1) break; 
        // main condition that if n is even then change it to its half otherwise multiply by 3 and add 1
        if (n%2 == 0) n /= 2;    
        else n = n*3+1;
    }
    cout << "\n";               
    return 0;
}



/***

Time complexity of this program O(n)

Input:
3

Output:
3 10 5 16 8 4 2 1

*****/
