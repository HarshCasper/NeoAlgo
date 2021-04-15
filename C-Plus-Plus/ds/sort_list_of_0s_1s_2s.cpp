/*
  Program to sort a linked list containing zeros, ones and twos.
  The given approach counts the number of ones, twos and zeros and makes the
  required changes in the linked list
*/

#include<bits/stdc++.h>
using namespace std;
struct node {
    int info;
    node* next;
};
node* head = NULL;

void insert(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void sortlist() {
    int zeros = 0, ones = 0, twos = 0;
    node* temp = head;
    while(temp != NULL) {
        if(temp->info == 0)
            zeros++;
        else if(temp->info == 1)
            ones++;
        else
            twos++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0; i < zeros; i++)
    {
        temp->info = 0;
        temp = temp->next;
    }
    for(int i = 0; i < ones; i++)
    {
        temp->info = 1;
        temp = temp->next;
    }
    for(int i = 0; i < twos; i++)
    {
        temp->info = 2;
        temp = temp->next;
    }
}

void print() {
    node* temp = head;
    while(temp != NULL) {
        cout<<temp->info<<" ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin>>n;
    int item;
    for(int i = 0; i < n; i++) {
        cin>>item;
        insert(item);
    }
    sortlist();
    print();
}
/*
  Input:
  n - number of elements in the list
  n elements
  Example:
  0 1 2 1 2

  Output:
  0 1 1 2 2

  Complexity Analysis:
  Time Complexity: O(n);
  Space Complexity: O(1);
*/
