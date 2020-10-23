// Added a String Permutation Program in C

/*
Algorithm :

1) Find longest non-increasing suffix in the array.

2) If the whole array is non-increasing sequence of strings, next permutation isn't possible.

3) Otherwise, "key" is the string just before the suffix.

4) Find the rightmost string in prefix, which is lexicographically larger than key.

5) Swap key with this string.

6) Reverse the suffix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	  // Find non-increasing suffix
    int i = n-1;
    while(i>0 && strcmp(s[i-1],s[i])>=0) 
        i--;	// find key
    if (i<=0) return 0;
    
    // Swap key with its successor in suffix
    int j = n-1;
    while(strcmp(s[i-1],s[j])>=0) 
        j--;	// find rightmost successor to key
    char *tmp = s[i-1];
    s[i-1] = s[j];
    s[j] = tmp;
    
    // Reverse the suffix
    j = n-1;
    while(i<j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    return 1;
}

int main()
{
	char **s;
	int len;
  printf("Enter the size of string: ");
	scanf("%d", &len);
	s = calloc(len, sizeof(char*));
	for (int i = 0; i < len; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < len; i++)
			printf("%s%c", s[i], i == len - 1 ? '\n' : ' ');
	} while (next_permutation(len, s));
	for (int i = 0; i < len; i++)
		free(s[i]);
	free(s);
	return 0;
}

/*

sample Input and Output - 
Input- (The first line of each test file contains a single integer n, the length of the string array s.
Each of the next n lines contains a string s[i])

2
ab
cd

Output- (Print each permutation as a list of space-separated strings on a single line)

ab cd
cd ab

Time Complexity- As shown in the main method the for loop is iterating the whole length of the string order of n times
and the outer do-while itearte until it gets true(n times). So the total time complexity will be (big-oh of n-square).

*/
