/*
 In this code we have to reverse the d elements of the array
There are many approach to slove this question like using the naive approach in which first perform
left rotate by 1 code then left rotate function from 0 to d

There is one more approach in which store d elements in temp then left rotate the remaining element
then add the temp element back  arr[n-d+i]=temp[i]

Now the efficient approach is using the Reversal Algorithm
in this we use a function leftrotate and reverse function and we will be using reverse function  
3 time 1st from o to d-1 then 2nd from  d to n-1 and then 3rd from o to n-1
*/
#include <bits/stdc++.h> 
using namespace std; 
void reversearray(int arr[],int start ,int end)
{
	
	while (start<end){
	swap(arr[start],arr[end]);            
	start ++;
	end --;
	}
}

void leftrotate(int arr[],int d,int n)
{
	if(d==0 || d==n)
	return ;
	d=d%n; 
	reversearray(arr,0,d-1);
	reversearray(arr,d,n-1);
	reversearray(arr,0,n-1);
}

void printarray(int arr[],int n)  
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}

int main()
{
	int arr[] ={1,2,3,4,5,6,7};
	int d=2;
	int n = sizeof(arr)/sizeof(arr[0]); 
	leftrotate(arr,d,n);
	printarray(arr,n);
return 0;	
}
/*
Time Complexity :-O(n)
Space Complexity :-O(1)

SAMPLE I/O :-
INPUT:-
n =5
1 2 3 4 5  
D=2
Output:- 3 4 5 1 2  

INPUT:-
n =10
1 2 3 4 5 6 7 8 9 10 
D=3
Output :- 4 5 6 7 8 9 10 1 2 3 
s*/