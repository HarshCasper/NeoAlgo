/*
Euclidean algorithms 

Euclid's algorithm is an efficient method for computing the greatest common divisor (GCD) of two integers (numbers).
 
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2) 
{ 
   	if (num1 == 0) 
   		return num2; 
   	return gcd(num2 % num1, num1); 
} 

int main(){

    int num1 ,num2;
    cout<< "Enter two number : ";
    cin >> num1 >> num2;
    
    cout <<"GCD = "<< gcd(num1,num2);
    
    return 0;
}

/*
Input:
Enter two number : 5 7  

Output:                                                                                                                                    
GCD = 1 

Space complexity = O(1)
Time complexity = O(log(n))
*/
