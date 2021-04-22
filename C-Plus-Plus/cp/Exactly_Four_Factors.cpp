/*
A number has exactly 4 factors if below given any condition is satisfied
 1.If the number is a cube of a prime number.
 2.If the number is a product of two distinct prime numbers.
*/

#include <bits/stdc++.h>
using namespace std;

// maxi gives the range of numbers
int maxi = 1000;
//arr contain the 1 value for the numbers which has exactly 4 factors
int arr[1000]={0};

void check() 
{
	//Implementing Sieve of Eratosthenes for checking prime numbers upto maxi
	int primeNumbers[maxi + 1];
	for(int i=0;i<maxi+1;i++)
		primeNumbers[i]=1;
		
	for (int i = 2; i <= sqrt(maxi); i++)
	{
	    if (primeNumbers[i])
		{
	    	for (int j = i * 2; j <= maxi; j += i)
	        primeNumbers[j] = 0;
	    }
	}
	
  // Creating a array of dynamic size containing all prime numbers upto maxi	
	vector<int> temp;
	for (int i = 2; i <= maxi; i++)
	    if (primeNumbers[i])
	        temp.push_back(i);
	
	for (int i = 0; i < temp.size(); ++i)
	{
		int x = temp[i];
		//If the number is a cube of a prime number, then it has exactly 4 factors
	  	if (1 *(pow(x, 3)) <= maxi)
	    	arr[x*x*x] = 1;
	    	
	      //If the number is a product of two distinct prime numbers,then it has exactly 4 factors
	  	for (int j = i + 1; j < temp.size(); ++j)
		{
	    	int y = temp[j];
	     	if (1 * x*y > maxi)
	        break;
	     	arr[x*y] = 1;
	   }
	}
}

int main()
{
    int num;
    cout<<"Enter the number you want to check: ";
    cin>>num;
    check();
    if(arr[num])
       cout<<num<<" has exactly four factors\n";
    else
       cout<<num<<" does not have exactly four factors\n";
    return 0;
}


/* 
  Sample Input/Output:
  
  Enter the number you want to check: 
  Input: num=27
  Output: 27 has exactly four factors
  
  Enter the number you want to check: 
  Input: num=109
  Output:109 does not have exactly four factors

  Time complexity-O(Nlog(log(N)))
  Space complexity-O(N)
*/
