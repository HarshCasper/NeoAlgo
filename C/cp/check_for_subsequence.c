#include <stdio.h>
#include <string.h>

int main()
{
    char str1[1000] , str2[1000];
    int i = 0 , j = 0;                    // i will point to string 1 and j will point to string 2 
    printf(" Enter first string :\n");
    scanf("%s" , str1);                   // str1 is substring
    printf(" Enter second string :\n");
    scanf("%s" , str2);                   //str2 is full string
    while (i < strlen(str1) && j < strlen(str2)) 
    {
		if (str1[i] == str2[j]) 
		{
			i++;
		}
		j++;
	}
	
	if (i == strlen(str1)) 
	{
		printf("Yes, str1 is substring of str2\n");
	}
	else 
	{
		printf("No, str1 is not a substring of str2\n");
	}
		
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
Input:
DTH SDFDTHFGB
QBR EQVBA
Output:
Yes, str1 is substring of str2
No, str1 is not substring of str2
*/
