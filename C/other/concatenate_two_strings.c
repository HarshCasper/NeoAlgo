//C Program to concatenate two strings without using the strcat() function.
#include <stdio.h>
#include <string.h> 

int main() {
  
  char str1[100], str2[100];
  printf("Enter the first string:");
  scanf("%s", str1);
  printf("Enter the second string:");
  scanf("%s", str2); 
  int length, j;

  length = 0;
  while (str1[length] != '\0') {
    ++length;
  }

  for (j = 0; str2[j] != '\0'; ++j, ++length) {
    str1[length] = str2[j];
  }

  str1[length] = '\0';

  printf("After concatenation, Final string will be:\n ");
  puts(str1);

  return 0;
}

/*
  INPUT:
  Enter the first string:Hello
  Enter the second string:World

  OUTPUT:
  After concatenation, Final string will be:
  HelloWorld
*/