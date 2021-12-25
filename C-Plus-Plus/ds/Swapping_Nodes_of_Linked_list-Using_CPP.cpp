/* given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.
the nodes themselves must be swapped and not the datas.
*/

#include <iostream>
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

// function to take input for linked list

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

// funtion to print the linked list

void print(Node * head) {
  Node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

// funtion to swap the nodes of linked list

Node * swapNodes(Node * head, int i, int j) {
  int pos = 0;
  Node * tail = head;
  Node * prevFirst = NULL;
  Node * prevSecond = NULL;
  int first = (i < j) ? i : j;
  int second = (i + j) - first;
  while (tail != NULL) {
    if (pos == first - 1)
      prevFirst = tail;

    if (pos == second - 1)
      prevSecond = tail;

    tail = tail -> next;
    pos++;
  }
  if (first == 0 && prevSecond != NULL && prevSecond -> next != NULL) {

    if (second != first + 1) {
      Node * temp1 = head;
      Node * temp2 = prevSecond -> next -> next;

      head = prevSecond -> next;
      prevSecond -> next -> next = temp1 -> next;
      prevSecond -> next = temp1;
      temp1 -> next = temp2;

      return head;
    } else {
      Node * temp = head;
      Node * temp2 = head -> next -> next;

      head = head -> next;
      head -> next = temp;
      temp -> next = temp2;

      return head;
    }
  }
  if (prevFirst == NULL || prevSecond == NULL || prevFirst -> next == NULL || prevSecond -> next == NULL)
    return head;
  if (second != first + 1) {
    Node * temp1 = prevFirst -> next;
    Node * temp2 = prevSecond -> next -> next;

    prevFirst -> next = prevSecond -> next;
    prevSecond -> next -> next = temp1 -> next;
    prevSecond -> next = temp1;
    temp1 -> next = temp2;

    return head;
  } else {
    Node * temp1 = prevFirst -> next;
    Node * temp2 = prevFirst -> next -> next -> next;

    prevFirst -> next = prevFirst -> next -> next;
    prevFirst -> next -> next = temp1;
    temp1 -> next = temp2;

    return head;
  }
}

// main function to take input from the user

int main() {
  int i, j;
  cout << "enter the elements of linked list" << endl;
  Node * head = takeinput();
  cout << "enter the two positions to be swapped" << endl;
  cin >> i;
  cin >> j;
  head = swapNodes(head, i, j);
  cout << "swapped linked list is " << endl;
  print(head);
  return 0;
}

/*
Time Complexity - O(n)
Space Complexity - O(1)
where n is the size of singly linked list

Sample Input 1 - 
enter the elements of linked list
3 4 5 2 6 1 9 -1
enter the two positions to be swapped
3 4

Sample Output 1 - 
swapped linked list is
3 4 5 6 2 1 9 

*/
