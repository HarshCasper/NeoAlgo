/*
POLYNOMIAL ADDITION USING ARRAYS
2 polynomials are accepted as input from the user
and stored in arrays.
The degree of the larger polynomial is found and stored in l
The 2 polynomial arrays are traversed from the end till one
of the 2 polynomials reaches the beginning
The coefficients are added and stored in an array sum
The remaining, terms if present in any polynomial, are added
to the sum array.
*/

#include <stdio.h>

//to add the 2 polynomials
void add_polynomials(int *a, int *b, int n, int m)
{
    int l, i, j, k;
    l = n > m ? n : m;
    int *sum = (int *)malloc(sizeof(int) * l);

    //initialize sum array
    for (i = 0; i <= l; i++)
        sum[i] = 0;
    i = n, j = m, k = l;

    //add the coefficients of like power terms
    while (i >= 0 && j >= 0)
    {
        sum[k--] = a[i--] + b[j--];
    }

    //add the remaining coefficients to sum
    if (i >= 0)
        while (i >= 0)
            sum[k--] = a[i--];
    else if (j >= 0)
        while (j >= 0)
            sum[k--] = b[j--];
            
    //display sum
    printf("SUM\n");
    for (i = 0; i <= l; i++)
    {
        printf("%dx^%d", sum[i], l - i);
        if (i != l)
            printf(" + ");
    }
}

//driver code
int main()
{
    //accept the polynomials as user input
    int n, m, i;
    printf("Enter the degrees of the polynomials: ");
    scanf("%d%d", &n, &m);
    int *poly1 = (int *)malloc(sizeof(int) * n);
    int *poly2 = (int *)malloc(sizeof(int) * m);
    printf("Enter the coefficients of first polynomial from highest to least power:\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &poly1[i]);
    printf("Enter the coefficients of second polynomial from highest to least power:\n");
    for (i = 0; i <= m; i++)
        scanf("%d", &poly2[i]);
    add_polynomials(poly1, poly2, n, m);
    return 0;
}

/*
SAMPLE I/O
Enter the degrees of the polynomials: 3 4
Enter the coefficients of first polynomial from highest to least power:
3 2 1 5
Enter the coefficients of second polynomial from highest to least power:
1 2 4 3 6
SUM:
1x^4 + 5x^3 + 6x^2 + 4x^1 + 11x^0

Time complexity : O(n)
Space Complexity: O(n)
*/
