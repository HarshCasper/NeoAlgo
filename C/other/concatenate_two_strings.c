// The best way to concatenate two strings in C programming is by using the strcat() function.But,in this example, we will concatenate two strings manually.
#include <stdio.h>
#include <string.h>     //header file

int main() {
  char str1[100] = "Hey,Open Source is amazing", str2[] = " Start contributing";   //It's important to note that the length of str1 should be sufficient to hold the string after concatenation.
  int length, j;

  // store length of str1 in the length variable
  length = 0;
  while (str1[length] != '\0') {
    ++length;
  }

  // concatenate str2 to str1
  for (j = 0; str2[j] != '\0'; ++j, ++length) {
    str1[length] = str2[j];
  }

  // terminating the str1 string
  str1[length] = '\0';

  printf("After concatenation, Final string will be: ");
  puts(str1);

  return 0;
}
//The two strings str1 and str2 will be concatenated and the result will be  stored in s1.

//OUTPUT: After concatenation, Final string will be:Hey,Open Source is amazing Start contributing
