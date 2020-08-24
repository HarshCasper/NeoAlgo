// Program for Longest Common Subsequence(LCS) problem 
#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#include<math.h>

#define MAX 10002
//int t[MAX][MAX];

int max(int a,int b)
{
    return (a > b) ? a : b;
}

// To print LCS of X[0..m-1], Y[0..n-1] 
void lcs(char X[], char Y[], int m, int n ) 
{ 
    int t[m+1][n+1];
    // Initialisation : if either string is empty, size of LCS is 0
    for (int i=0; i<=m; i++) 
    { 
	    for (int j=0; j<=n; j++) 
	    { 
            if (i == 0 || j == 0)   
		        t[i][j] = 0;
        }
    }
    //Build-up the 2d-array t[][]
    for (int i=1; i<=m; i++) 
    { 
	    for (int j=1; j<=n; j++) 
	    {
            //If current character of the strings is same, count it & solve for remaining
            if (X[i-1] == Y[j-1])   
                t[i][j] = t[i-1][j-1] + 1; 
            //Otherwise take the larger of the 2 values
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]); 
        } 
    } 

    // Now printing LCS
    //k is the length of LCS contained in t[m][n]
    int k = t[m][n]; 
    printf("Length of LCS is %d\n",k);
    // an array to store the lcs string 
    char result[k+1]; 
    result[k] = '\0'; // Set the terminating character 

    // Start from the right-most-bottom-most corner 
    // Move backwards in the same way the table was created and 
    // one by one store characters in result[]
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        // If current character in X[] and Y[] are same, then 
        // current character is part of LCS 
        if (X[i-1] == Y[j-1]) 
        { 
            result[k-1] = X[i-1]; // Put current character in result 
            i--; j--; k--;	 // reduce values of i, j and k 
        } 

        // Otherwise, move in the direction of larger value 
        else if (t[i][j-1] > t[i-1][j]) 
            j--; 
        else
            i--; 
    } 
    // Print the result
    printf("LCS of %s and %s is %s\n",X,Y,result); 
} 

int main() 
{ 
    char X[MAX],Y[MAX];
    printf("Enter the strings: \n");
    scanf("%s%s",X,Y); 
    int m = strlen(X); 
    int n = strlen(Y); 
    lcs(X, Y, m, n); 
    return 0;
} 
