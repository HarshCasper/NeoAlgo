/*
Finding a pair of element with sum k using hash table in a Unsorted array using c
*/
#include<stdio.h>
#include<stdlib.h>

struct Array{

	int * A;

	int size;

};
void pairwithsumhash(struct Array arr)

{

	int i,greatestno = 0,smallestno=32767;

	int *H;

	int k;

	printf("Enter the sum of k:");

	scanf("%d",&k);

	for(i=0;i<arr.size;i++)

	{

		if(arr.A[i]>greatestno)

			greatestno = arr.A[i];

		if(arr.A[i]<smallestno)

			smallestno=arr.A[i];

	}

	H = (int *)malloc((greatestno+1)*sizeof(int));

	for(int i=0;i<greatestno+1;i++)

		H[i]=0;

	for(int i=0;i<arr.size;i++)

		H[arr.A[i]]=1;

	for(i =0;i<arr.size;i++)

	{

		if((k-arr.A[i])>=0 && H[k-arr.A[i]]!=0)

		{

			printf("%d+%d=%d\n",arr.A[i],k-arr.A[i],k);

			H[arr.A[i]]--;

		}

	}

	free(H);

	H=NULL;

}


int main()

{

    struct Array arr;

    int ch,i;

    printf("Enter Size of Array");

    scanf("%d",&arr.size);

    arr.A = (int *)malloc(arr.size*sizeof(int));

    printf("Enter the array elements");

    for(i=0;i <arr.size;i++)

    {

        scanf("%d",&arr.A[i]);

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

    free(arr.A);

    arr.A = NULL;

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
