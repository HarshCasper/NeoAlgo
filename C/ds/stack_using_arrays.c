#include<stdio.h>
#include<stdlib.h>

//Implementing stacks using arrays
struct stack{
    int size;
    int top;
    int *arr;
};

// To check if the stack is full
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// To check if the stack is empty
int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//To inert Elements
void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

//To remove the element at the top
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// To return the topmost element i.e to peek
int peek(struct stack *ptr)
{
    if(!isEmpty(ptr))
    {
        return ptr->arr[ptr->top];
    }
    else{
        exit(EXIT_FAILURE);
    }
}

//Main Method to execute all the functions
int main()
{
    int element,choice = 0 ;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    
    do
    {
        printf("Enter choice: \n");
    printf("1.Push \n2.Pop \n3.Peek \n4.Exit \n");
    scanf("%d", &choice);
        switch(choice)
        {
         case 1: 
            printf("Enter the element to insert: \n");
            scanf("%d", &element);
            push(sp, element);
            break;
         case 2:
            printf("Popped %d from the stack\n", pop(sp));
            break;
         case 3:
            printf("Top most element is %d\n", peek(sp));
            break;
        }
    }while(choice!=4);
    
    return 0;
}