/*Problem Statement: 
In a hotel,there is exactly one room for every integer, including zero and negative integers.
Even stranger, the hotel is currently at full capacity, meaning there is exactly one guest in every room. 
The hotel's manager,
decides he wants to shuffle the guests around because he thinks this will create a vacancy (a room without a guest).
For any integer k and positive integer n, let kmodn denote the remainder when k is divided by n. 
More formally, r=kmodn is the smallest non-negative integer such that k−r is divisible by n. 
It always holds that 0≤kmodn≤n−1. For example, 100mod12=4 and (−1337)mod3=1.
Then the shuffling works as follows. There is an array of n integers a0,a1,…,an−1. 
Then for each integer k, the guest in room k is moved to room number k+akmodn.
After this shuffling process, determine if there is still exactly one guest assigned to each room. 
That is, there are no vacancies or rooms with multiple guests. */

#include<bits/stdc++.h>
using namespace std;

string strange_hotel(int len,int arr[],vector<int> vis)
{
    for (int i = 0;i < len; ++i)
    {
        int x = (arr[i] % len + len) % len;
        x = (x + i) % len;
        vis[x]++;
    }
    string ans = "YES";
    for (int i = 0; i < len; ++i)
    {
        if (vis[i] == 0)
        {
            ans = "NO";
        }
    }
    return ans;
}

int main()
{
        int len; 
        cout<<"Enter length of the array: "<<endl;
        cin >> len;
        int *arr=new int[len];
        vector<int> vis(len, 0);
        cout<<"Enter array: "<<endl;
        for (int i = 0; i < len; ++i)
        {
            cin >> arr[i];
        }
        string str=strange_hotel(len,arr,vis);
        cout << "Is only one guest staying in one room? " << str << endl;
        return 0;
}
/*Example:-

Input:-
Enter length of the array:
1
Enter array:
14

Output:-
Is only one guest staying in one room? YES

Time Complexity: O(n)
Space Complexity: O(n)
*/

