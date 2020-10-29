//algorithm for removing remove outermost parantheses in O(n) time complexity and O(1) space complexity

#include <stdio.h>

char * remove_outer_parantheses(char * S)
{
    int count = 0;
    int stack = 0;
    char *ans = S;
    char c; 
    while (c = *S++)
    {
        if (c == ')') 
        {
            --stack;
        }
        if (stack > 0) 
        {
            ans[count++] = c;
        }
        if (c == '(') 
        {
            ++stack;
        }
            
    }
    ans[count] = '\0';
    return ans;
}

int main()
{   //taking input from the user
    char s[1000];
    printf(" Enter the string\n ");
    scanf(" %s ",s);
    //printing result
    printf("The final string is : %s\n ",remove_outer_parantheses(s));
    return 0;
}

/*
Sample Input 1:
Input: "(()())(())"
Output: The final string is : ()()()
  
Sample Input 2:
Input: "(())()"
Output: The final string is : ()
*/