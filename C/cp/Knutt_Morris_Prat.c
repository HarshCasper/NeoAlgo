/*Knuth–Morris–Pratt string-searching algorithm 
Searches for occurrences of a word W within a main text string S 
*/
#include <stdio.h>
#include <string.h>

int Knutt_Morris_Prat(char[], char[]);
int main()
{
	char string[20], matchcase[20];
	printf("Enter string: ");
	gets(string);
	printf("Enter substring: ");
	gets(matchcase);
	Knutt_Morris_Prat(string, matchcase);
	return 0;
}

int Knutt_Morris_Prat(char string[], char matchcase[])
{
	int i, j = 0, index;
	for (i = 0; i < strlen(string) - strlen(matchcase) + 1; i++)
	{
		index = i;
		if (string[i] == matchcase[j]) /*Check if characters match*/
		{
			/*Continue checking until the characters match or the end of pattern string is reached*/
			do {
				i++;
				j++;
			} while (j != strlen(matchcase) && string[i] == matchcase[j]);
			if (j == strlen(matchcase)) /*if j is equal to pattern length, pattern is found.*/
			{
				printf("Match found from position %d to %d.\n", index + 1, i);
				return 0;
			}
			else /*if j is not equal to pattern length, move to next character and continue the same steps.*/
			{
				i = index + 1;
				j = 0;
			}
		}
	}

	printf("No substring match found in the string.\n");
	return 0;
}

/*
Time Complexity: O(n + m)  - n is the length of string and m is the length of substring
Space Complexity: O(m) - m is the length of substring

Sample Output
Enter string: ABCABAABCABAC
Enter subsring: CAB 
Match found from position 3 to 5.
*/

