/* Detection of cycle or loop in a Singly linked list
Their may exist a node in a linked list which may point to another node present already in 
the linked list before it, this leads to formation of loop in the linked list.
Solution: We use hare and tortoise algorithm to solve the problem. We maintain to pointers hare and tortoise . Tortoise pointer move one step at one iteration 
and  hare pointer move by two steps in one iteration. At every iteration we see whether hare is equal to tortoise, if yes then it means there exist a loop in 
the list and we return true. Simultaneosly we also check if tortoise or hare or hare->next is NULL, if yes it means there is no cycle present and we return false.
*/

#include <bits/stdc++.h>
using namespace std;

//Creation of Node struct for Linked List
struct Node{
    int data;
    Node *next;
    explicit Node(int element){
        data = element;
        next = NULL;
    }
};

//Hare and Tortoise Algorithm
//Both pointers meet at point if their exist a loop in the list ;otherwise any of the pointer encounters null
bool detectCycle(Node *head){
    Node *tortoise = head,*hare = head;
    do{
        if(hare==NULL || hare->next==NULL || tortoise==NULL){
            return false;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }while(hare!=tortoise);
    
    return true;
}
int main(){
    Node * head = new Node(1);
    head -> next = new Node (2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = head->next;
    cout << detectCycle(head);
    return 0;
}

/*Test Case
Input : 1->2->3
           |  |
           ^ --<
Output : 1
Time Complexity
O(N)
Space Complexity
O(1)
*/