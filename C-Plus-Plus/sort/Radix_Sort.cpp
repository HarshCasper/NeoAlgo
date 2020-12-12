/* Radix sort works on the idea of digit by digit sorting from LSD (least significant digit) to 
MSD(most significant bit). We will use counting sort for this purpose.
*/
#include<bits/stdc++.h>
using namespace std;

void radixSort(int arr[], int n) {                        //function to perform the sort
    int i, maximum = INT_MIN, bucket[n], digitPos = 1, count = 1;    //declare a bucket array as well as the initial LSD(digitPos) with a variable to store progress
    for ( i = 0; i < n; i++)
    {
        maximum = max(maximum, arr[i]);       // find the maximum value in the array and store it
    }

    //Now implement the countsort algorithm
    while (maximum/digitPos > 0)
    {
        int digitCount[10] = {0};
        for ( i = 0; i < n; i++)
        {
            digitCount[arr[i]/digitPos%10]++;   //counts the number of times a digit occured at digitPos place for each input
        }
        for ( i = 1; i < 10; i++)
        {
            digitCount[i] += digitCount[i-1];   //finds the cumulative count
        }
        for ( i = n-1; i >= 0; i--)
        {
            bucket[--digitCount[arr[i]/digitPos%10]] = arr[i];  //just for keeping the order
        }
        
        for ( i = 0; i < n; i++)
        {
            //rearranging..
            arr[i] = bucket[i];
        }

        digitPos *= 10;    
        
        
    }
    
    
}

int main() {    //driver function
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<endl<<"Before Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    radixSort(arr, n);
    cout<<endl<<"After Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    
}


/* Time Complexity
   If we have n input numbers and they have upto d digits. Therefore count sort algorithm is implemented d times.
   Count sort is a linear algorithm with O(n) time complexity, therefore the radix sort algorithm in whole takes 
   O(n*d) time.
*/