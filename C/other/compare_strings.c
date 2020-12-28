#include <stdio.h>

int main()
{

    char a[20];
    char b[20];

    printf("Enter string in array 'a' : ");
    scanf("%s", a);

    printf("Enter string in array 'b': ");
    scanf("%s", b);

       int i, j;

    for (i = 0, j = 0; a[i] != '\0' || b[j] != '\0'; i++, j++)
    {

        if (a[i] != b[j])
            break;
    }

    if (a[i] == b[j])
        printf("They are EQUAL");

    else if (a[i] < b[j])
        printf("%s is smaller than %s \n", a, b);

    else

        printf(" %s is greater than %s \n", a, b);
}