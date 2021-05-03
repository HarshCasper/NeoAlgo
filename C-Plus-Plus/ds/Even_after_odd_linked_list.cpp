/* Print all even placed nodes in a linked list after odd placed nodes.

    Example:

    Given a Linked List 
    1->6->9->12->5->8->15->NULL

    So, all the even placed nodes will print after odd placed nodes.
    So, the Output should be::

    1->9->5->15->6->12->8->NULL     

*/

#include<bits/stdc++.h>
using namespace std;

//Creating a class named node
class node
{
    public:
        int data;
        node* next;

        //Creating a constructor
        node(int val)
        {
            data=val;
            next=NULL;
        }
};

//Creating a function to calc the length of the linked list
int length(node* &head)
{
    if(head==NULL)
        return 0;

    node* temp=head;
    int count=1;

    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    return count;
}

//Function to insert data in linked list
void insert(node* &head)
{
    int val;
    

    cin>>val;
    node* n=new node(val);

    if(head==NULL)
    {
        n->next=head;
        head=n;
        return;
    }

    node* temp=head;

    //Traversing to the last of the loop
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    temp->next->next=NULL;
    
}

//Function to display the linked list
void display(node* head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"NULL";
    cout<<endl;
}

//Function to add even node of the linked list after the odd nodes
void evenodd(node* &head)
{
    if(length(head) == 1 || length(head)== 0 || length(head)== 2)
    {
        display(head);
        return;
    }
    
    int l=length(head);
    node* even=head->next;
    node* odd=head;
    node* evenstart=head->next;

    while(odd->next!=NULL && even->next!=NULL)
    {
        if(even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
        }
        if(odd->next!=NULL)
        {
            even->next=odd->next;
            even=even->next;
        }
    }
            
    odd->next=evenstart;
    if( odd->next!=NULL)
        even->next=NULL;

}

int main()
{
    node* head=NULL;
    int n;
    cout<<"\n Entering the number of nodes you want to insert in a linked list::";
    cin>>n;

    cout<<"\n Enter the data in the linked list:";
    for(int i=0;i<n;i++)
        insert(head);
    
    cout<<"\n Linked list before changing ::";
    display(head);

    evenodd(head);
    cout<<"\n\n Linked list after changing ::";
    display(head);

    return 0;

}
 /*

 Time Complexity- O(l)
 Space Complexity- O(l)     where l is the length of the linked list

    Sample Testcase:
    ----------------

 Sample Input:

 Entering the number of nodes you want to insert in a linked list::7

 Enter the data in the linked list: 1 6 9 12 5 8 15 


 Sample Output:

 Linked list before changing ::1->6->9->12->5->8->15->NULL


 Linked list after changing ::1->9->5->15->6->12->8->NULL 

 */