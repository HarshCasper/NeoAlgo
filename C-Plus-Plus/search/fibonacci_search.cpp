
/*
Fibonacci search is an efficient search algorithm based on:
--> divide and conquer principle that can find an element in the given sorted array. */
/*
Algorithm --->

Let the length of given array be n [0...n-1] and the element to be searched be x.

Then we use the following steps to find the element with minimum steps:

1) Find the smallest Fibonacci number greater than or equal to n.
Let this number be c [ Fibonacci number].
Let the two Fibonacci numbers preceding it be a and b respectively.

While the array has elements to be checked:
-> Compare x with the last element of the range covered by a.
-> If x matches, return index value
-> Else if x is less than the element, move the third Fibonacci variable two Fibonacci down,
indicating removal of approximately two-third of the unsearched array.

-> Else x is greater than the element, move the third Fibonacci variable one Fibonacci down.
Reset offset to index. Together this results into removal of approximately front one-third of the unsearched array.

Since there might be a single element remaining for comparison, check if b is '1'.
If Yes, compare x with that remaining element. If match, return index value.

From the above algorithm it is clear if we have to search the larger section of the array,
then the time taken will be more and will result into worst case and it's complexity wil be O(log n).
If on the very first search, we get our element then it will be considered as the best case and complexcity will be O(1).
When we consider the average case then case left and lies between the best and worst i,
when we have to search the element on the smaller section of the array and hence we get our average case complexity as O(log n).

According to the algorithm we will first sort the array.
Output is based on Sorted array.

QUESTION-->
1) You are given 't' test cases to check.
2) You are given a memory space of array size, 10.
3) You are asked to enter elements in the array.
4) You can input as much elements in the array less than or equal to 10.
5) The array should be sorted if Unsorted.
6) You have to chose an element and find its position in the sorted array.
7) if element not found, print -1.
*/

#include<bits/stdc++.h>
using namespace std;

// function created to find the min value between x and y
int min(int x, int y) { return (x <= y) ? x : y; }

//function created returns index of x if present,  else returns -1.
int FibonacciSearch(int arr[], int x, int n){
// a,b,c are variables that stores the fibonacci numbers sequentially.
int a = 0;
int b = 1;
int c = a + b;

// until c does not become equal to or greater than n , loop executes.
while(c < n){

a = b;
b = c;
c = a + b;
}
// Marks the eliminated range from front
int offset = -1;

// checking if c is at valid location.
while (c > 1) {
// i will be assigned the value of min() used.
int i = min(offset + a, n - 1);


/*If x is greater than the value at index ,c cut the subarray array from offset to i*/
if (arr[i] < x) {

c = b;
b = a;
a = c - b;
offset = i;
}
/*If x is greater than the value at index ,c
cut the subarray after i+1. */
else if (arr[i] > x) {
c = a;
b = b - a;
a = c - b;
}


else
//if element found, return index.
return i;
}
//comparing the last element with x
if (b && arr[offset + 1] == x)
return offset + 1;
// if not then return -1.
return -1;
}


int main(){
int t; cin>>t;
while(t--){
int l;
cout<<"\nEnter the number of elements in array which should be less than 10";
cin>>l;
//array defined
int arr[10];
cout<<"Enter elements in array";
for(int i=0;i<l;i++)
{
cin>>arr[i];
}
//sorting the array
sort(arr, arr + l);

int n = sizeof(arr)/sizeof(arr[0]);
int x;
cout<<"\nEnter element to be searched :" ;
cin>>x;
cout<<"Found at index:"<<FibonacciSearch(arr, x, n);
}
return 0;
}



/* complexities */
/*
Worst case time complexity:  O(log n)
Average case time complexity:  O(log n)
Best case time complexity:  O(1)
Space complexity:  O(1)   */


/*
sample input :
3
7
100 90 30 15 60 120 10
30
5
40 60 22 10 45
22
2
40 60
45
*/

/*
sample output:
2
1
-1
             
*/


