#include<iostream>			//Header file
using namespace std;		//For cin and cout
int main(){
	int n, arr[n], num, temp;			//Declarartion of required variables
	cout<<"Enter the number of elements of the array: ";
	cin>>n;			//Getting the number of elements of the array from the user
	cout<<endl<<"Enter the elements of the array to be sorted: ";
	for (int i = 0; i < n; i++){			//For loop for taking elements of the array from the user, can be space-seperated as well
		cin>>num;
		arr[i] = num;
	}
	for (int i = 0; i < n-1; i++){			//Outer for loop
		for(int j = 0; j < n-1; j++){		//Inner for loop
			if(arr[j] > arr[j+1]){			//Checking if the element if larger than the next element
				temp = arr[j+1];			//Swapping the elements, temp is used to store the temporary variable
				arr[j+1] = arr[j];
				arr[j] = temp; 
				}
			}
	}
	cout<<"Array after sorting is:"<<endl;
	for(int i = 0; i < n; i++){			//For loop for printing out the array after sorting
		cout<<arr[i]<<" ";
		}

return 0;
}
