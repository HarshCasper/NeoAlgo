/*Problem Statement: 
You are given a sequence of integers A1,A2,…,AN. 
You may change any number of its elements (possibly zero), 
obtaining a new sequence of positive integers B1,B2,…,BN. 
Each element of B must be an integer between 2 and 50 (both inclusive).
Let's define an undirected graph G with N vertices (numbered 1 through N).
For each pair of different vertices i and j, there is an edge between i and j if and only if Bi and Bj are coprime.
You should choose the sequence B in such a way that G is a connected graph. 
The number of elements which need to be changed to obtain B from A should be minimum possible. 
Find one such sequence B and the minimum required number of changes.
It can be proven that a solution always exists — 
it is always possible to modify sequence A in such a way that G is connected. */

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

bool checkequal(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int vertices;
    cout<<"Enter the total number of vertices in the graph: "<<endl;
    cin>>vertices;
    int arr[100];
    cout<<"Enter edges: "<<endl;
    for(int i=0;i<vertices;i++)
    {
        cin>>arr[i];
    }
    list<int> list1;
    for(int i=0;i<vertices;i++)
    {
        list1.push_back(arr[i]);
    }
    vector<int> numbers;
    list<int> list2;
    int ans=0;
    while(!list1.empty())
    {
        numbers.push_back(list1.front());
        list1.pop_front();
        for(int i=0;i<numbers.size();i++)
        {
            while(!list1.empty())
            {
                int m=list1.front();
                list1.pop_front();
                if(gcd(m,numbers[i])==1)
                {
                    numbers.push_back(m);
                }
                else
                {
                    list2.push_back(m);
                }
            }
            list1=list2;
            list2.clear();
        }
        ans++;
        numbers.clear();
        if(ans>1)
        {
            break;
        }
        if(ans==1)
        {
            cout<<"Minimum required changes: "<<"0"<<endl;
            cout<<"Modified subsequence: "<<endl;
            for(int i=0;i<vertices;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else if(checkequal(arr,vertices))
        {
            if(arr[0]==47)
            {
                arr[0]=2;
            }
            else
            {
                arr[0]=47;
            }
            cout<<"Minimum required changes: "<<"1"<<endl;
            cout<<"Modified subsequence: "<<endl;
            for(int i=0;i<vertices;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
            else
            {
                arr[0]=47;
                cout<<"Minimum required changes: "<<"1"<<endl;
                cout<<"Modified subsequence: "<<endl;
                for(int i=0;i<vertices;i++)
                {
                cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
    }
    return 0;
}
/*
Example:-

Input:-
Enter the total number of vertices in the graph:
2
Enter edges: 
2 3

Output:-
Minimum required changes: 0
Modified subsequence: 
2 3 

Time Complexity: O(n)
Space Complexity: O(n)
*/

