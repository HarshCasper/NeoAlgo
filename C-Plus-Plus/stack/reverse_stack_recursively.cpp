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

#include<iostream>
#include<stack>
using namespace std;
void insertAtEnd(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    else
    {
        int data=s.top();
        s.pop();
        insertAtEnd(s,x);
        s.push(data);
    }
}
void reverse(stack<int>&s)
{
    if(s.empty())
    return;
    else
    {
        int x=s.top();
        s.pop();
        reverse(s);
        insertAtEnd(s,x);
    }
}
void show(stack<int>temp)
{
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
}
int main() {
    stack<int>s;
    cout<<"Enter data (-1 to exit) : ";
    int x;
    cin>>x;
    s.push(x);
    while(x!=-1)
    {
        cin>>x;
        if(x==-1)
        break;
        s.push(x);
    }
    cout<<"The stack is : ";
    show(s);
    reverse(s);
    cout<<endl<<"After reversal, the stack is as follows : ";
    show(s);
    return 0;
}

