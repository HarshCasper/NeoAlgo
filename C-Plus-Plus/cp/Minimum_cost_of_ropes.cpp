/*

*There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
*The task is to connect the ropes with minimum cost.

*Time Complexity : O(NLog(N))

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    long long minCost(long long arr[], long long n)
    {
        if (n == 1)
            return 0;
        priority_queue<long long, vector<long long>, greater<long long>> prio_que;

        for (int i = 0; i < n; i++)
        {
            //push elements in the priority queue
            prio_que.push(arr[i]);
        }
        long long ans = 0;
        //if size of queue is >1 then perform these
        while (prio_que.size() > 1)
        {
            //find 1st min element from min heap and pop
            long long a = prio_que.top();
            prio_que.pop();

            //find wnd min element from min heap and pop
            long long b = prio_que.top();
            prio_que.pop();

            //add it in answer
            ans = ans + (a + b);

            //store answer back in the priority queue
            prio_que.push(a + b);
        }
        return ans;
    }
};
long long minCost(long long arr[], long long n);
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

/*

*Test Cases
*Input:
*n = 5
*arr[] = {4, 2, 7, 6, 9}
*Output: 
*62 

*/