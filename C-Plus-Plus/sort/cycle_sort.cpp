#include <iostream> 
using namespace std; 
  
void CycleSort(int *arr, int n) 
{ 
    int writes = 0; 
  
    for (int str = 0; str <= n - 2; str++) { 
        // initialize item as starting point 
        int st_p = arr[str]; 
      
        int pos = str; 
        for (int i = str + 1; i < n; i++) 
            if (arr[i] < st_p) 
                pos++; 
  
        if (pos == str) 
            continue; 
  
        while (st_p == arr[pos]) 
            pos += 1; 
   
        if (pos != str) { 
            swap(st_p, arr[pos]); 
            writes++; 
        } 
  
        // Rotateting Cycle
        while (pos != str) { 
            pos = str; 
 
            for (int i = str + 1; i < n; i++) {
                if (arr[i] < item) 
                    pos += 1; 
            }
  
            // ignoring Duplicates
            while (st_p == arr[pos]) {
                pos += 1; 
            }
  
            if (st_p != arr[pos]) { 
                swap(st_p, arr[pos]); 
                writes++; 
            } 
        } 
    } 
} 
  
int main() 
{ 
    int arr[] = { 1,3,2,4,3,6,4,8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    CycleSort(arr, n); 
  
    cout << "Sorted Array is :-" << endl; 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    return 0; 
} 
