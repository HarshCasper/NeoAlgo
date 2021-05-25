/*
Given a sequence of brackets as a string,
find maximum possible length of balanced bracket sequence.
string consists only two characters , one is '(' another is ')'
*/

#include <stdio.h>
#include <string.h>

//this balanced_bracket_sequence function will calculate maximum possible length of balanced bracket sequence
int balanced_bracket_sequence(char s[], int string_size)
{
    int max_possible_balanced_bracket_sequence = 0;
    int first_bracket = 0;
    /* Here if the current character of string is ' ( ' we will increment the first_bracket by 1
    and if the current character of string is ' ) ' we will check
    if first_bracket have value, we will increment max_possible_balanced_bracket_sequence
    by 2 and decrease first_bracket by 1
    */
    for(int i = 0; i < string_size; i++)
    {
        if(s[i] == '(')
        {
            first_bracket++;
        }
        else if(s[i] == ')')
        {
            if(first_bracket)
            {
                max_possible_balanced_bracket_sequence += 2;
                first_bracket--;
            }
        }
    }
    return max_possible_balanced_bracket_sequence;
}

int main()
{
    printf("Enter the string : \n");
    char s[1000];
    scanf("%s", &s);
    int string_size = (int)strlen(s);
    int max_balanced_bracket_sequence = balanced_bracket_sequence(s, string_size);
    printf("Maximum possible length of balanced bracket sequence is : \n");
    printf("%d \n",max_balanced_bracket_sequence);
}

/*
Standard Input and Output

Enter the string :
((()())

Maximum possible length of balanced bracket sequence is :
6

Time Complexity : O(N)
Space Complexity : O(1)

*/
