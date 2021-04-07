/* Two stacks are kept: One is for pushing and popping elements as they come and go (elements stack), and the other is for keeping track of the maximum element (maximum elements stack).
When the first element arrives, push it onto both of the stacks. As the elements may not be distinct, we need to keep track of their indices. So, declare a stack of pair<int,int> or use a structure.*/
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    stack<pair<int,int> > ele, maxi;
    int n, i = 1;
    cin>>n;
    while(i <= n)
    {
        int t, v;
        pair<int, int> p1, p2;
        cin>>t;
        if(t == 1)
        {
            cin>>v;
            ele.push(make_pair(v, i));
            if(maxi.size() == 0)
            {
                maxi.push(make_pair(v, i));
            }
            else
            {
                p1 = maxi.top();
                if(p1.first < v)
                {
                    maxi.push(make_pair(v, i));
                }
            }
        }
        else if(t == 2)
        {
            p1 = ele.top();
            ele.pop();
            p2 = maxi.top();
            if(p1.first == p2.first && p1.second == p2.second)
            {
                maxi.pop();
            }
        }
        else
        {
            p1 = maxi.top();
            cout<<p1.first<<endl;
        }
        i++;
    }
    return 0;
}

/*  Time Complexicity: O(n)             Space Complexicity: O(n)
 
 TEST CASE:1
 INPUT: 10              OUTPUT: 26
        1 97                    91
        2
        1 20
        2
        1 26
        1 20
        2
        3
        1 91
        3
        
 TEST CASE:2
 INPUT: 4              OUTPUT: 83 
        1 83
        3
        2
        1 76
    
    */
