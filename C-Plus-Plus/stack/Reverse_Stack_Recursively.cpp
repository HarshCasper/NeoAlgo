//To reverse the elements of the stack recursively
//Time complexity:  O(n^2)
//Space Complexity: O(n)

//Sample Input:
/*Example 1:-
Enter data (-1 to exit) : 1 2 3 4 5 -1
The stack is : 5 4 3 2 1
After reversal, the stack is as follows : 1 2 3 4 5

Example 2:-
Enter data (-1 to exit) : 45 22 55 78 90 10 34 -1
The stack is : 34 10 90 78 55 22 45
After reversal, the stack is as follows : 45 22 55 78 90 10 34
*/

#include<bits/stdc++.h>
using namespace std;
void insertAtEnd(stack<int>&a,int x)
{
    if(a.empty())
    {
        a.push(x);
        return;
    }
    else
    {
        int data=a.top();
        a.pop();
        insertAtEnd(s,x);
        a.push(data);
    }
}
void reverse_stack(stack<int>&a)
{
    if(a.empty())
    return;
    else
    {
        int x=a.top();
        a.pop();
        reverse(a);
        insertAtEnd(a,x);
    }
}
void print_stack(stack<int>temp)
{
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
}
int main() {
    stack<int>a;
    cout<<"Enter data (-1 to exit) : ";
    int x;
    cin>>x;
    s.push(x);
    while(x!=-1)
    {
        cin>>x;
        if(x==-1)
        break;
        a.push(x);
    }
    cout<<"The stack is : ";
    print_stack(a);
    reverse_stack(a);
    cout<<endl<<"After reversal, the stack is as follows : ";
    print_stack(a);
    return 0;
}

