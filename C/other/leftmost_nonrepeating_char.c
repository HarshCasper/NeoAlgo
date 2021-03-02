#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int first;
    int second;
};

int find_char_index(char *str)
{
    struct pair p[256] = {0};
    for (int i = 0; str[i]; i++)
    {
        (p[str[i]].first)++;
        p[str[i]].second = i;
    }
    int index = 10001;
    for (int i = 0; i < 256; i++)
    {
        if (p[i].first == 1)
            index = index > p[i].second ? p[i].second : index;
    }
    return index;
}

int main()
{
    char str[10000];
    printf("Enter a string: ");
    scanf("%s", str);
    int index = find_char_index(str);
    if (index == 10001)
        printf("%d", -1);
    else
        printf("%d", index);
    return 0;
}

/*
Given a string, find the index of the leftmost non repeating character in it.
Example: s = "hello", output should be: 0 (index of h)
s = "aabcdb", output should be: 3 (index of c)
s = "xxyyzz", output should be -1 (since there is no non repeating character in this string)

Time Complexity: O(n)
Space Complexity: O(n)
*/
