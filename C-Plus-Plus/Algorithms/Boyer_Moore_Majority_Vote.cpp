// C++ Program for finding out 
// Majority Element in an array  
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function to find the candidate with the Majority */
int findCandidate(int a[], int size) 
{ 
    int majority_element = 0, count = 1; 
    for (int i = 1; i < size; i++) { 
        if (a[majority_element] == a[i]) 
            count++; 
        else
            count--; 
        if (count == 0) { 
            majority_element = i; 
            count = 1; 
        } 
    } 
    return a[majority_element]; 
} 
  
/* Function to check if the candidate 
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand) 
{ 
    int count = 0; 
    for (int i = 0; i < size; i++) 
  
        if (a[i] == cand) 
            count++; 
  
    if (count > size / 2) 
        return 1; 
  
    else
        return 0; 
} 
  
/* Function to print the Majority Element */
void printMajority(int a[], int size) 
{ 
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size); 
  
    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand)) 
        cout << " " << cand << " "; 
  
    else
        cout << "No Majority Element"; 
} 
  
/* Driver code */
/* int main() 
{ 
    int a[] = { 1, 3, 3, 1, 2 }; 
    int size = (sizeof(a)) / sizeof(a[0]); 
  
    // Function calling 
    printMajority(a, size); 
  
    return 0; 
}

Output - No Majority Element */

/* Time Complexity: O(n). The time complexity is linear.
Auxiliary Space: O(1).  No extra space is required */

