// The best way to concatenate two strings in C programming is by using the strcat() function.But,in this example, we will concatenate two strings manually.
#include <stdio.h>
#include <string.h>     //header file

int main() {
  char str1[100] = "Hey,Open Source is amazing", str2[] = " Start contributing";
  int length, j;

  // store length of str1 in the length variable
  length = 0;
  while (str1[length] != '\0') {
    ++length;
  }

  for (j = 0; str2[j] != '\0'; ++j, ++length) {
    str1[length] = str2[j];
  }

  str1[length] = '\0';

  printf("After concatenation, Final string will be: ");
  puts(str1);

  return 0;
}

//OUTPUT: After concatenation, Final string will be:Hey,Open Source is amazing Start contributing
