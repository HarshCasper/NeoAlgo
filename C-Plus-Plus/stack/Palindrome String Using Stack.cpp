#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int top1= -1 , top2= -1;

// function to push elements in stack.
void push(char s,char arr[])
{
    top2++;
    arr[top2]=s;
}
//function to pop elements in stack
void pop()
{
    top1--;
}
//function to check if string is palindrome
int palindrome(char str[],char str2[])
{
    int flag=0;
    while(str[top1]!='X')
    {
        push(str[top1],str2);
        pop();
    }
    int t=top1-1;
    while(t!=-1)
    {
        if(str[t]!=str2[t])
        {
            flag=0;
            return flag;
        }
        else
        {
            flag=1;
            t--;
        }
    }
    return flag;
}
int main()
{
    int n;
    cout<<"Enter size of string :- ";
    cin>>n;
    char str1[n],str2[n];
    cout<<"Enter a String (eg:- ABXBA) :- ";
    fflush(stdin);//this statement clears buffer before taking string as user input .
    gets(str1);
    top1=n-1;
    fflush(stdin);
    if(palindrome(str1,str2)==1)
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
    return 0;
}
