#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int longest_substring(char *string)
{
    int offset[100];
    int index = 0;
	int substr_max_len = 0;
    int len = 0;
    

    memset(offset, 0xff, sizeof(offset));
    while (*string != '\0') {
        if (offset[*string] == -1) {
            len++;
          } 
		  else {
            if (index - offset[*string] > len)
				{
                len++;
            } 
			else 
			{
	        len = index - offset[*string];
            }
        }
        if (len > substr_max_len) 
		{
            substr_max_len = len;
        }
        offset[*string++] = index++;
    }

    return substr_max_len;
}

int main(void)
 {
    char *string ="HackinCodes";
	printf("\nOriginal String: %s", string);
	printf("\nLength of the longest substring without repeating characters: %d\n", longest_substring(string));
	return 0;
}

