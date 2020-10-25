//Implementation of Reversing a Linked List in C using Iterative and Recursive Method

#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

//function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

// to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Reverses the given linked list Iteratively
void reverseIterative(struct Node** head)
{
	struct Node* prev = NULL;   	// the prev pointer
	struct Node* current = *head;   // the main pointer

	// traverse the list
	while (current != NULL)
	{
		struct Node* next = current->next;
		current->next = prev;
		// advance the two pointers
		prev = current;
		current = next;
	}
	*head = prev;
}

// Recursive function to reverse the given linked list Recursively
void reverseRecursive(struct Node* head, struct Node** headRef)
{
	struct Node* first;
	struct Node* rest;

	if (head == NULL)
		return;
	first = head;
	rest = first->next;
	if (rest == NULL)
	{
		*headRef = first;
		return;
	}
	reverseRecursive(rest, headRef);
	rest->next = first;
	first->next = NULL;
}

int main()
{
	int n;
	cout << "Enter the number of elements:" << endl;
	cin >> n;
	int keys[n];
	for (int i = 0; i < n; i++)
	{
		cin >> keys[i];
	}
	struct Node *head = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		push(&head, keys[i]);
	}
	reverseIterative(&head);
	reverseRecursive(&head);
	printList(head);
	return 0;
}

/*
Example:-
Input-
Enter the number of elements:
5
1 2 3 4 5

Output-
5->4->3->2->-1->NULL
*/

