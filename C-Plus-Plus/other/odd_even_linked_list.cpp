/* Program to rearrange a given linked list so that all odd indexed nodes are arranged first,
   followed by the even indexed nodes in one iteration through the linked list*/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
 };

ListNode* odd_even_linked_list(ListNode* head) {

    //if linked list has only 1 node, no rearrangement required
    if(head->next==NULL)
    {
        return head;
    }

    //Head of the LinkedList containing odd indexed elements
    ListNode* head_odd= new ListNode();

    //Head of the LinkedList containing even indexed elements
    ListNode* head_even= new ListNode();

    head_odd= head;
    head_even= head->next;

    //Counter for odd indexed nodes
    ListNode* co= head_odd;
    //Counter for even indexed nodes
    ListNode* ce= head_even;

    while((co->next)!= NULL && (ce->next)!= NULL)
    {
        //pointer to next odd indexed element
        co->next= co->next->next;
        //pointer to next even indexed element
        ce->next= ce->next->next;
        co= co->next;
        ce= ce->next;
    }

    //join the 2 linked list
    co->next= head_even;

    return head;
}

int main()
{
    int n;
    cin>>n;

    int x;
    cin>>x;

    ListNode* head= new ListNode();

    head->val= x;
    head->next= NULL;

    ListNode* temp= head;

    for(int i=1;i<n;i++)
    {
        cin>>x;
        ListNode* new_node= new ListNode();
        new_node->val= x;
        temp->next= new_node;
        new_node->next= NULL;
        temp= temp->next;
    }

    ListNode* head_new= odd_even_linked_list(head);


    //print the rearranged linked list
    temp= head_new;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}

/*  Testcase 1:
    n= 7
    Input Linked List: 1->2->3->4->5->6->7
    Output Linked List: 1->3->5->7->2->4->6

    Testcase 2:
    n= 4
    Input Linked List: 2->4->6
    Output Linked List: 2->6->4

    Time Complexity: O(n)  (We have traversed the linked list just once)
    Space Complexity: O(1) (No extra space is used)*/

