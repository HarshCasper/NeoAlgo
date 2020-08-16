/**
 * Problem Statement
 * A String str and number of queries q are given as input. The queries are in
 * the form space separated values with the direction and the amount by which
 * the string is to be rotated. The first characters after each query is
 * concatenated as a separate string and is checked whether it is a substring of
 * the original string. If yes, print YES otherwise print NO. For Example:
 * Input:
 * career
 * 3
 * L 2
 * R 3
 * L 2
 * Output:
 * NO
 *
 * Author: [Lakhan Nad](https://github.com/Lakhan-Nad)
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100009
#define MAX_QUERIES 100009

/**
 * Algorithm Used:
 * STEP 1: Perform all the queries and store the first character after each
 * rotation in a seperate string Since we only need first characters we don't
 * need to perform queries instead we can simply extract the character we know
 * would come as first after rotation For left first char will be str[pos % len]
 * For right first char will be str[len - pos % len]
 * Example:
 *  Orignal str == "career", length = 6
 *  Operation: L 2 -> "reerca" [2 % length = 2]
 *  Operation: L 6 -> "career" [6 % length = 0]
 *  Operation: R 5 -> "areerc"
 * STEP 2: Check weather new string is substring of other
 * For this we use built in method strstr
 * [check it
 * here](https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm)
 */

int main() {
  char str[MAX_STRING_SIZE];
  char newstr[MAX_QUERIES];
  int queries, size;
  scanf("%s%*c", str);
  scanf("%d%*c", &queries);
  size = strlen(str);
  char direction;
  int positions;
  for (int i = 0; i < queries; i++) {
    scanf("%c %d%*c", &direction, &positions);
    positions %= size;
    if (direction == 'L') {
      newstr[i] = str[positions];
    } else {
      newstr[i] = str[size - positions];
    }
  }
  newstr[queries] = '\0';  // C strings always terminates with '\0'
  if (strstr(str, newstr) != NULL) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}