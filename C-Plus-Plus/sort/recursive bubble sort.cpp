// c++ program for Bubble sort using recursion 
#include<iostream>
using namespace std;
//function for recursive Bubble sort
void BubbleSort(int arr[],int n){
	//basic case
	if(n==1){
		return;
	}
		for(int i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
			}
		//for recursion
		  BubbleSort(arr,n-1);
		}
	}
//function for printing array
void Display(int arr[],int n){
	cout<<"after sorting:"<<endl;
	for(int j=0;j<n;j++){
		cout<<arr[j]<<" ";
	}
}
//program for testing above functions
int main(){
	int n;
	cout<<"enter the number of element:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the value of element:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	BubbleSort( arr , n);
	Display(arr,n);
}
/*
INPUT:
enter the number of element:
8
enter the value of element:
345 568 976 1 35 76 1234 2341
OUTPUT:
after sorting:
1 35 76 345 568 976 1234 2341
*/
