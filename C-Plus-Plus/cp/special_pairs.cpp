/*Problem Statement: 
Given integers N and M, 
find the number of ordered pairs (a,b) such that 1≤a<b≤N and ((M mod a) mod b)=((M mod b) mod a). */

#include<bits/stdc++.h>
using namespace std;

int special_pair(int total,int number)
{
	int count=0;
	unordered_map<int,int> mp;
	for(int i=1;i<=total;i++)
    {
        int pair1=number%i;
        mp[i]=pair1;
    }
    for(auto it: mp)
    {
        int k=it.first;
        for(int j=k+1;j<=total;j++)
        {
            int temp=number%j;
           	int pair1=temp%(it.first);
            int pair2=(it.second)%j;
            if(pair1==pair2)
           	{
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int total,number;
    cout<<"Enter total number of integers and the number: "<<endl;
    cin>>total>>number;
    cout<<"Total special pairs: "<<special_pair(total,number)<<endl;
    return 0;
}
/*Example:-

Input:-
Enter total number of integers and the number: 
3 5

Output:-
Total special pairs: 2

Time Complexity: O(nlogn)
Space Complexity: O(nlogn)
*/

