//C Program to sort an array using Shell Sort technique
#include <stdio.h>
//ShellSort Function
void ShellSort(int arr[], int num)
{
    int gap, i, j, tmp;
    //this for loop of gap is the heart of Shell sort
    //In each pass w check the valu of gap
    //if gap=1 then we stop this loop
    for (gap = num / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < num; i++)
        {
        	//loop continue for index lesser then gap
            for(j = i - gap; j >= 0; j = j - gap)
            {
            	//if lesser index value is small
            	//compared to bigger index
            	//then continue
                if (arr[j+gap] >= arr[j])
                    break;
                //else    
                // Swap values of bigger index with smaller one   
                else
                {
                    tmp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = tmp;
                }
            }
        }
    }
}
//Display function to print the result
void display(int arr[],int n)
{
	int i;
printf("\n\nSorted Array in ascending order is : \n");
for(i=0; i < n; ++i)
printf("%5d",arr[i]);
}
//Main Function
int main()
{
    int i,k, num;
    //Enter the number of element array have
    printf("Enter total number of elements :: ");
    scanf("%d",&num);
    //store the element of array
    int arr[num];
    //Input values of array
    printf("Enter elements :: ");
    for(i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }
    //Call shell sort function
    ShellSort(arr,num);
    //call display function
    display(arr,num);
    return 0;
}
//end of Main function

/*Sample Input Output
Enter total number of elements :: 10
Enter elements : 36 432 43 44 57 63  94 3 5 6

Sorted Array in ascending order is :
    3    5    6    36     43     44     57     63     94     432
*/

/*Complxity

Worst case time complexity is O(n2) 
Best case complexity is O(nlog(n)).
Space complexity is O(1).
*/
