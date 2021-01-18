#include <stdio.h>

int main()
{

    char a[] = "hello";
    char b[] = "hellow";
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
