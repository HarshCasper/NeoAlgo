#include <stdio.h>
#include <string.h>
int find_occ(char main_str[100], char sub_str[100], int main_len, int sub_len);
int main()
{
    char word[100], sub[100];
    scanf("%s%s", word, sub);
    int len_word, len_sub, occ; //find length of both strings
    len_word = strlen(word);
    len_sub = strlen(sub);
    if (len_word = 0 || len_sub == 0 || len_word < len_sub) //if either string is empty or length of substring is greater than the main string
        printf("Enter valid strings.");
    else
    {
        occ = find_occ(word, sub, len_word, len_sub);
        printf("Number of occurences of %s in %s: %d", sub, word, occ);
    }
    return 0;
}
int find_occ(char main_str[100], char sub_str[100], int main_len, int sub_len)
{
    int occ = 0, len_m; //loop variables and variable to store occurence
    for (len_m = 0; len_m <= (main_len - sub_len); len_m++)
    {
        int len_s;
        for (len_s = 0; len_s < sub_len; len_s++)
        {
            if (main_str[len_m + len_s] != sub_str[len_s])
                break;
        }
        if (len_s == sub_len)
        {
            occ++;
            len_s = 0;
        }
    }
    return occ;
}

/*
Time Complexity: O(len_word*len_sub)
Space Complexity: O(len_word)

Sample Input:
abcchifjrnccdnrr
cc
Output:
Number of occurences of cc in abcchifjrnccdnrr: 2
*/
