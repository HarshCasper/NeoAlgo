// C Program for Interpolation search algorithm
#include <stdio.h>
//Array size must be less tha MAX
#define MAX 100
/* Interpolation search function begin ::
	Search for key element in array.
	If key present in a[0..n-1],
	then it return the index of that key element
	else return -1
*/
int interpolation_search(int a[], int low, int high, int key)
{
    int mid;
    while (low <= high && key>=a[low] && key<=a[high])  {
    	
    	 if (low == high){ 
            if (a[low] == key) return low; 
            return -1; 
    }
        //Finding the value of position     
        mid = low + ((key-a[low])/(a[high]-a[low]))*(high-low);         
		// Condition of target found 
		if (key == a[mid])
            return mid+1;        
		// If key is greater then 
		// key must be in upper part 
		if (key < a[mid])
            high = mid - 1;        
		// If key is smaller then
		// key must be in lower part 
		else
            low = mid + 1;
    }
    return -1;
}
/* End of interpolation_search() */
/* The main() begins */
int main()
{
    int a[MAX];
    int i, num;
    int key, pos;
    printf("\nEnter the size of array (num < %d) :", MAX);
    scanf("%d", &num);    
    //Interpolation search work best for uniform array
    printf("Enter %d Elements of array  :\n",num);
    for (i = 0; i < num; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the value to be Search : ");
    scanf("%d", &key);    
    //Display the user inputs of element and searched key
    printf("\nELEMENTS ARE : \n ");
	for (i = 0; i < num; i++)
		printf("%d\t", a[i]);	
	printf("\nElement to be search is : %d",key);
    pos = interpolation_search(&a[0], 0, num - 1, key);
    //Check if the elemnet found in an array or not!
    printf("\n\nOutput -->\n");
    if (pos == -1)
        printf("\nElement %d not found\n", key);
    else
        printf("\nElement %d found at position %d\n", key, pos);
    return 0;
}
/* The main() end */
/*Sample Input Output of above code 
Enter the size of array (num < 100) : 5
Enter 5 Elements of array  :
1
2
3
4
5
Enter the value to be Search : 4
ELEMENTS ARE :
1    2    3    4    5
Element to be search is : 4


Output -->
Element 4 found at position 4.
