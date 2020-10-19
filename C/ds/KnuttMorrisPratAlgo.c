#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main()
{
    char string[100], matchcase[20], c;
    int i = 0, j = 0, index;
 
    /*Scanning string*/
    printf("Enter string: ");
    do
    {
        fflush(stdin);
        c = getchar();
        string[i++] = tolower(c);
 
    } while (c != '\n');
    string[i - 1] = '\0';
    /*Scanning substring*/
    printf("Enter substring: ");
    i = 0;
    do
    {
        fflush(stdin);
        c = getchar();
        matchcase[i++] = tolower(c);
    } while (c != '\n');
    matchcase[i - 1] = '\0';
    for (i = 0; i < strlen(string) - strlen(matchcase) + 1; i++)
    {
        index = i;
        if (string[i] == matchcase[j])
        {
            do
            {
                i++;
                j++;
            } while(j != strlen(matchcase) && string[i] == matchcase[j]);
            if (j == strlen(matchcase))
            {
                printf("Match found from position %d to %d.\n", index + 1, i);
                return 0;
            }
            else
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

Sample Input:
Enter string: ABCABAABCABAC
Enter subsring: CAB 
Output:
Match found from position 3 to 5
*/
