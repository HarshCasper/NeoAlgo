/* 
Description : 
        Finding the longest substring without repeating characters having linear time Complexity O(n) 
		and constant Space Complexity O(1) 
*/

#include <bits/stdc++.h>
using namespace std;

//length of longest substring
int Lols(char str[], int len)
{
	//returning zero if the string is empty
	if (str == NULL || len == 0)
	{
		return 0;
	}
	// varible for traversing in the string
	int i = 0;
	int j = 0;
	// to store the maximum length of the substring w/o repeating Characters
	int max_len = 0;
	// boolean varible to check for the charecters
	bool hash[256] = {0};

	while (i < len)
	{
		if (hash[str[i]])
		{
			if (i - j + 1 > max_len)
			{
				//max_len=max(max_len,i-j+1);
				max_len = i - j + 1;
			}
			while (str[j] != str[i])
			{
				hash[str[j]] = 0;
				j++;
			}
			i++;
			j++;
		}
		else
		{
			hash[str[i]] = 1;
			i++;
		}
	}
	if (max_len < len - j)
	{
		//max_len=max(max_len,len-j);
		max_len = len - j;
	}

	return max_len - 1;
}

int main(void)
{
	char string[20];
	printf("Enter Input String:");
	scanf("%[^\n]%*c", string);
	// length of the string
	int len = strlen(string);
	printf("\nlength of longest substring without repeating characters: %d\n", Lols(string, len));
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/* 
Sample Input-output

Input: Enter Input String:abcbacbb
Output: length of longest substring without repeating charecters: 3

Input: Enter Input String:Hackincodes
Output: length of longest substring without repeating charecters: 7

Input: Enter Input String:ddddd
Output: length of longest substring without repeating charecters: 1

Input: Enter Input String:
Output: length of longest substring without repeating charecters: 0  
*/

