#include<iostream>			//Header file
using namespace std;		//For cin and cout
int main(){
	int n, arr[n], num, temp;			//Declarartion of required variables
	cout<<"Enter the number of elements of the array: ";
	cin>>n;			//Getting the number of elements of the array from the user
	cout<<endl<<"Enter the elements of the array to be sorted: " <<"\n";
	for (int i = 0; i < n; i++){			//For loop for taking elements of the array from the user, can be space-seperated as well
		cin>>num;
		arr[i] = num;
	}
	for (int i = 0; i < n-1; i++){			//Outer for loop
		bool sorted = true; // declaring a sorted variable which will check if array is already sorted or not
		for(int j = 0; j < n-1-i; j++){		//Inner for loop
			if(arr[j] > arr[j+1]){			//Checking if the element if larger than the next element
				temp = arr[j+1];			//Swapping the elements, temp is used to store the temporary variable
				arr[j+1] = arr[j];
				arr[j] = temp;
				sorted = false; // sorted value will be updated to false if there is swapping of elements occured 
				}
			}
		if(sorted){ // If the elements aren't swapped and sorted is true only then array is already sorted
			break;
		}
	}
	cout<<"Array after sorting is:"<<endl;
	for(int i = 0; i < n; i++){			//For loop for printing out the array after sorting
		cout<<arr[i]<<" ";
		}

return 0;
}
/*
// Input
Enter the number of elements of the array: 5
Enter the elements of the array to be sorted:
1
2
3
6
5

// Ouput
Array after sorting is:
1 2 3 5 6

Time complexities:
	Worst Case:O(n2) -When we have to sort the array in opposite order as 
					 compared to given like ascending to descending. 
    Best Case:O(n)   - When the array is already sorted.
    Average Case:O(n2) - When elements are in jumbled order.

Space Complexity: Auxilary Space:O(2) because of variable temp and sorted.  
*/