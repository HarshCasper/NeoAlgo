/* 
A special number is a number in which the sum of factorial of 
digits is equal to the number itself.
Example-145 as 145=1!+4!+5!
*/


#include <iostream>
using namespace std;

int special(int x)
{
    int t=x,b=0,f,sum=0,i;
    while(x!=0)
    {
        b=x%10;
        f=1;
		/*To calculate factorial of each digit*/
        for(i=1;i<=b;i++)
        f=f*i;
		/* To store the sum of factorial of digits*/
        sum=sum+f;
        x=x/10;
    }
    if(sum==t)
    return 1;
    else
    return 0;
}
/*Main function*/
int main() {
	// your code goes here
	int n;
	cout<<"Enter a number to check special or not\n";
	cin>>n;
	int a;
	/*Calling the function special*/
	a=special(n);
	if(a==0)
	cout<<"It is not a special number.\n";
	else
	cout<<"It is a special  number.\n";
	return 0;
}

/*
Time Complexity:O(n)
Space Complexity:O(1)

Input/Output:
Enter a number to check special or not 150
It is not a special number.
*/
