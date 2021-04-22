/* The program will used to convert any number 
    into any base provided by user */
    
#include <iostream>
#include <vector>
using namespace std;

void base(int n,int b)
{
	vector<int>a;
	int k=0;
	int q;
	q=n;
	while(q!=0)
	{
	    a.push_back(q%b);
	    q=q/b;
	    k++;
	}
	
	for(int i=a.size()-1;i>=0;i--)
	   cout<<a[i];
}

int main()
{
	int n; 
	cout<<"Enter a Number ";
	cin>>n;
	cout<<"Enter a Base ";
	int b;
	cin>>b;
	base(n,b); //calling the function
	
  return 0;
}
/*
Input :- 
12 2
Output :-
1100
*/

/*
Time Complexity :- O(n)
Space Complexity :- O(n)
*/

