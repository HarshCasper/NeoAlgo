//QUICK SORT WORKS ON THE BASIS OF DIVIDE-AND-CONQUER ALGORITHM.THIS ALGORITHM IS FASTER THAN OTHER SORTING ALGORITHMS.
//TIME COMPLEXITY : O(n log n)
//SPACE COMPLEXITY :O(log n)

#include <stdio.h>

#include <conio.h>

#define capacity 100
int partition(int array[], int beggining, int end);
void quick_sort(int array[], int beggining, int end);
int partition(int array[], int beggining, int end) {
    int low, high, temp, location, flag;
    location = low = beggining;
    high = end;
    flag = 0;
    while (flag != 1) {
        while ((array[location] <= array[high]) && (location != high))
            high--;
        if (location == high)
            flag = 1;
        else if (array[location] > array[high]) {
            temp = array[location];
            array[location] = array[high];
            array[high] = temp;
            location = high;
        }
        if (flag != 1) {
            while ((array[location] >= array[low]) && (location != low))
                low++;
            if (location == low)
                flag = 1;
            else if (array[location] < array[low]) {
                temp = array[location];
                array[location] = array[low];
                array[low] = temp;
                location = low;
            }
        }
    }
    return location;
}
void quick_sort(int array[], int beggining, int end) {
    int location;
    if (beggining < end) {
        location = partition(array, beggining, end);
        quick_sort(array, beggining, location - 1);
        quick_sort(array, location + 1, end);
    }
}
void main() {
    int array[capacity], i, number_of_elements;
    printf("\n Enter the number of elements in the array: ");
    scanf("%d", & number_of_elements);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < number_of_elements; i++) {
        scanf("%d", & array[i]);
    }
    quick_sort(array, 0, number_of_elements - 1);
    printf("\n The sorted array is: \n");
    for (i = 0; i < number_of_elements; i++)
        printf(" %d\t", array[i]);
    getch();
}

//OUTPUT:
//Enter the number of elements in the array: 5
//Enter the elements of the array:
//12      1       34      3       2
//The sorted array is:
//1       2       3       12      34
