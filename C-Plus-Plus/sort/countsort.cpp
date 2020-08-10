// C++ Program for implementation of counting sort  
#include<bits/stdc++.h>  
#include<string.h> 
using namespace std;  
  
//  function to sort the given char arr[] in alphabetical order  
void countSort(char arr[])  
{    
    char output[strlen(arr)];  
  
    //An array to store count of inidividul characters and initialize count array as 0  
    int count[255 + 1], i;  
    memset(count, 0, sizeof(count));  
  
    // Store count of each character  
    for(i = 0; arr[i]; ++i)  
        ++count[arr[i]];  
  
    // update count[i] so that count[i] now contains actual position of this character in output array  
    for (i = 1; i <= 255; ++i)  
        count[i] += count[i-1];  
  
    // Build the output character array  
    for (i = 0; arr[i]; ++i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
     
    // Copy the output array to arr to have sorted characters  
    for (i = 0; arr[i]; ++i)  
        arr[i] = output[i];  
}  
  
int main()  
{  
    char arr[] = "datastructures"; 
    //calling the countsort function inside main function
    countSort(arr);  
    //output the sorted array
    cout<< "Sorted character array is " << arr;  
    return 0;  
}  
