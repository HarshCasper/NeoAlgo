/*
Problem Desciption:
The problem states that, there are N students in the class, i'th student has assign Ci number of task. Your task is to determine if it is possible to redistribute C1 + C2 + ... + Cn task among the student of class thus that i'th student would get i task.
*/

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    int sum_of_i_student=0;
    int sum_of_task=0;
    for(int i=1;i<=n;i++)
    {
        sum_of_i_student=sum_of_i_student+i;
        int a;
        cin>>a;
        arr.push_back(a);
        sum_of_task=sum_of_task+a;
    }
    if(sum_of_i_student==sum_of_task)cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

/* 
Test case :
2
5
7 4 1 1 2
5
1 1 1 1 1
output
YES
NO
*/