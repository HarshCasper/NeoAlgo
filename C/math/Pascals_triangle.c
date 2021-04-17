/*
Pascal's triangle is a triangular array of the binomial coefficients. It has many applications in mathematics and computer science
The below code prints the Pascal's Triangle upto the given number of lines
*/
#include <stdio.h>

//fact function returns factorial of the number
int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

// function to find the binomial coefficient
int binomial_coef(int n, int r)
{
    return fact(n) / (fact(n - r) * fact(r));
}

//function to print the pascals triangle
void pascalsTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", binomial_coef(i, j));
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of lines for the pascal's triangle\n");
    int n;
    scanf("%d", &n);
    printf("The pascal's triangle with %d number of lines is :\n", n);
    pascalsTriangle(n);
    return 0;
}

/*
Sample I/O :

Enter the number of lines for the pascal's triangle
5
The pascal's triangle with 5 number of lines is :
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1

Time Complexity : O(n^3)
Space complexity : O(1)
*/
