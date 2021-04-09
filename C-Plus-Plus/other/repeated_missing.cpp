/*
Repeating and missing number

Given an unsorted array of positive integers. The elements are in the range 1 to n where n is the size of array,
there is one number which is repeated and another number which is missing. Find these numbers and print them.
The approach used is that checking if the current element is in its desired position or not. It is, then simply iterate
for next, else put it in its desired position by comparing with its index number and swap it accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

void print_number(int input[], int n){
    int j = 0;
    while(j < n){
        //if below condition is true then the number is either in its desired position or is repeated
        if(input[j] == j+1 || input[j] == input[input[j]-1]){
            j++;
        }
        else{
            //else putting the elements in its desired position by swaping them with the index number - 1
            swap(input[j], input[input[j]-1]);
        }
    }
    
    //after arranging the number in the sequence, printing the repeated and missing number
    for(int i = 0; i < n; i++){
        if(input[i] != i+1){
            cout << "\nRepeated number: " << input[i] << endl;
            cout << "Missing number: " << i+1 << endl;
        }
    }
}

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    cout << "\n Enter the elements of array: ";
    int input[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];

    //calling the function for repeated and missing number
     print_number(input, n);
	
	return 0;
}

/*
Test Case :
Input - 
Enter the size of array: 7
Enter the elements of array: 4 2 3 6 1 1 7
Output - 
Repeated number: 1
Missing number: 5

Time Complexity: O(n), n is size of array - for traversing the array
Space Complexity: O(1), since no extra space is used
*/

