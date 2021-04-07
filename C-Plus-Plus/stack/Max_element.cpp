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