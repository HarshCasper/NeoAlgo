#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; ++i) {
  	scanf("%d", &arr[i]);
  }
  bool f = 1;
  for (int i = 0; i < n; ++i) {
  	if(arr[arr[i]] != i) {
  		f = 0;
  	}
  }
  if(f)
  	printf("The given array is mirror-inverse");
  else
  	printf("The given array is not mirror-inverse");
  return 0;
}

/*
Time Complexity: O(N)
INPUT 1:
5
1 0 2 4 3
OUTPUT 1:
The given array is mirror-inverse

INPUT 2:
5
1 2 0 4 3
OUTPUT 2:
The given array is not mirror-inverse
*/
