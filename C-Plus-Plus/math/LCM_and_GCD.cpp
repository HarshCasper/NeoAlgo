//LCM and GCD between two numbers

#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2) 
{ 
   	if (num1 == 0) 
   		return num2; 
   	return gcd(num2 % num1, num1); 
} 
int lcm(int num1, int num2) 
{ 
	return (num1*num2)/gcd(num1, num2); 
} 

int main(){

    int num1 ,num2;
    cout<< "Enter the number : ";
    cin >> num1 >> num2;
    
    cout <<"LCM = " << lcm(num1,num2) << endl << "GCD = "<< gcd(num1,num2);
    
    return 0;
}

/*
Input:
Enter the number : 5 7  

Output:
LCM = 35                                                                                                                                      
GCD = 1 


space complexity = O(1)
time complexity = O(1)
*/