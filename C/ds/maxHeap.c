/*
A max heap has the property that the parent is greater than or equal to the child nodes. 
When using a 0-indexed array,
Left child of a node at i is (2 * i + 1)
Right child of a node at i is (2 * i + 2)
Parent is (i - 1) / 2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int currentSize, capacity;
    int *arr;
}heap;

heap * createHeap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h -> arr = (int *)malloc(capacity * sizeof(int));
    h -> currentSize = -1;
    h -> capacity = capacity;
    return h;
}
/* to initialize an empty heap of a given capacity */

void search(heap *h, int key) {
    int index;
    for (index = 0; index <= h -> currentSize; index ++) {
        if (h -> arr[index] == key) {
            printf("Found at position %d!\n", index + 1);
            return;
        }
    }
    printf("Not found!\n");
}
/* to search if a given element is present in the heap or not */

void swap(int arr[10], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
/* to swap elements at two positions of array */

void upHeapify(heap *h, int index) {
    int parent = (index - 1) / 2;
    if (h -> arr[parent] < h -> arr[index]) {
        swap(h -> arr, parent, index);
        upHeapify(h, parent);
    }
}
/* moving an element up the heap to satisfy the max heap property */

void insert(heap *h, int value) {
    if (h -> currentSize == h -> capacity - 1) {
        printf("Heap is full. Cannot insert\n");
        return;
    }
    h -> arr[ ++ h -> currentSize] = value;
    upHeapify(h, h -> currentSize);
    printf("Inserted!\n");
}
/* inserting an element into the heap */

void downHeapify(heap *h, int index) {
    int lChild = 2 * index + 1, rChild = 2 * index + 2, largest = index;
    if (lChild <= h -> currentSize && h -> arr[lChild] > h -> arr[largest])
        largest = lChild;
    if (rChild <= h -> currentSize && h -> arr[rChild] > h -> arr[largest])
        largest = rChild;
    if (largest != index) {
        swap(h -> arr, largest, index);
        downHeapify(h, largest);
    }
}
/* moving an element down the heap to satisfy the max heap property */

void extract(heap *h) {
    if (h -> currentSize < 0) {
        printf("Heap is empty. Cannot extract!\n");
        return;
    }
    int root = h -> arr[0];
    h -> arr[0] = h -> arr[h -> currentSize --];
    downHeapify(h, 0);
    printf("Extracted number is %d!\n", root);
}
/* to extract the maximum element(i.e the root) of the max heap  */

void insertExtract(heap *h, int value) {
    if (h -> currentSize < 0 || value > h -> arr[0]) {
        printf("Extracted number is %d!\n", value);
        return;
    }
    printf("Extracted number is %d!\n", h -> arr[0]);
    h -> arr[0] = value;
    downHeapify(h, 0);
    
}
/* to insert an element into the heap and then extract the maximum element */

void display(heap *h) {
    for (int index = 0; index <= h -> currentSize; index ++) {
        printf("%d ", h -> arr[index]);
    }
    printf("\n");
}
/* to display the min heap */

int main() {
    int choice, capacity;
    printf("Enter capacity of maxHeap:\n");
    scanf("%d", &capacity);
    heap *h = createHeap(capacity);
    do {
        printf("1. Insert\n2. Extract\n3. Insert and Extract\n4. Display\n5. Search\n6. Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: { 
                int num;
                printf("Enter number to be inserted:\n");
                scanf("%d", &num);
                insert(h, num);
                break;
            }
            case 2: {
                extract(h);
                break;
            }
            case 3: {
                int num;
                printf("Enter number to be inserted:\n");
                scanf("%d", &num);
                insertExtract(h, num);
                break;
            }
            case 4: {
                printf("The maxHeap is:\n");
                display(h);
                break;
            }
            case 5: {
                int num;
                printf("Enter the number to be searched:\n");
                scanf("%d", &num);
                search(h, num);
                break;
            }
            case 6: { 
                printf("Exiting\n");
                break;
            }
            default: {
                printf("Invalid choice. Exiting\n");
                break;
            }
        }
    } while( choice > 0 && choice <= 5);
}

/*
Sample I/O:
Heap capacity: 10
insert 5
display: 5
insert 8
display: 8 5
insert 11
display: 11 5 8
extract: 11
display: 8 5
search 11: Not found!
insert and extract 15: 15
display: 8 5
exit

Time Complexities:

insert - O(log(n))
extract - O(log(n))
insert extract - O(log(n))
display - O(n)
search - O(n)

Space Complexities:

insert - O(1)
extract - O(1)
insert extract - O(1)
display - O(1)
search - O(1)
*/