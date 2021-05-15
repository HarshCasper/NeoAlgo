//Huffman algorithm
#include <stdio.h>
#include <stdlib.h>

#define max 50

struct Node {
  char item;
  long long freq;
  struct Node *left, *right;
};

struct Heap {
  long long size;
  long long capacity;
  struct Node **array;
};

// Create nodes
struct Node *newNode(char item, long long freq) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

// Create min heap
struct Heap *createMinH(long long capacity) {
  struct Heap *minHeap = (struct Heap *)malloc(sizeof(struct Heap));

  minHeap->size = 0;

  minHeap->capacity = capacity;

  minHeap->array = (struct Node **)malloc(minHeap->capacity * sizeof(struct Node *));
  return minHeap;
}

// Function to swap
void swap(struct Node **a, struct Node **b) {
  struct Node *t = *a;
  *a = *b;
  *b = t;
}

// Heapify
void Heapify(struct Heap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swap(&minHeap->array[smallest], &minHeap->array[idx]);
    Heapify(minHeap, smallest);
  }
}

// Check if size is 1
int checkSizeOne(struct Heap *minHeap) {
  return (minHeap->size == 1);
}

// Extract min
struct Node *extractMin(struct Heap *minHeap) {
  struct Node *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  Heapify(minHeap, 0);

  return temp;
}

// Insertion function
void insertMinHeap(struct Heap *minHeap, struct Node *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct Heap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    Heapify(minHeap, i);
}

int isLeaf(struct Node *root) {
  return !(root->left) && !(root->right);
}

struct Heap *createAndBuildMinHeap(char item[], int freq[], int size) {
  struct Heap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct Node *buildHuffmanTree(char item[], int freq[], int size) {
  struct Node *left, *right, *top;
  struct Heap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void result(int arr[], int n);

void printHCodes(struct Node *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    printf("  %c  -> ", root->item);
    result(arr, top);
  }
}

// Wrapper function
void HuffmanCodes(char item[], int freq[], int size) {
  struct Node *root = buildHuffmanTree(item, freq, size);

  int arr[max], top = 0;

  printHCodes(root, arr, top);
}

// Print the array
void result(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);

  printf("\n");
}

int main() {
  char arr[] = {'A', 'B', 'C', 'D'};
  int freq[] = {5, 1, 6, 3};

  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Huffman code:\n");
 

  HuffmanCodes(arr, freq, size);
}