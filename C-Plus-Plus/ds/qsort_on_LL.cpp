
#include <iostream>
#include <cstdio>
using namespace std;

struct LLNode
{
    int data;
    LLNode *next;
};

void addNode(LLNode **head, int value)
{
    LLNode *curr = new LLNode;
    curr->data = value;
    curr->next = NULL;

    if (*head == NULL)
        *head = curr;
    else
    {
        curr->next = *head;
        *head = curr;
    }
}

void display(LLNode **head)
{
    LLNode *temp = *head;

    while (temp != NULL)
    {
        if (temp->next != NULL)
            cout << temp->data << " ->";
        else
            cout << temp->data;

        temp = temp->next;
    }
    cout << endl;
}
LLNode *getTail(LLNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd)
{
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

LLNode *qSort(LLNode *head, LLNode *end)
{
    if (!head || head == end)
        return head;

    LLNode *newHead = NULL, *newEnd = NULL;

    LLNode *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = qSort(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = qSort(pivot->next, newEnd);

    return newHead;
}

void quickSort(LLNode **headRef)
{
    (*headRef) = qSort(*headRef, getTail(*headRef));
    return;
}

int main()
{
    LLNode *head = NULL;
    LLNode *tail = NULL;
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 90);
    addNode(&head, 50);
    addNode(&head, 10);
    addNode(&head, 110);

    cout << "Linked List before sorting \n";
    display(&head);

    quickSort(&head);

    cout << "Linked List after sorting \n";
    display(&head);

    return 0;
}

/*
QuickSort on Singly Linked List:

Linked List before sorting
110 ->10 ->50 ->90 ->30 ->20

Linked List after sorting
10 ->20 ->30 ->50 ->90 ->110

Best-case performance: O(n log n)
Worst-case space complexity: O(n)
Worst-case performance: O(n2)
Average performance: O(n log n)

*/



