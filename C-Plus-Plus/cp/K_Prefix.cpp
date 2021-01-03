//K Prefix
/* Given a list of integers nums and an integer k, 
return the maximum possible i where nums[0] + nums[1] + ...  + nums[i] ≤ k. 
Return -1 if no valid i exists.
*/

#include <bits/stdc++.h> 
using namespace std;

int k;
vector<int> nums;

//Finding the Max possible i value
int solve() {
    int res=0,pre=-1;
    for(int i=0;i<nums.size();i++)
    {
        res=res+nums[i];
        if(res<=k)
           pre=i;
        
    }
    if(pre==-1)
        return -1;    
    return pre;
}

//Taking input
void input()
{
	cout<<"Enter the value of k: "<<endl;
	cin>>k;
	cout<<"Enter the list of integers: "<<endl;
	int x;
	while(cin>>x)
	{
		nums.push_back(x);
	}
}
int main()
{
	input();
	int max_i=solve();
	cout<<"Max Possible i is: "<<max_i;
}

/*

Input: 
Enter the value of k: 4
Enter the list of integers: 3 -5 4 1 6

Output:
Max Possible i is: 3

Time Complexity: O(n)  Size of the array

*/