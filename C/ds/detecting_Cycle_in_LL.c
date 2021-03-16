/*
    Contributor: Kratika Mittal (@kratika19)

    A Linked List is a linear data structure which includes a series of connected nodes. Each node stores the data and the pointer to the address of the next node.
    If any node is visited more than once while traversing the list then we can say that it contains cycle/loop.
     Example:
                15 -> 14 -> 69
                    ^     |
                    |     v
                    43 <-  95   
     Output:
            Cycle is present in the Linked List

    Method:
    * Create two pointers, slow and fast.
    * Fast will move 2 nodes ahead at one time, while slow will move at the mormal pace, ie, one node at a time.
    * We will perform the iteration until the address in one of the node is null or the address inside both the nodes is same.
    * If same, cycle exists.
    * Else, cycle does not exist in the linked list.
*/


#include <stdio.h>
#include<stdlib.h>

//basic node structure of linked list
struct Node {
    int data;
    struct Node *next;
}*head;

//creating sample circular list to check if the algorithm works fine or not
void create_circular_linked_list(int *A, int n) {
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (int  index = 1; index < n; index++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[index];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

//display function to display the contents of linked list
void display(struct Node *point) {
    int flag = 0;
    printf("Elements of Linked List are: \n");
    while (flag != 1 || point != head) {
        flag = 1;
        printf("%d\n",point->data);
        point = point->next;
    }
}

//function to represent if loop is present or not
//it returns 1 if loop is present
//it return 0 if loop is absent
int is_loop_present(struct Node *first) {
    int check = 0;
    struct Node *fast, *slow;
    slow = fast = first;
    do {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        if (slow == fast) {
            check = 1;
            break;
        }
    } while (slow != NULL && fast != NULL);
    return check;
}


int main() {
    int A[] = {1, 2, 3, 4, 7, 8,9};

    create_circular_linked_list(A, 7);

    display(head);

    printf("\n");

    int check = is_loop_present(head);
    if (check == 1)
        printf("Loop is present in the Linked List\n");
    else
        printf("Loop is absent in the Linked List\n");
        
    printf("\n");
    return 0;
}

//Sample output
//Elements of Linked List are:
//1
//2
//3
//4
//7
//8
//9
//
//Loop is present in the Linked List

//Time Complexity = O(n)
//Space Complexity = O(n)