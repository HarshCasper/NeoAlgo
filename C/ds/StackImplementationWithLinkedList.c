/*
A stack is an Abstract Data Type (ADT), commonly used in most programming languages.This feature makes it LIFO data structure. LIFO stands for Last-in-first-out. Here, the element which is placed (inserted or added) last, is accessed first.
The Basic operation in Stack are:
1.push() − Pushing (storing) an element on the stack.
2.pop() − Removing (accessing) an element from the stack.
3.peek() − get the top data element of the stack, without removing it.
4.display() - used to display the elements
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * link;
};
struct node * top = NULL;
void push();
void pop();
void display();
void push() {
    struct node * temp;
    temp = (struct node * ) malloc(sizeof(struct node));
    printf("\n Enter node data:");
    scanf("%d", & temp -> data);
    temp -> link = top;
    top = temp;
}
void pop() {
    struct node * temp;
    if (top == NULL)
        printf("No element");
    else {
        temp = top;
        printf("The deleted element is %d", temp -> data);
        top = top -> link;
        temp -> link = NULL;
        free(temp);
    }
}
void display() {
    struct node * temp;
    if (top == NULL)
        printf("\n Stack is empty");
    else {
        temp = top;
        printf("\nData is");
        while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = temp -> link;
        }
    }
}
void main() {
        int choice;
        do {
            printf("\n*****Menu*****)
                printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n"); printf("Enter your choice:"); scanf("%d", & choice);
                switch (choice) {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choice");
                }
            }
            while (choice < 5);
            getchar();
        }

/*
*****MENU****** 
1.Push
2.Pop 
3.Display 
4.Exit 
Enter your choice 1 
Enter node data 23

*****MENU****** 
1.Push
2.Pop 
3.Display 
4.Exit
Enter your choice 1 
Enter node data 24

*****MENU****** 
1.Push
2.Pop 
3.Display 
4.Exit
Enter your choice 2
The deleted element is 24

*****MENU****** 
1.Push
2.Pop 
3.Display 
4.Exit
Enter your choice 
1 Enter node data 25

*****MENU****** 
1.Push
2.Pop 
3.Display 
4.Exit
Enter your choice 3 
Data is 23 25

Time complexity : O(1)
Space Complexity: O(n)
*/
