/* C code for Heap Sorting*/ 

#include<stdio.h>

void maxHeap(int[], int);
void minHeap(int[], int);

int temp;
//function for maxHeap Sort
void maxHeap(int arr[], int len) {
  int pos, maxH;
  for (int i = 1; i < len; i++) {
    pos = i;
    do {
      maxH = (pos - 1) / 2;
      /* to build MAXHEAP  array */
      if (arr[maxH] < arr[pos]) {
        temp = arr[maxH];
        arr[maxH] = arr[pos];
        arr[pos] = temp;
      }
      pos = maxH;
    } while (pos != 0);
  }

  printf("Heap  array : \n");
  printf("Max Heap\n");
  for (int i = 0; i < len / 2; i++) {
    printf("Parent : %d Left Child : %d Right Child : %d\n", arr[i], arr[2 * i + 1], arr[2 * i + 2]);
  }
  for (int j = len - 1; j >= 0; j--) {
    temp = arr[0];
    arr[0] = arr[j];
    arr[j] = temp;
    maxH = 0;
    do {
      pos = 2 * maxH + 1;
      if ((arr[pos] < arr[pos + 1]) && pos < j - 1)
        pos++;
      if (arr[maxH] < arr[pos] && pos < j) {
        temp = arr[maxH];
        arr[maxH] = arr[pos];
        arr[pos] = temp;
      }
      maxH = pos;
    } while (pos < j);
  }
}

//Function for MinHeap Sort
void minHeap(int arr[], int len) {
  int pos, minH;
  for (int i = 1; i < len; i++) {
    pos = i;
    do {
      minH = (pos - 1) / 2;
      /* to build MINHEAP  array */
      if (arr[minH] > arr[pos]) {
        temp = arr[minH];
        arr[minH] = arr[pos];
        arr[pos] = temp;
      }
      pos = minH;
    } while (pos != 0);
  }
  printf("Min Heap\n");
  for (int i = 0; i < len / 2; i++) {
    printf("Parent : %d Left Child : %d Right Child : %d\n", arr[i], arr[2 * i + 1], arr[2 * i + 2]);
  }
  for (int j = len - 1; j >= 0; j--) {
    temp = arr[0];
    arr[0] = arr[j];
    arr[j] = temp;
    minH = 0;
    do {
      pos = 2 * minH + 1;
      if ((arr[pos] > arr[pos + 1]) && pos < j - 1)
        pos++;
      if (arr[minH] > arr[pos] && pos < j) {
        temp = arr[minH];
        arr[minH] = arr[pos];
        arr[pos] = temp;
      }
      minH = pos;
    } while (pos < j);
  }
}

//driver code to check above function
int main() {
  int size;
  printf("Input-->\n");
  printf("Enter the size of array :\n");
  scanf("%d", & size);
  int arr[size];
  printf("Enter the elements of array :\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", & arr[i]);
  }
  maxHeap(arr, size);
  minHeap(arr, size);
  return 0;
}

/*
 Input-->                                                                                                     
 Enter the size of array :                                                                                    
 3                                                                                                            
 Enter the elements of array :                                                                                
 12                                                                                                           
 15                                                                                                           
 56                                                                                                           
 Heap  array :                                                                                                
 Max Heap                                                                                                     
 Parent : 56 Left Child : 12 Right Child : 15                                                                 
 Min Heap                                                                                                     
 Parent : 12 Left Child : 15 Right Child : 56  
 
 Time Complexity : O(n log n)
 Space Complexity : O(1)
*/