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
	char string[10]="abcabcbb";
	int len=strlen(string);
	printf ("Given Substring:"); 
	printf("%s",string);				// length of the string
	printf("\nlength of longest substring without repeating characters: %d\n", Lols(string,len));
}

