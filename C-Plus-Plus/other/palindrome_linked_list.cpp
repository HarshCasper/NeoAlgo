//A program to check if a given singly linked list is a palindrome or not in linear time and no extra space
//The idea is to reverse the second half of the linked list, and then compare the two halfs for palindrome checking

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
};

//return if the linked list is a palindrome or not
bool is_palindrome(ListNode* head)
{

    ListNode* A = head;
    int cnt = 0;

    //Count the number of nodes in the linked list
    while (A != NULL) {
        cnt++;
        A = A->next;
    }

    //If there is only one node, then its clearly a palindrome
    if (cnt == 1) {
        return 1;
    }

    //Traverse upto the node(half_end) after which we need to reverse the linked list
    int half = (cnt + 1) / 2;
    half--;

    ListNode* half_end = head;
    while (half > 0) {
        half_end = half_end->next;
        half--;
    }

    //Take 2 pointers to reverse the linked list after node half_end
    ListNode* p1 = half_end;
    ListNode* p2 = half_end->next;

    ListNode* temp = p2->next;
    p2->next = NULL;
    p1 = p2;
    p2 = temp;

    while (p2) {
        temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
    }

    //Join the head of the reversed linked list to the current endthat is, half_end
    half_end->next = p1;

    //Take 2 pointers and compare the 2 parts
    p2 = head;
    p1 = half_end->next;

    while (p1) {
        //If any one value is different, return 0
        if ((p2->val) != (p1->val)) {
            return 0;
        }
        else {
            p2 = p2->next;
            p1 = p1->next;
        }
    }

    return 1;
}

int main()
{
    int nodes;
    cin >> nodes;

    int node_val;
    cin >> node_val;

    ListNode* head = new ListNode();
    head->val = node_val;
    head->next = NULL;

    ListNode* temp = head;

    for (int i = 1; i < nodes; i++) {
        cin >> node_val;
        ListNode* new_node = new ListNode();
        new_node->val = node_val;
        new_node->next = NULL;
        temp->next = new_node;
    }

    if (is_palindrome(head)) {
        cout << "Yes, it is a palindrome" << endl;
    }
    else {
        cout << "No, it is not a palindrome" << endl;
    }
}

/*Test Case 1:
  n= 6
  input= 2->4->6->6->4->2
  output= Yes, it is a palindrome

  Test Case 2:
  n= 5
  input= 1->2->3->5->9
  output= No, it is not a palindrome

  Time Complexity: O(n)
  (Since, we traverse the linked list only thrice, once for counting the nodes,
   then to reverse the second half and then for checking if it is a palindrome)
  Space Complexity: O(1) (No extra space is used)*/
