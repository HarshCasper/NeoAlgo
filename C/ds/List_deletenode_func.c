/*
 * Definition of a  singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Below is the function to delete node

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;
    n->next = NULL;
    return n;
}

void deleteNode(struct node *ref)
{
    while (ref->next != NULL)
    {
        ref->data = ref->next->data; //NODE TO BE DELETE POINTER GIVEN
        ref = ref->next;
    }
    free(ref);
}

void main()
{
    struct node *n = newNode(1);
    n->next = newNode(2);
    n->next->next = newNode(3);
    n->next->next->next = newNode(4);
    n->next->next->next->next = newNode(5);
    n->next->next->next->next->next = newNode(6);

    deleteNode(n->next->next->next); // deletion node is  4

    while (n->next != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}

/* OUTPUT
1 2 3 4 5 NULL
1 2 3 5 NULL
Time Complexity: O(1)
Space complexity: O(n)
*/
