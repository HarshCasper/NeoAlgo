#include <stdio.h>
#include <string.h>

void getZ(char s[], int z[])
{
	int n = strlen(s);
	int left = 0, right = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > right)
		{
			left = right = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		}
		else
		{
			int k = i - left;
			if (z[k] < right - i + 1)
			{
				z[i] = z[k];
			}
			else
			{
				left = i;
				while (right < n && s[right - left] == s[right])
					right++;
				z[i] = right - left;
				right--;
			}
		}
	}
}

int main()
{
	char text[100], pattern[100];
	printf("Enter the text: ");
	scanf("%s", text);
	printf("\nEnter the pattern: ");
	scanf("%s", pattern);
	int m = strlen(pattern);
	strcat(pattern, "$");
	strcat(pattern, text);
	int n = strlen(pattern);
	int z[n];
	getZ(pattern, z);
	for (int i = 0; i < n; ++i)
	{
		if (z[i] == m)
		{
			printf("\nPattern found at index %d", i - m - 1);
		}
	}

	return 0;
}

/*
Time Complexity: O(length of text + length of pattern)

Input
Enter the text: AABACAAFGAABAABA
Enter the pattern: AABA

Output
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
*/
