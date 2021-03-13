//Find the pair of adjacent elements that have the largest product in a given array and return that product.
#include <stdio.h>

void prod_elements(int *, int *, int);
int largest_product(int *, int);
int main()
{
	int num, i, arr[1000], prod[1000];
	printf("Enter the number of elements:");
	scanf("%d", &num);
	printf("Enter the elements:");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Array=");
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	prod_elements(prod, arr, num);
	printf("Largest Adjacent Product in the Array=%d", largest_product(prod, num));
	return 0;
}

// Putting the product of adjacent elements in a new array
void prod_elements(int *prod, int *arr, int num)
{
	int i;
	for (i = 0; i < num - 1; i++)
	{*(prod + i) = (*(arr + i)) * (*(arr + i + 1));
	}
}

// Taking out the largest product from the prod array
int largest_product(int *prod, int num)
{
	int i, big;
	big = *prod;
	for (i = 0; i < num - 1; i++)
	{
		if (big<*(prod + i))
			big = *(prod + i);
	}

	return (big);
}

/*Sample Output
Enter the number of elements:6
Enter the elements:3 6 -2 -5 7 3
Array=3 6 -2 -5 7 3
Largest Adjacent Product in the Array=21
*/

