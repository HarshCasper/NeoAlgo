//In this problem ,you must enter elements of array and number whose occurrence you wish to find.
//Thus the occurrence of element is calculated.
//Time Complexity:O(logN)
//Space Complexity:O(1)

#include<stdio.h>

int main() {
    int total_number_of_elements, number_to_be_searched;
    //Maximum capacity of array is 10000.
    int array[1000];
    int count = 0;
    printf("Enter total number of elements : ");
    scanf("%d", & total_number_of_elements);
    printf("Enter elements of array:\n ");
    for (int i = 1; i <= total_number_of_elements; i++) {
        printf("Element %d - ", i);
        scanf("%d", & array[i]);
    }
    printf("Enter number whose occurrence needs to be counted :");
    scanf("%d", & number_to_be_searched);
    for (int i = 1; i <= total_number_of_elements; i++) {
        if (array[i] == number_to_be_searched) {
            count++;
        }
    }
    printf("The number %d occurred %d times in this array", number_to_be_searched, count);

}

//OUTPUT:
//Enter total number of elements : 6
//Enter elements of array:
//Element 1 - 1
//Element 2 - 2
//Element 3 - 1
//Element 4 - 1
//Element 5 - 2
//Element 6 - 3
//Enter number whose occurrence needs to be counted :1
//The number 1 occurred 3 times in this array.
