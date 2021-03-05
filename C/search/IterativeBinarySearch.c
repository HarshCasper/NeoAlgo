
#include<stdio.h>

//Time Complexity: O(logn)
//Space Complexity: O(n)

//Iterative Binary Search
//(l is leftmost index , r the rightmost index and val is the element we are searching for)
int binarySearch(int arr[],int l,int r,int val)
{
int mid=0;
while(l<=r)
{
	//Storing the middle index of the array
	mid=(l+r)/2;
	//value matched with X i.e searched element
	//return the corresponding index 
	if(arr[mid]==val)
	{
		return mid;
	}
	//If val is less than the mid element
	//Check the left sub-array
	else if(val<arr[mid])
	{
		r=mid-1;
	}
	//If val is greater than the mid element
	//Check the right sub-array
	else
	{
		l=mid+1;
	}
}
//value not found in the array
//return with -1 response
return -1;	
}

int main()
{
int arr[]={-2,5,14,17,19,27};
//searched value assuming to be val=19
int val=19;
int n=sizeof(arr)/sizeof(arr[0]);
int index=binarySearch(arr,0,n-1,val);	

if(index==-1)
{
	printf("\nThe element %d is not present in the array",index);
}else
{
	printf("\nThe element %d is present at index: %d",val,index);
}
return 0;	
}


