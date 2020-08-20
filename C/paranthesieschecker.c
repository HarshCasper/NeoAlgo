/*
Given a string of parenthesis check if parenthesis occurred in pair
Example:
Input: s="({})"
Output: yes

Input: s="[{(}])"
Output: yes

Input: s="(((}"
Output: no

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int check(char *a){
    int a1 = 0,a2 = 0 , b1= 0, b2=0,c1=0,c2=0;
    for(int i=0;i<strlen(a) ; i++){
        if(a[i]=='{')
            a1++;
        else if(a[i]=='}')
            a2++;
        else if(a[i]=='(')
            b1++;
        else if(a[i]==')')
            b2++;
        else if(a[i] =='[')
            c1++;
        else if(a[i]==']')
            c2++;
    }
    if(a1==a2 && c1==c2 && b1==b2)             //we are checking if opening and closing brackets are same then it is true 
        return 1;
    else 
        return 0;
}
int main() {
char a[1001];
    int n,valid;

     scanf("%s",a); //accepting input
         valid = check(a);        //if function returns 1 then it is true
         if(valid==1)
             printf("yes\n");
    else                //else it is false
        printf("no\n");
    return 0;
}
