// C code for maximum water Container

#include<stdio.h>
int maxArea(int[], int);

// function to find the maximum Area
int maxArea(int A[], int length) {
  int start = 0;
  int end = length - 1;
  int area = 0;
  int min;
  while (start < end) {
    // Calculating the max area 
    if (A[start] < A[end]) {
      min = A[start];
    } else {
      min = A[end];
    }
    int t = end - start;
    if (area < (min * t)) {
      area = min * t;
    }

    if (A[start] < A[end])
      start += 1;

    else
      end -= 1;
  }
  return area;

}
//driver code to check above function
int main() {
  int size1, size2; 
  printf("Input-->");
  printf("Enter the a size : \n");
  scanf("%d", & size1);
  printf("Enter the b size :\n");
  scanf("%d", & size2);
  int a[size1],b[size2];
  printf("Enter the elements of a container :\n");
  for (int i = 0; i < size1; i++) {
    scanf("%d", & a[i]);
  }
  printf("Enter the elements of b container\n");
  for (int i = 0; i < size2; i++) {
    scanf("%d", & b[i]);
  }
  int A = maxArea(a, size1);
  int B = maxArea(b, size2);
  printf("Output-->\n");
  if (A > B) {
    printf("Container a contain more water i.e %d\n", A);
  } else {
    printf("Container b contain more water i.e %d\n", B);
  }
  return 0;
}

/*
 Input-->
 Enter the a size : 4
 Enter the b size : 5
 Enter the elements of a container :
 1 5 4 3
 Enter the elements of b container :
 3 2 1 4 5
 Output-->
 Container b contain more water i.e 12

 Time Compelxity: O(n).
 As only one traversal of the array is required, so time complexity is O(n) where n is size of array.
 Space Complexity: O(1).
 No extra space is required, so space complexity is constant
*/