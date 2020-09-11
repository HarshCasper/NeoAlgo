// algorithm for merging two sorted array in O(1) space complexity and in
// Nlog(N) + Mlog(M) time complexity
#include <stdio.h>
#include <stdlib.h>
int i, j;

void mergesort(int a[], int b[], int n, int m) {
  int min;
  if (n >= m) {
    min = m;
  } else {
    min = n;
  }
  for (i = 0; i < min; i++)  // we are swapping the elements of both the array
    // which should be there in the result
  {
    if (a[n - i - 1] > b[i]) {
      a[n - i - 1] = a[n - i - 1] - b[i];  // swapping the elements
      b[i] = a[n - i - 1] + b[i];
      a[n - i - 1] = b[i] - a[n - i - 1];
    }
  }
  // sorting the first array
  int x = n;
  int round1 = x / 2 + x % 2;
  while (round1 > 0 && x > 1) {
    for (int i = 1; i + round1 <= n;
         i++)  // Comparing elements in the first array
      if (a[i - 1] > a[i + round1 - 1]) {
        a[i - 1] = a[i - 1] - a[i + round1 - 1];
        a[i + round1 - 1] = a[i - 1] + a[i + round1 - 1];
        a[i - 1] = a[i + round1 - 1] - a[i - 1];
      }

    x = round1;
    round1 = x / 2 + x % 2;
  }
  // Sorting  the second array
  int y = m;
  int round2 = y / 2 + y % 2;
  while (round2 > 0 && y > 1) {
    for (i = 1; i + round2 <= m; i++)  // Comparing elements in the second array
      if (b[i - 1] > b[i + round2 - 1]) {
        b[i - 1] = b[i - 1] - b[i + round2 - 1];
        b[i + round2 - 1] = b[i - 1] + b[i + round2 - 1];
        b[i - 1] = b[i + round2 - 1] - b[i - 1];
      }

    y = round2;
    round2 = y / 2 + y % 2;
  }
}

void print(int a[], int b[], int n, int m) {
  for (i = 1; i <= n;
       i++)  // printing the elements of the first and second array
    printf("%d ", a[i - 1]);
  for (i = 1; i <= m; i++) printf("%d ", b[i - 1]);
}

int main() {
  int n, m;
  printf(
    "please enter the number of elements for the first array\n");  // taking
  // input
  // from the
  // user
  scanf("%d ", &n);
  printf("please enter the number of elements for the second array\n");
  scanf("%d ", &m);
  int capacity = 100;
  int used = 0;
  int *a = (int *)malloc(sizeof(int) * capacity);
  int *b = (int *)malloc(sizeof(int) * capacity);

  printf("please enter the elements of the first array\n");
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i - 1]);
    if (used == capacity) {
      capacity *= 2;
      a = (int *)realloc(a, sizeof(int) * capacity);
    }
    a[used] = a[i - 1];
    used++;
  }

  printf("please enter the elements of the second array\n");
  for (i = 1; i <= m; i++) {
    scanf("%d", &b[i - 1]);
    if (used == capacity) {
      capacity *= 2;
      b = (int *)realloc(b, sizeof(int) * capacity);
    }
    b[used] = b[i - 1];
    used++;
  }
  mergesort(a, b, n, m);
  print(a, b, n, m);
  return 0;
}

/*
Sample input/output
Enter size of first array:
6
Enter size of second array:
5
Enter array elements:
1 5 7 9 13 17
Enter array elements:
4 6 10 13 15
output
1 4 5 6 7 9 10 13 13 15 17
*/
