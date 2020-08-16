//CPP program to prime factorize a number using sieve
#include<iostream>
#include<vector>
using namespace std;
int a[1000001];
//Created Sieve to efficiently handle the queries to calculate the prime factorization
void sieve()
{
	int maxm=1000000;
	for(int i=0;i<=maxm;i++)
		a[i]=-1;
	for(int i=2;i<=maxm;i++)
	{
		if(a[i]==-1)
		{
			for(int j=i;j<=maxm;j+=i)
				if(a[j]==-1)
					a[j]=i;
		}
	}
}
//Main Function
int main()
{
	sieve();
	int n;
	//Enter the number
	cin>>n;
	 vector<int> v;
    while (n != 1) 
    { 
        v.push_back(a[n]); 
        n /= a[n]; 
    }
    //Output the prime factorizaion of the number
    for(auto x:v)
    	cout<<x<<" "; 
}
/* Author -Chandan Kumar Sahu(@chandansahuji)
Sample input:
n=30
Sample output:
2 3 5
Time Complexity-O(logn)
Space Complexity-O(n)

**To increase the range, update the array size and maxm
*/