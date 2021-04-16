#include<bits/stdc++.h>
using namespace std;
void Zeckendorf_Theorem(int n)
{
    while (n > 0) {
       //find the number equal or smaller than n
         
     if (n == 0 || n == 1)
        int F=n;
  
  //assigning first two conditions
  //calculating other by the sum of last two
     int a=0,b=1,c=1;
     while(c<=n)
     {
     	
     	a=b;
     	b=c;
     	c=a+b;
	 }
          int F=b;
  
        // Print the number
        cout << F << " ";
  
        // Reduce n
        n = n - F;
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    int n;
    //write the number
    cin>>n;
    Zeckendorf_Theorem(n);
	}
    return 0;
}