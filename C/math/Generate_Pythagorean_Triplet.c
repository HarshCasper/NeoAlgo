#include <stdio.h>

void pythagoreanTriplets(int limit) 
{ 

    int a, b, c = 0; 
    int m = 2; 
    while (c < limit) { 
        for (int n = 1; n < m; ++n)
        {
            
            a = m * m - n * n; 
            b = 2 * m * n; 
            c = m * m + n * n; 
  
            if (c > limit) 
                break; 
  
            printf("%d %d %d\n", a, b, c); 
        } 
        m++; 
    } 
} 


int main()
{
    int limit;
    printf("Enter the limit:\n");
    scanf("%d",&limit);
    pythagoreanTriplets(limit);
    return 0;
}



Sample Input:
Enter the limit:
10
Ouput:
3 4 5
8 6 10

This program finds the pythagorean triplet in the given limit
