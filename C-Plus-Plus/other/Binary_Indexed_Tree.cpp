#include <iostream> 
using namespace std; 
  
int getSum(int BITree[], int index) 
{ 
    int sum = 0; 
  
  
    index = index + 1; 
  
    
    while (index>0) 
    { 
     
        sum += BITree[index]; 
  
     
        index -= index & (-index); 
    } 
    return sum; 
} 
  

void updateBIT(int BITree[], int n, int index, int val) 
{ 

    index = index + 1; 
  
   
    while (index <= n) 
    { 
   
    BITree[index] += val; 
  

    index += index & (-index); 
    } 
} 
  

int *constructBITree(int arr[], int n) 
{ 
    
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //     cout << BITree[i] << " "; 
  
    return BITree; 
} 
  
  
//main 
int main() 
{ 
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(freq)/sizeof(freq[0]); 
    int *BITree = constructBITree(freq, n); 
    cout << "Sum of elements in arr[0..5] is "
        << getSum(BITree, 5); 
  
    
    freq[3] += 6; 
    updateBIT(BITree, n, 3, 6); 
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(BITree, 5); 
  
    return 0; 
} 
