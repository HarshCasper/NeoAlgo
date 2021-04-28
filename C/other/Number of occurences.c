//Enter elements of an array and number to be searched you must find number of occurrences of that number in an array.

#include <stdio.h>

int main() {
    int total_number_of_elements, number_to_be_searched;
    //maximum size of this array is 10000.
    int array[10000];
    int count = 0;
    printf("Enter total number of elements : ");
    scanf("%d", & total_number_of_elements);
    printf("Enter elements of an array :\n");
    for (int i = 0; i < total_number_of_elements; i++) {
        scanf("%d", & array[i]);
    }
    printf("Enter number whose occurrence must be counted : \n");
    scanf("%d", & number_to_be_searched);
    for (int i = 0; i < total_number_of_elements; i++) {
        if (array[i] == number_to_be_searched) {
            count++;
        }
    }
    printf("The number %d occurred %d time.", number_to_be_searched, count);
}

// Output:
// Enter total number of elements:5
// Enter elements of an array :
// 3 2 2 2 3
// Enter number whose occurrence must be counted : 2
// The number 2 occurred 3 time.

// Time Complexity :O(log n)
// Space Complexity:O(1)
