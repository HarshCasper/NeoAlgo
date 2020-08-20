/* input q queries and return count of prime numbers in given range a and b
    
    Constraints: Q <= 1000000000
                 a and b <= 1000000000
   Sample input: 2
                 1 10
                 11 20
   input line 1 is no. of queries Q, line 2 and 3 are the range between prime number have to be checked
   
   Sample output: 4
                  4
   
   Explaination: prime numbers between range 1 and 10 are 4 i.e., 2,3,5,7. So, print 4.
   using Sieve Erastosthenes to find prime number upto maximum number i.e.,1000000000 then calculate cummulative sum upto 1000000000 and return count of prime numbers between given range. 				            

*/

#include<iostream>
using namespace std;

/*prime sieve method */
void prime_sieve(int *p,int n)
{
	for(int i=3; i<=n; i +=2)
	{
		p[i] = 1;
	}
	for(int i=0; i<=n; i = i+2)
	{
		for(long long j = i*i; j<=n; j= j+i)
		{
			p[j] = 0;
		}
		
	}
	//special case for 2
	p[2] = 1;
	p[1] = p[0] = 0; // 1,0 are not prime
}

int main()
{
	int n = 1000000000;
	int *p = new int[n]{0};
	int csum[n] = {0};
	
	prime_sieve(p,n);
	
	for(int i=1; i<=n; i++)
	{
		csum[i] = csum[i-1] + p[i];
	}
	int q;
	cin>>q;
    
	while(q--)
	{
		int a,b;
	   cin>>a>>b; //input range
	   cout<<csum[b] - csum[a+1]<<endl;	
	}
	return 0;	
	
}
