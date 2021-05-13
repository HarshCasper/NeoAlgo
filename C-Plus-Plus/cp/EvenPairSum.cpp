/*
Two positive integers A and B are given. Find the number of pairs 
of positive integers (X,Y) such that 1=X=A, 1=Y=B and X+Y is even.
Input
The first line of the input contains a single integer T denoting the
number of test cases.The description of T test cases follows.
The first and only line of each test case contains two space-separated 
integers A and B.
Output
For each test case, print a single line containing one integer-the number
of valid pairs.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //t=test case
    int t; 
    cin>>t;
    while(t--)
         {
	    long long c,d;
	    long long ans=0;
	    cin>>c>>d;
	    long long a=min(c,d);
	    long long b=max(c,d);
	    if(a%2==0)
	    {
	        if(b%2==0)
	        {
	            ans=2*(a/2)*(b/2);
	            cout<<ans<<endl;
	            continue;
	        }
	        else
	        {
	            long long x=(a/2)*(b/2),y=(a/2)*((b/2)+1);
	            cout<<x+y<<endl;
	            continue;
	            
	        }
	    }
	    else
	    {
	       if(b%2==0)
	        {
	            long long x=(a/2)*(b/2),y=((a/2)+1)*(b/2);
	            cout<<x+y<<endl;
	            continue;
	        }
	        else
	        {
	            
	            long long x=(a/2)*(b/2),y=((a/2)+1)*((b/2)+1);
	            cout<<x+y<<endl;
	            continue;
	        } 
	    }	    
	}
	
	return 0;
}
/*
Example Input
4
1 1
2 3
4 6
8 9
Example Output
1
3
12
36

time complexity- O(t)
//t is no. of test cases
*/
