/*
Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm, 
or by recursively applying the bucket sorting algorithm.
I have used Insertion Sort to sort the individual Buckets.
*/
#include<iostream>
#include<vector>
using namespace std;

//to sort the individual bucket
void Insertion_Sort(float arr[10][10],int n,int idx)
{
	for(int i=0;i<n;i++)
	{	int k=i;
		float temp=arr[idx][i];
		while(k-1>=0 && arr[idx][k] < arr[idx][k-1])
		{
			arr[idx][k]=arr[idx][k-1];
			k=k-1;
		}

		arr[idx][k]=temp;
	}
}

void Bucket_Sort(float arr[20],int n)
{
	float temp[10][10];
	//count array stores the length of elements in the respective buckets  
	int count[10]={0};	
	for(int i=0;i<n;i++)
	{
		int idx = arr[i]*10;
		temp[idx][count[idx]]=arr[i];
		count[idx]++;
	}

	for(int i=0;i<10;i++)
	{
		if(count[i]>0)
			Insertion_Sort(temp,count[i],i);
	}

//to rewrite the values in array in sorted order
	int i=0;
	for(int j=0;j<10 && i<n;j++)
	{
		if(count[j]>0)
		{
			for(int k=0;k<count[j];k++)
			{
				arr[i]=temp[j][k];
				i++;
			}
		}
	}
}

int main()
{
	int n;
	float arr[20];
	cout<<"\nEnter number of elements:";
	cin>>n;
	cout<<"\nEnter numbers : ";
	for(int i=0;i<n;i++)
	{
		
		cin>>arr[i];
	}
	//loop to print original array

	cout<<"\n Array before sorting : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];
	}
	Bucket_Sort(arr, n);

	cout<<"\nSorted array:\n";
	//loop to print sorted array
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];
	}
	return 0;
}

/*

Input :
Enter number of elements: 8
Enter numbers : 0.787 0.6773 0.4632 0.2927 0.635 0.896 0.152 0.462

OutPut :
Array before sorting : 0.787 0.6773 0.4632 0.2927 0.635 0.896 0.152 0.462

Sorted array: 0.152	0.2927	0.462	0.4632	0.635	0.6773	0.787	0.896

*/