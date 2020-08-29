/*You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0
Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.The linked list with nodes N = 3 is given.
Here, x = 2 which means last node is connected with xth node of linked list. Therefore, there exists a loop.
Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

void loopHere(Node* head, Node* tail, int position)
{
  if (position == 0) return;

  Node* walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

bool isLoop(Node* head)
{
  if (!head) return false;

  Node* fast = head->next;
  Node* slow = head;

  while ( fast != slow)
  {
    if ( !fast || !fast->next ) return false;
    fast = fast->next->next;
    slow = slow->next;
  }

  return true;
}

int length(Node* head)
{
  int ret = 0;
  while (head)
  {
    ret++;
    head = head->next;
  }
  return ret;
}

void removeLoop(Node* head);

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, num;
    cin >> n;

    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);

    for (int i = 0 ; i < n - 1 ; i++)
    {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }

    int pos;
    cin >> pos;
    loopHere(head, tail, pos);

    removeLoop(head);

    if ( isLoop(head) || length(head) != n )
      cout << "0\n";
    else
      cout << "1\n";
  }
  return 0;
}


void removeLoop(Node* head)
{
  Node *slowPointer = head, *fastPointer = head;
  Node *prev;
  while (fastPointer != NULL && fastPointer->next != NULL) {
    prev = slowPointer;
    slowPointer = slowPointer->next;
    fastPointer = fastPointer->next->next;
    if (slowPointer == fastPointer) {
      break;
    }
  }
  if (slowPointer == fastPointer)
  {
    slowPointer = head;
    while (slowPointer->next != fastPointer->next) {
      slowPointer = slowPointer->next;
      fastPointer = fastPointer->next;
    }
    if (fastPointer == head) {
      prev->next = NULL;
    } else
      fastPointer->next = NULL;
  }
}
