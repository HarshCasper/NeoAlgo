#include <stdio.h>
int main()
{

    char a[20];
    char b[21];

    printf("Enter string to check : ");
    scanf("%s", a);

    int i, j;

    // reversing the string
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i--;
    for (j = 0; i >= 0; i--, j++)
    {

        b[j] = a[i];
    }
    b[j] = '\0';

    // comparing the strings
    for (i = 0, j = 0; a[i] != '\0' || b[j] != '\0'; i++, j++)
    {

        if (a[i] != b[j])
            break;
    }

    if (a[i] == b[j])
        printf("Palindrome string \n");

    else
        printf("Not a palindrome string \n");
}