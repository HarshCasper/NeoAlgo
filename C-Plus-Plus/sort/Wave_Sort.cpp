/*Wave Sort Algorithm is one of the famous algorithm with the view point of interviews in FAANG companies.
This algorithm helps to sort the elements of an array in a wave form.

It looks like:-

arr[0] >= arr[1] =< arr[2] >= arr[3] =< arr[4] and so on.... */

#include<bits/stdc++.h> //header file
using namespace std;    //for cin and cout

void swap(int *x, int *y){     //swap the required contents
    int temp = *x;
    *x = *y;
    *y = temp;
}

//This function sorts arr[0...n-1] in wave form.
void waveSort(int arr[], int n){

    for(int i=1; i<n; i+=2){            //'for' loop for traversing all arrays

        if(arr[i] > arr[i-1]){
            swap(&arr[i], &arr[i-1]);      //calling out swap function
        }

        if(arr[i] > arr[i+1] && i <= n-2){
            swap(&arr[i], &arr[i+1]);
        }
    }

}

int main(){

    int n, arr[n];		//Declarartion of required variables
    
	cout<<"Enter the number of elements of the array: ";
	cin>>n;		  	//Getting the number of elements of the array from the user

	cout<<"Enter the elements of the array to be sorted: " << "\n";
	for (int i = 0; i < n; i++){			//'for' loop for taking elements of the array from the user, can be space-seperated as well
		cin>>arr[i];
	}
    
    waveSort(arr, n);  // calling out waveSort function

    cout<<"Array after sorting is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}

/*Test Cases

//Input
Enter the  number of elements of the array: 7
Enter the elements of the array to be sorted:
1 5 8 7 6 4 2

//Output
Array after sorting is:
5 1 8 6 7  2  4

// Time Complexity - O(N)
// Space Comlexity - O(1)

*/