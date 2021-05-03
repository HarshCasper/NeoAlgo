/*
A Dynamic Programming based C program to find minimum 
number operations to convert string1 to string2
*/

#include <stdio.h>
#include <string.h>
	// Utility function to find the minimum of three numbers 
int mincount(int count1, int count2, int count3)
{
	if (count1 <= count2 && count1 <= count3)
		return count1;
	else if (count2 <= count1 && count2 <= count3)
		return count2;
	else
		return count3;
}
int editDistDP(char str1[], char str2[], int str1Len, int str2Len)
{
	// Create a table to store results of subproblems 
	int dp[str1Len + 1][str2Len + 1];
	// Fill d[][] in bottom up manner 
	for (int indexstr1 = 0; indexstr1 <= str1Len; indexstr1++)
	{
		for (int indexstr2 = 0; indexstr2 <= str2Len; indexstr2++)
		{ /*If first string is empty, only option is to 
			   insert all characters of second string */
			if (indexstr1 == 0)
				// Min. operations = indexstr2
				dp[indexstr1][indexstr2] = indexstr2;
			/* If second string is empty, only option is to 
			    remove all characters of second string */
			else if (indexstr2 == 0)
				dp[indexstr1][indexstr2] = indexstr1;	// Min. operations = loop
			/*If last characters are same, ignore last char 
			   and recur for remaining string */
			else if (str1[indexstr1 - 1] == str2[indexstr2 - 1])
				dp[indexstr1][indexstr2] = dp[indexstr1 - 1][indexstr2 - 1];
			/*If the last character is different, consider all 
			  possibilities and find the minimum */
			else
				dp[indexstr1][indexstr2] = 1 + mincount(dp[indexstr1][indexstr2 - 1],	// Insert 
					dp[indexstr1 - 1][indexstr2],	// Remove 
					dp[indexstr1 - 1][indexstr2 - 1]);	// Replace 
		}
	}
	return dp[str1Len][str2Len];
}
// Driver program 
int main()
{
	char string1[20];
	char string2[20];
	int n;
	printf("\n Input: ");
	printf("\n Enter the first string:");
	gets(string1);
	printf("\n Enter the second string:");
	gets(string2);
	n = editDistDP(string1, string2, strlen(string1), strlen(string2));
	printf("\n Output:");
	printf(" %d\n ", n);
	return 0;
}
// The main() end here
/*
Input:
Enter the first string: "sunday"
Enter the second string: "saturday"
Output: 3 
*/
/*
Time Complexity : O(mn)
Space Complexity : O(mn)
*/

