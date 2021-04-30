//A PRIORITY QUEUE  BEHAVES SIMILAR TO THE NORMAL QUEUE EXCEPT THE FACT THAT EACH ELEMENT HAS SOME PRIORITY AND ELEMENT WITH HIGHEST PRIORITY IS PLACED FIRST IN THAT QUEUE.
//THE ELEMENTS WITH HIGHER PRIORITY IS REMOVED FIRST WHILE DELETION FUNCTION IS INVOKED.THIS IS IMPLEMENTED USING LINKED LIST.

#include <stdio.h>

#include <malloc.h>

struct node {
    int data;
    int priority;
    struct node * link;
};
struct node * start = NULL;
struct node * insert(struct node * start);
struct node * delete(struct node * start);
void display(struct node * start);
int main() {
    int choice;
    do {
        printf(" \n-------------------- ");
        printf("\n 1. INSERT THE ELEMENT");
        printf("\n 2. DELETE THE ELEMENT");
        printf("\n 3. DISPLAY THE ELEMENTS");
        printf("\n 4. EXIT");
        printf("\n ENTER YOUR CHOICE : ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete(start);
            break;
        case 3:
            display(start);
            break;
        }
    } while (choice != 4);
}

//to insert elements to queue
struct node * insert(struct node * start) {
    int val, priority_of_data;
    struct node * ptr, * p;
    ptr = (struct node * ) malloc(sizeof(struct node));
    printf("\n Enter the value of data item and its Priority : ");
    scanf("%d %d", & val, & priority_of_data);
    ptr -> data = val;
    ptr -> priority = priority_of_data;
    if (start == NULL || priority_of_data < start -> priority) {
        ptr -> link = start;
        start = ptr;
    } else {
        p = start;
        while (p -> link != NULL && p -> link -> priority <= priority_of_data)
            p = p -> link;
        ptr -> link = p -> link;
        p -> link = ptr;
    }
    return start;
}

struct node * delete(struct node * start) {
    struct node * ptr;
    //if there are no elements in queue
    if (start == NULL) {
        printf("\n Oops!Cannot delete elements as queue is in underflow state!!");
        return 0;
    }
     else {
        ptr = start;
        printf("\n Deleted item is: %d", ptr -> data);
        start = start -> link;
        free(ptr);
    }
    return start;
}

//to display priority number and data
void display(struct node * start) {
        struct node * ptr;
        ptr = start;
        if (start == NULL)
            printf("\nQueue is empty");
        else {
            printf("\n Priority Queue is : \n");
            while (ptr != NULL) {
                printf("data->%d Priority->%d\n", ptr -> data, ptr -> priority);
                ptr = ptr -> link;
            }
        }
    }

    //TIME COMPLEXITY:o(n)

    //OUTPUT:
    //--------------------
    //1. INSERT THE ELEMENT
    //2. DELETE THE ELEMENT
    //3. DISPLAY THE ELEMENTS
    //4. EXIT
    // ENTER YOUR CHOICE : 1

    //Enter the value of data item and its Priority : 12 1

    //--------------------
    // 1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 1

    // Enter the value of data item and its Priority : 123 3

    //--------------------
    // 1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 1

    // Enter the value of data item and its Priority : 126 4

    //--------------------
    // 1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 1

    //Enter the value of data item and its Priority : 121 2

    //--------------------
    // 1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    //ENTER YOUR CHOICE : 3

    //Priority Queue is :
    //data->12 Priority=1
    //data->121 Priority=2
    //data->123 Priority=3
    //data->126 Priority=4

    //--------------------
    //1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 2

    //Deleted item is: 12
    //--------------------
    //1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    //ENTER YOUR CHOICE : 2

    //Deleted item is: 121
    //--------------------
    //1. INSERT THE ELEMENT
    //2. DELETE THE ELEMENT
    //3. DISPLAY THE ELEMENTS
    //4. EXIT
    // ENTER YOUR CHOICE : 2

    // Deleted item is: 123
    //--------------------
    // 1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    // 3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 2

    //Deleted item is: 126
    -- -- -- -- -- -- -- -- -- --
    //1. INSERT THE ELEMENT
    // 2. DELETE THE ELEMENT
    //3. DISPLAY THE ELEMENTS
    // 4. EXIT
    // ENTER YOUR CHOICE : 2

    //Oops!Cannot delete elements as queue is in underflow state!!
