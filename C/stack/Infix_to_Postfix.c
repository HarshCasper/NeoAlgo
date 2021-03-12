#include <stdio.h>
#include <stdlib.h>
#include<strings.h>

//Definition of node
struct Node{
    char data;
    struct Node *next;
}*top=NULL;

//function for 'Push(Adding to Queue)'
void push(char x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack is full\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

//Function for 'Pop(Removing from Queue)'
char pop(){
    struct Node *t;
    char x=-1;

    if(top==NULL)
        printf("Stack is Empty\n");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

//Function to Display
void Display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//function to check Precedence of signs
int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

//function to check if character is operand or not
int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;

}

//function to convert infix to postfix
char * InToPost(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
                postfix[j++]=pop();
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b*c-d/e";
    push('#');
    char *postfix=InToPost(infix);
    printf("%s ",postfix);
    return 0;
}

/*
Input is given as : 'a+b*c-d/e'

Output is : 'abc*+de/-'

*/
/*
Submitted by: Yuvraj Singh Tomar
Github: 07yuvraj
*/
