/*

Author: Mohim Singla


C++ program to merge alternate nodes two linked lists.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

//Creating a struct
struct node{
int data;
node *next;
};

//Function to create linked list
struct node* create(int n)
{

    struct node* head=NULL;
    struct node* tail=NULL;
    while(n!=0)
    {
        int x;
        cin>>x;
        if (head==NULL)
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            head=temp;
            tail=head;
        }
        else
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            tail->next=temp;
            tail=temp;
        }
        n--;
    }
    return head;
}
struct node* head=NULL;
struct node* tail=NULL;

//Function to create linked list
struct node* new_list(int x)
{

        if (head==NULL)
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            head=temp;
            tail=head;
        }
        else
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            tail->next=temp;
            tail=temp;
        }

    return head;
};

//Create Merged linked list function
struct node* merge_list(struct node* list1, struct node* list2,int y)
{
    node* list3=NULL;
    node* temp1=list1;
    node* temp2=list2;
    while(y!=0)
    {
        list3=new_list(temp1->data);
        list3=new_list(temp2->data);
        temp1=temp1->next;
        temp2=temp2->next;
        y--;
    }
    return list3;
}

//display function to print the linked lists
void display(struct node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//main starts
int main()
{
    cout<<"Enter no. of nodes in both the linked lists: ";
    int y;
    cin>>y;
    node* list1=create(y);
    node* list2=create(y);
    cout<<"Linked List1: ";
    display(list1);
    cout<<"Linked List2: ";
    display(list2);
    node* list3=merge_list(list1,list2,y);
    cout<<"Linked List after merging: ";
    display(list3);


}

/*
Input format in test cases:
1st line contains number of nodes in each linked list(n).
2nd line contains value of each node of 1st linked list (total n) separated by spaces.
3rd line contains value of each node of 2nd linked list (total n) separated by spaces.

--------------------------------------------------------------------------------------
Test Case 1:
Input:
6
1 3 5 7 9 11
2 4 6 8 10 12

Output:
Linked List1: 1->3->5->7->9->11->NULL
Linked List2: 2->4->6->8->10->12->NULL
Linked List after merging: 1->2->3->4->5->6->7->8->9->10->11->12->NULL
--------------------------------------------------------------------------------------
Test Case 2:
Input:
9
1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1

Output:
Linked List1: 1->2->3->4->5->6->7->8->9->NULL
Linked List2: 9->8->7->6->5->4->3->2->1->NULL
Linked List after merging: 1->9->2->8->3->7->4->6->5->5->6->4->7->3->8->2->9->1->NULL
--------------------------------------------------------------------------------------

Time Complexity: merge_list() function: O(n)
Space complexity: merge_list() function: O(n)

*/
