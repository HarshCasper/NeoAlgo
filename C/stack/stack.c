//IMPLEMENTATION OF STACK IN C

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//max. no. of elements present in the stack
#define STACK_SIZE 100

//struct for representing a stack
struct stack{
    int top;
    int items[STACK_SIZE];
};

//variable to keep track of size of stack
int sz = 0;

//creating a stack
void create_stack(struct stack *ps){
    ps->top = -1;
}

//push operation
void push(struct stack *ps, int x){
    if(ps->top == STACKSIZE-1){
        printf("Stack overflow\n");
    }
    else{

        //increase the size
        ps->top++;
        //assign the value to top element
        ps->items[ps->top] = x;
        printf("%d pushed onto the stack\n", x);
    }
    sz++;
}

//pop operation
void pop(struct stack *ps){
    if(ps->top==-1){
        printf("Stack underflow\n");
    }
    else{
        printf("The popped element is :%d\n" ,(ps->items[ps->top]));
        ps->top--;
    }
    sz--;
}

//function to get the top element
void stack_top(struct stack *ps){
    if(ps->top==-1){
        printf("Stack underflow\n");
    }
    else{
        printf("The top element is : %d\n", (ps->items[ps->top]));
    }
}

//check if a stack is empty(1) or not(0)
int is_empty(struct stack *ps){
    return (ps->top==-1);
}

//check if a stack is full(1) or not(0)
int is_full(struct stack *ps){
    return (ps->top==STACKSIZE-1);
}

//display stack elements
void display(struct stack *ps){
    if(ps->top>=0){
        printf("Stack elements are :");
        for(int i=sz-1; i>=0; i--){
            printf("\n%d", ps->items[i]);
        }
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
    }
}

//driver code
int main(int argc, char const *argv[]) {
    //declare a struct of type stack
    struct stack *s ;
    s = (struct stack *)malloc(sizeof(struct stack));
    create_stack(s);

    int ch, ans, val;

    do{
        printf("---------------------------------\n");
        printf("\t MENU\n");
        printf("---------------------------------\n");
        printf(" 1. Push\n 2. Pop\n 3. Top element\n 4. Check if empty\n 5. Check if full\n 6. Display\n 7.Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter a value : ");
                scanf("%d", &val);
                push(s, val);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                stack_top(s);
                break;
            case 4:
                ans = is_empty(s);
                if(ans==1){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Stack not empty yet\n");
                }
                break;
            case 5:
                ans = is_full(s);
                if(ans==1){
                    printf("Stack is full !!\n");
                }
                else{
                    printf("Stack not full yet\n");
                }
                break;
            case 6:
                display(s);
                break;
            case 7:
                exit(0);
        }
    }while(ch<8);

    return 0;
}

/*
SAMPLE I/O :
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 1
Enter a value : 25
25 pushed onto the stack
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 1
Enter a value : 36
36 pushed onto the stack
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 6
Stack elements are :
36
25
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 2
The popped element is :36
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 1
Enter a value : 96
96 pushed onto the stack
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 3
The top element is : 96
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 5
Stack not full yet
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 2
The popped element is :96
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 2
The popped element is :25
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 4
Stack is empty
---------------------------------
         MENU
---------------------------------
 1. Push
 2. Pop
 3. Top element
 4. Check if empty
 5. Check if full
 6. Display
 7.Exit
---------------------------------
Enter your choice : 7
*/
