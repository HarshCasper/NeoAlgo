//Power of 2 (Naive Approach)
//Time Complexity : O(logn)
//Space Complexity: O(1)

/*Sample Input:
Example 1:- 
Enter number
5
Example 2:-
Enter number
32

Sample Output:
Example 1:- No
Example 2:- Yes
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number \n";
	cin>>n;
	int f =1;
	if(n==0)
	cout<<"No"<<"\n";
	else
	{
		while(n!=1)
		{
			if(n%2!=0)
			{
				f=0;
				break;
			}
			n=n/2;
			
		}
	}
	if(f==0)
	cout<<"No"<<"\n";
	else
	cout<<"Yes"<<"\n";
	
	  
	  
}
