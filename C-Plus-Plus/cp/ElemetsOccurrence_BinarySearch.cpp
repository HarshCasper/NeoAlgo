/* To print the occurrence of the given number in the list/array using Binary Search Technique 

inputs:
Size of array/list
Elements in the array/list
A number whose occurrence is to be printed

The program should do :
Find the occurrence of the given number using the above technique

Sample Test Case:
Input :
5
1 4 2 3 4
4
Output:
Occurrence of '4': 2

Space Complexity - O(1)
Time complexity - logn
*/


#include <iostream> //Header File
using namespace std; //Standard cin and cout


//Binary_search() for performing binary search on elements


int Binary_search (int array[], int sizeOf_array, int number, bool found)
{
    int start = 0, end = sizeOf_array - 1;
    int value = -1;
    while (start <= end)
    {
        int middle = start + ((end - start) / 2);

        if (number == array[middle]) 
        {
            value = middle;

            if (found)

                end = middle - 1;
            else 

                start = middle + 1;
            
        }

        else if (number < array[middle])
        {
            end = middle - 1;
        }

        else
        {
            start = middle + 1;
        }
    }

    return value;
}

//Partition() for quick_sort Algorithm


int Partition (int *Array, int start, int end)
{
    int pivot = Array[end];
    int partition_index = start;
    for(int i = start; i < end ;i++)
    {
        if(Array[i] <= pivot)
        {
            swap(Array[i], Array[partition_index]);
            partition_index++;


        }
    }

    swap(Array[partition_index], Array[end]);

    return partition_index; 
}

//Quick_sort() for performing quick_sort Algorithm

int Quick_sort (int array[] , int lower_bound , int  upper_bound)
{
    int temporary ;

    if (lower_bound < upper_bound)
    {
        temporary = Partition (array , lower_bound , upper_bound );
        Quick_sort (array , lower_bound , temporary - 1);
        Quick_sort (array , temporary + 1, upper_bound);
    }
}

//main function
int main()
{
    int array_size;

    cout<<"The size of array is: ";
    cin>>array_size;

    int array[array_size];

    cout<<"Please input the elements in array:\n";
    for (int i = 0 ; i < array_size ; i++) 
    {
        cin>>array[i];
    }
    cout<<"\n";

    int number;

    cout<<"Enter the number to find its occurrence : ";
    cin>>number;

    int lower_bound = 0 , upper_bound = array_size - 1;

    Quick_sort (array , lower_bound , upper_bound);

    int first_occurrence_of_number = Binary_search (array, array_size, number, true); // function for finding first occurrence of element after sorting 

    int last_occurrence_of_number = Binary_search (array, array_size, number, false); // function for finding last occurrence of element after sorting

    int total_occurrences_of_number = last_occurrence_of_number - first_occurrence_of_number + 1; //to clculate the total number of occurrence
    
    if (first_occurrence_of_number != -1) //Occurrence Found
    {
        cout<<"Occurrence of  '"<<number<<"': " <<total_occurrences_of_number; 
    }
    else {                                  //occurrence not found
        cout<<"The number is not present in the array."; 
    }

    return 0;
}
