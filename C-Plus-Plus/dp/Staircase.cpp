/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run-up to the stairs.
*/


#include<bits/stdc++.h>
using namespace std;

long staircase(int n)
{
    long *ans = new long[n+1];
    
    ans[0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        long x=0;
        long y=0;
        long z=0;
                    
        
        if(i-1>=0)
            x = ans[i-1];
        if(i-2>=0)
            y = ans[i-2];
        if(i-3>=0)
            z = ans[i-3];
        
        ans[i] = x+y+z;
    }
    
    long finalAns = ans[n];
    delete [] ans;
    return finalAns;
}

int main()
{
	int n;
  	cout<<"Enter the number of steps"<<endl;
	cin >> n;
  	cout<<"The total number of possible ways are:"<<endl;
	cout << staircase(n);
}


/*
Sample Input 1:
Enter the number of steps
4

Sample Output 1:
The total number of possible ways are:
7

Time Complexity: O(n)

Space Complexity: O(n)
*/
