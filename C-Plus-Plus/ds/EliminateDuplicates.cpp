/*
Remove the consecutive duplicate values from the singly linked list such that the given list only contains unique elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
  Node * next;
  Node(int data) {
    this -> data = data;
    this -> next = NULL;
  }
};

Node * takeinput() {
  int data;
  cin >> data;
  Node * head = NULL, * tail = NULL;
  while (data != -1) {
    Node * newnode = new Node(data);
    if (head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      tail -> next = newnode;
      tail = newnode;
    }
    cin >> data;
  }
  return head;
}

void print(Node * head) {
  Node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

Node * removeDuplicates(Node * head) {
  if (head == NULL)
    return head;
  Node * currHead = head;
  while (currHead -> next != NULL) {
    if (currHead -> data == currHead -> next -> data) {
      currHead -> next = currHead -> next -> next;
    } else {
      currHead = currHead -> next;
    }
  }
  return head;
}
int main() {
  cout << "Enter the data of linked list "<<endl;
  Node * head = takeinput();
  head = removeDuplicates(head);
  cout << "The linked list after eliminating consecutive duplicates is" << endl;
  print(head);

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
where n is the size of the singly linked list

Sample Input:
Enter the data of linked list
1 2 3 3 4 3 4 5 4 5 5 7 -1

Sample Output:
The linked list after eliminating consecutive duplicates is
1 2 3 4 3 4 5 4 5 7 
*/
