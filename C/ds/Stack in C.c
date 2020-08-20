#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty() {
   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int count(){
    int count = 0;
    for(int i = top; i>=0; i--){
        count++;
    }
    printf("The total number of elements in the stack are : %d \n",count);

}

int pop() {
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
      printf("Element inserted at the top of stack successfully!!!\n");
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {

   int ch,n,a;
   do{

   printf("Enter your choice : \n1 - Push\n2 - Pop\n3 - Peak\n4 - Check if stack is Empty\n5 - Check if stack is full\n6 - Display\n7 - Count total number of elements\n");
   scanf("%d",&ch);

   switch(ch){

        case 1:
           printf("Enter the value to push : \n");
           scanf("%d",&a);
           push(a);
           break;

        case 2:
            a = pop();
            printf("The popped value is %d\n", a);
            break;

        case 3:
            printf("Element at top of the stack: %d\n" ,peek());
            break;

        case 4:
            printf("Stack empty: %s\n" , isempty()?"true":"false");
            break;

        case 5:
            printf("Stack full: %s\n" , isfull()?"true":"false");
            break;

        case 6:

             if(!isempty()) {
                printf("Elements: \n");
                  for(int i = top; i>=0; i--){
                    printf("%d\n",stack[i]);
                  }
               }
             else{
                printf("Stack is empty \n");
             }
               break;

        case 7:
            count();
            break;

        default:
            printf("Please enter the correct choice\n");

   }
        printf("Press 1 to repeat otherwise press any key \n");
        scanf("%d",&n);

   }while(n == 1);

   return 0;
}
