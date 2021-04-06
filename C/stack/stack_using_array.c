//MENU DRIVEN C PROGRAM FOR IMPLEMENTING STACK USING ARRAY

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Maximum stack size
#define STACK_SIZE 100

int stack[STACK_SIZE];
/*
initially top = -1 to denote that the
stack is empty.
n is the number of stack elements
*/
int top = -1, i, j, ch, n;

//function to add an element to the stack, one on top of the other
void push(){
    /*
    if we are at the top position then more
    elements cannot be added
    */
    if(top>=n){
        printf("Stack full --- overflow\n");
    }
    else{
        int val;
        printf("Enter the value : ");
        scanf("%d", &val);
        top = top+1;
        stack[top] = val;
        printf("%d pushed onto the stack", val);
    }
}

//function to remove the topmost element from the stack
void pop(){
    /*
    check if there are elements in the
    stack or not
    */
    if(top<=-1){
        printf("Stack empty --- underflow\n");
    }
    else{
        printf("The popped element is %d", stack[top]);
        top = top-1;
    }
}

//function to get the top element from the stack
void peek(){
    printf("The top element is : %d", stack[top]);
}

//function to check if the stack is empty
void is_empty(){
    if(top==-1){
        printf("Stack is empty!\n");
    }
    else{
        printf("Stack not empty yet..\n");
    }
}

//function to check if the stack if full
void is_full(){
    if(top==n-1){
        printf("Stack is full!\n");
    }
    else{
        printf("Stack not full yet..\n");
    }
}

//function to display stack elements from top to bottom
void display(){
    //this condition is true if there are elements in the stack
    if(top>=0){
        printf("The stack elements are : \n");
        for(int i=top; i>=0; i--){
            printf("\n%d", stack[i]);
        }
    }
    else{
        printf("Stack is empty!\n");
    }
}

//driver code
int main(){
    printf("\t\tSTACK USING ARRAYS\n");
    printf("\n-----------------------------------------\n");
    printf("Enter no. of elements in the stack : ");
    scanf("%d", &n);
    printf("\n-----------------------------------------\n");
    printf("\t\tMENU\n");
    printf("\n-----------------------------------------\n");
    do{
        printf("\n\nChoose an option : \n");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Check if full\n6. Exit\n");
        printf("Your choice : ");
        scanf("%d", &ch);
        printf("");

        switch(ch){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            is_empty();
            break;
        case 5:
            is_full();
            break;
        case 6:
            exit(0);
        }
    }while(ch<7);
}

/* SAMPLE INPUT - OUTPUT

Enter no. of elements in the stack : 2

-----------------------------------------
                MENU

-----------------------------------------


Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 1
Enter the value : 55
55 pushed onto the stack

Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 1
Enter the value : 65
65 pushed onto the stack

Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 5
Stack is full!


Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 3
The top element is : 65

Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 2
The popped element is 65

Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 2
The popped element is 55

Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 4
Stack is empty!


Choose an option :

1. Push
2. Pop
3. Peek
4. Check if empty
5. Check if full
6. Exit
Your choice : 6

Process returned 0 (0x0)   execution time : 45.588 s
Press any key to continue.
*/
