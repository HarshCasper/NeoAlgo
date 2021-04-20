/* This code is submitted to NeoAlgo as a part of Contributors hack 2020
Finding the longest substring without repeating characters having linear time Complexity O(n) and constant Space Complexity O(1) */
	

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

int Lols(char str[], int len) //length of longest substring
{

	if (str==NULL || len==0)   //returning zero if the string is empty
	{
		return 0;
	}
	
	int i=0; 				// varible for traversing in the string
	int j=0; 				// varible for traversing in the string
	int max_len=0;			// to store the maximum length of the substring w/o repeating Characters 
	bool hash[256]={0};     // boolean varible to check for the charecters
	
	while(i<len)
	{
		if (hash[str[i]])
		{
			if (i-j+1>max_len)
			{
				max_len=i-j+1;		//max_len=max(max_len,i-j+1);
			}				
			while(str[j]!=str[i])
			{
				hash[str[j]]=0;       
				j++;
			}
			i++;j++;
		}
		else
		{
			hash[str[i]]=1;
			i++;
		}
		
	}
	if (max_len<len-j)
	{
		max_len=len-j;				//max_len=max(max_len,len-j);
	}						
	
	return max_len-1;
}

int main(void)
{
	char string[20];
	printf("Enter Input String:");
	scanf("%[^\n]%*c", string); 
	int len=strlen(string); 			// length of the string
	printf("\nlength of longest substring without repeating characters: %d\n", Lols(string,len));
}


/* Sample Input-output

Input: Enter Input String:abcbacbb
Output: length of longest substring without repeating charecters: 3

Input: Enter Input String:Hackincodes
Output: length of longest substring without repeating charecters: 7

Input: Enter Input String:ddddd
Output: length of longest substring without repeating charecters: 1

Input: Enter Input String:
Output: length of longest substring without repeating charecters: 0  */

