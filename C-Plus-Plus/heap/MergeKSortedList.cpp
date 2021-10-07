/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/


#include <bits/stdc++.h>
#define pil pair<int,ListNode *>
using namespace std;
// Defining a struct of ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    //creating a priority queue with elements in increasing order.
    priority_queue<pil,vector<pil>,greater<pil>> pq;
    
    //Inserting a pair of integer and ListNode head.
    for(auto it : lists){
        if(it){
            pq.push({it->val,it});
        }
    }
    //Creating A New head pointer to store merged Lists.
    ListNode *temp = new ListNode();
    ListNode *head = temp;
    
    //Iterating till priority queue gets empty.
    while(!pq.empty()){
        
        // Popping the smallest element.
        pil top = pq.top();
        pq.pop();
        
        // Pointing head pointer to smallest element pointer.
        temp->next = top.second;
        
        //Checking if next element exists on current list or not.
        if(top.second->next){
            pq.push({top.second->next->val,top.second->next});
        }
        temp = temp->next;
    }
    return head->next;
}
/*
Input : 
[
  1->4->5,
  1->3->4,
  2->6
]

Output : 
1->1->2->3->4->4->5->6

*/
