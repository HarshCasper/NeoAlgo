/*
Finding a pair of element with sum k using hash table in a Unsorted array using c
*/
#include<stdio.h>
#include<stdlib.h>
//Define a structure for an array.
struct Array{

	int * A;

	int size;

};
void pairwithsumhash(struct Array arr)

{

	int i,greatestno = 0,smallestno = 32767; //Declaring a greatestno and smallestno

	int *H; // Declaring a integer type pointer for hash table

	int k; //Declaring a variable

	printf("Enter the sum of k:"); 

	scanf("%d",&k); //Taking inputs for sum of k 

	for(i=0;i<arr.size;i++)

	{

		if(arr.A[i]>greatestno)

			greatestno = arr.A[i]; //Finding greatestno from the array
		
		if(arr.A[i]<smallestno)

			smallestno = arr.A[i]; // Finding smallestno from the array

	}

	H = (int *)malloc((greatestno+1)*sizeof(int)); //Allocating memory dynamically 

	for(int i=0;i<greatestno+1;i++)

		H[i]=0; //Defing hash table size as per the greatestno

	for(int i=0;i<arr.size;i++)

		H[arr.A[i]]=1; //Incrementing hash table for every array value.

	for(i =0;i<arr.size;i++)

	{

		if((k-arr.A[i])>=0 && H[k-arr.A[i]]!=0) //Applying condition

		{

			printf("%d+%d=%d\n",arr.A[i],k-arr.A[i],k); //Printing the result if condition satisfies.

			H[arr.A[i]]--; //Decrementing hash table

		}

	}

	free(H); //Deleting the memory 

	H=NULL; //Making pointer to NUll.

}


int main()

{

    struct Array arr; //Declaring struct

    int ch,i; //Declaring the varibles.

    printf("Enter Size of Array");

    scanf("%d",&arr.size); //Asking user to enter the size of the array.

    arr.A = (int *)malloc(arr.size*sizeof(int)); //Alloacting memory for an array dynamically.

    printf("Enter the array elements");

    for(i=0;i <arr.size;i++)

    {

        scanf("%d",&arr.A[i]); //Asking user to enter the array values.

    }

    do

    {

        printf("\n1. Find a pair of element with sum k using hash in a Unsorted array: \n");

        printf("2. Exit\n");

        printf("enter you choice ");

        scanf("%d",&ch);


        switch(ch)

        {

            case 1: printf("Pair of Elements with sum k using hash table in a unsorted array: \n");

            pairwithsumhash(arr); 

            break;

        }

    }while(ch<2); 

    free(arr.A); //Deleting the array

    arr.A = NULL; //Making pointer to NUll.

    return 0;

}

//Output:- 
/*

Enter Size of Array5
Enter the array elements4
2
1
3
8

1. Find a pair of element with sum k using hash in a Unsorted array:
2. Exit
enter you choice 1
Pair of Elements with sum k using hash table in a unsorted array:
Enter the sum of k:5
4+1=5
2+3=5

*/
