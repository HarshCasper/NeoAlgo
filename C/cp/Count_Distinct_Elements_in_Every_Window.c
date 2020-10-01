// C program to Count of distinct elements in every window.

#include<stdio.h>
void distCount(int a[],int n,int k){
	int count[100000]={0};
	int i,d=0;
	printf("Count of distinct elements in every window: ");
	for(i=0;i<k;i++){
		count[a[i]]+=1;
		if(count[a[i]]==1)
			d++;
	}
	
	printf("%d ",d);
	for(i=k;i<n;i++){
		count[a[i-k]]-=1;
		if(count[a[i-k]]==0)
			d--;
		if(count[a[i]]==0)
			d++;
		count[a[i]]+=1;
		printf("%d ",d);
	}
}

int main(){
	int i,n,k,a[100000];
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the size of window: ");
	scanf("%d",&k);
	distCount(a,n,k);
	return 0;
}

/*
	Sample input/output
	-------------------
	Enter the size of array: 10
	Enter the elements of array: 10 9 8 9 7 8 5 6 6 5
	Enter the size of window: 4
	Count of distinct elements in every window: 3 3 3 4 4 3 2
	------------------------------------------------------------------------------------
	
	Time Complexity= O(n) 
	Space Complexity= O(n)
*/
