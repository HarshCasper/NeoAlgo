/* Program to rearrange a given linked list so that all odd indexed nodes are arranged first,
   followed by the even indexed nodes in one iteration through the linked list*/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
};

ListNode* odd_even_linked_list(ListNode* head)
{

    //if linked list has only 1 node, no rearrangement required
    if (head->next == NULL) {
        return head;
    }

    //Head of the LinkedList containing odd indexed elements
    ListNode* head_odd = new ListNode();

    //Head of the LinkedList containing even indexed elements
    ListNode* head_even = new ListNode();

    head_odd = head;
    head_even = head->next;

    //Counter for odd indexed nodes
    ListNode* counter_odd = head_odd;
    //Counter for even indexed nodes
    ListNode* counter_even = head_even;

    while ((counter_odd->next) != NULL && (counter_even->next) != NULL) {
        //pointer to next odd indexed element
        counter_odd->next = counter_odd->next->next;
        //pointer to next even indexed element
        counter_even->next = counter_even->next->next;
        counter_odd = counter_odd->next;
        counter_even = counter_even->next;
    }

    //join the 2 linked list
    counter_odd->next = head_even;

    return head;
}

int main()
{
    int nodes;
    cin >> nodes;

    int node_value;
    cin >> node_value;

    ListNode* head = new ListNode();

    head->val = node_value;
    head->next = NULL;

    ListNode* temp = head;

    for (int i = 1; i < nodes; i++) {
        cin >> node_value;
        ListNode* new_node = new ListNode();
        new_node->val = node_value;
        temp->next = new_node;
        new_node->next = NULL;
        temp = temp->next;
    }

    ListNode* head_new = odd_even_linked_list(head);

    //print the rearranged linked list
    temp = head_new;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
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
