/*
Description : 
        We have to find wether the number is power of 2 or not . If it is then return yes else no 
*/

#include<bits/stdc++.h>
using namespace std;

bool power_of_2(int n)
{
	// if zero then it will return true
	return (n&& !(n&n-1));
}
int main()
{
	int num;
    cout<<"Enter the number : "<<endl;
	cin>>num;
	power_of_2(num)? cout<<"Yes\n": cout<<"No\n";
}

/*
Time complexity : O(1)
Space complexity : O(1)
*/

/*
Input :
Enter the number : 
64

Output :
Yes

*/

