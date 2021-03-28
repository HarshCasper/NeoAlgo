// C++ program to delete all the Fibonacci nodes from the circular singly linked list

#include <bits/stdc++.h>
using namespace std;
 
// Structure for a node
struct Node {
    int data;
    struct Node* next;
};
 
// Function to insert a node at the beginning of a Circular linked list
void push(struct Node** head_ref, int data)
{
    // Create a new node and make head as next
    // of it.
    struct Node* ptr1
        = (struct Node*)malloc(
            sizeof(struct Node));
    struct Node* temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
    
    // If linked list is not NULL then set the next of last node
    if (*head_ref != NULL) {
        // Find the node before head
        // and update next of it.
        while (temp->next != *head_ref)
            temp = temp->next;
 
        temp->next = ptr1;
    }
    else
 
        // Point for the first node
        ptr1->next = ptr1;
 
    *head_ref = ptr1;
}
 
// Delete the node from a Circular Linked list
void deleteNode(Node* head_ref, Node* del)
{
    struct Node* temp = head_ref;
 
    // If node to be deleted is head node
    if (head_ref == del)
        head_ref = del->next;
 
    // Traverse list till not found
    // delete node
    while (temp->next != del) {
        temp = temp->next;
    }
 
    // Copy the address of the node
    temp->next = del->next;
 
    // Finally, free the memory
    // occupied by del
    free(del);
 
    return;
}
 
// Function to find the maximum
// node of the circular linked list
int largestElement(struct Node* head_ref)
{
    // Pointer for traversing
    struct Node* current;
 
    current = head_ref;  // Initialize head to the current pointer
 
    int maxEle = INT_MIN;
 
    do {
        // If current node data is greater for max then replace it
        if (current->data > maxEle) {
            maxEle = current->data;
        }
 
        current = current->next;
    } while (current != head_ref);
 
    return maxEle;
}
 
// Function to create hash table to
// check Fibonacci numbers
void createHash(set<int>& hash,
                int maxElement)
{
    int prev = 0, curr = 1;
 
    // Adding the first two elements
    // to the hash
    hash.insert(prev);
    hash.insert(curr);
 
    // Inserting the Fibonacci numbers
    // into the hash
    while (curr <= maxElement) {
        int temp = curr + prev;
        hash.insert(temp);
        prev = curr;
        curr = temp;
    }
}
 
// Function to delete all the Fibonacci nodes
// from the singly circular linked list
void deleteFibonacciNodes(Node* head)
{
    // Find the largest node value
    // in Circular Linked List
    int maxEle = largestElement(head);
    
    // Creating a hash containing all the Fibonacci numbers
    set<int> hash;
    createHash(hash, maxEle);
 
    struct Node* ptr = head;
 
    struct Node* next;
 
    do {
        // If the node's data is Fibonacci, delete node 'ptr'
        if (hash.find(ptr->data)
            != hash.end())
            deleteNode(head, ptr);
 
        // Point to the next node
        next = ptr->next;
        ptr = next;
 
    } while (ptr != head);
}
// Function to print nodes in a given Circular linked list 
void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
 
int main()
{
    struct Node* head = NULL;
 
    cout<<"Enter no. of integers you want to insert in the linked list: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      push(&head, x);
    }
 
    deleteFibonacciNodes(head);
 
    printList(head);
 
    return 0;
}


//Example:
//INPUT:
//Enter no. of integers you want to insert in the linked list: 7
//0
//1
//2
//5
//30
//20
//12

//OUTPUT:
//12 30 20
