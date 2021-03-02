//C program to check if two input strings are anagrams or not

#include <stdio.h>
#include <string.h>
void sort_strings(char str[]) //sort the strings
{
  int loop1, loop2;
  char temp;
  for (loop1 = 0; str[loop1] != '\0'; loop1++)
  {
    for (loop2 = 0; str[loop2] != '\0'; loop2++)
    {
      if (str[loop2] > str[loop1])
      {
        temp = str[loop1]; //swapping
        str[loop1] = str[loop2];
        str[loop2] = temp;
      }
    }
  }
}
int check_anagram(char str1[], char str2[], int len)
{
  int loop_num;
  for (loop_num = 0; loop_num < len; loop_num++)
  {
    if (str1[loop_num] != str2[loop_num])
      return -1;
  }
  return 0;
}
int main()
{
  char str1[50], str2[50];
  int len1, len2;
  printf("Enter two strings:\n");
  scanf("%s%s", str1, str2); //strings to be checked
  len1 = strlen(str1);
  len2 = strlen(str2);
  //if length of strings is not equal they cannot be anagrams
  if (len1 != len2)
    printf("The given strings are not anagrams");
  else
  {
    sort_strings(str1);
    sort_strings(str2);
    if (check_anagram(str1, str2, len1) == 0) //len1=len2
      printf("The given strings are anagrams");
    else
      printf("The given strings are not anagrams");
  }
  return 0;
}

/*
    TIME COMPLEXITY-O(nlogn)
    SPACE COMPLEXITY-O(n)

    SAMPLE INPUT
    restful
    fluster

    OUTPUT
    The given strings are anagrams
*/
