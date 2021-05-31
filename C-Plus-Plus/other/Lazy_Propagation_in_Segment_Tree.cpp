//Demonstrating the working of LAZY PROPOGATION in Segment Tree using the problem statment : To update a range in the array and return the maximum element in the array after updating.

//TIME COMPLEXITY OF LAZY PROPOGATION: O(log(N))   [N here is the range]

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
  
  
//storing the segment tree
int tree[MAX] = { 0 };
  
// For storing the pending updates
int lazy[MAX] = { 0 };
  
void updateHelp(int current, int startI, int endI, int us,
                     int ue, int diff)
{
    if (lazy[current] != 0) {
        
        tree[current] += lazy[current];
  
        if (startI != endI) {
            
            lazy[current * 2 + 1] += lazy[current];
            lazy[current * 2 + 2] += lazy[current];
        }
  
    
        lazy[current] = 0;
    }
  
    
    if (startI > endI || startI > ue || endI < us)
        return;
  
   
    if (startI >= us && endI <= ue) {
        // Adding the difference to current node
        tree[current] += diff;
  
        if (startI != endI) {
          
            lazy[current * 2 + 1] += diff;
            lazy[current * 2 + 2] += diff;
        }
        return;
    }
  
    int mid = (startI + endI) / 2;
    updateHelp(current * 2 + 1, startI, mid, us, ue, diff);
    updateHelp(current * 2 + 2, mid + 1, endI, us, ue, diff);
  
    tree[current] = max(tree[current * 2 + 1], tree[current * 2 + 2]);
}
  
// Updating the range of values in segment tree

void updateArray(int n, int us, int ue, int diff)
{
    updateHelp(0, 0, n - 1, us, ue, diff);
}
 
int FindMaxHelp(int startI, int startE, int qs, int qe, int current)
{
  
   
    if (lazy[current] != 0) {
  
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        tree[current] += lazy[current];
  
        // Checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (startI != startE) {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[current * 2 + 1] += lazy[current];
            lazy[current * 2 + 2] += lazy[current];
        }
  
        // Unset the lazy value for current node as it has
        // been updated
        lazy[current] = 0;
    }
  
    // Out of range
    if (startI > startE || startI > qe || startE < qs)
        return 0;
  
    if (startI >= qs && startE <= qe)
        return tree[current];
  
    // If part of this segment overlaps with the given range
    int mid = (startI + startE) / 2;
    return max(FindMaxHelp(startI, mid, qs, qe, 2 * current + 1),
               FindMaxHelp(mid + 1, startE, qs, qe, 2 * current + 2));
}
  
int FindMax(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe) {
        printf("Invalid Input");
        return -1;
    }
  
    return FindMaxHelp(0, n - 1, qs, qe, 0);
}
  

void constructHelp(int arr[], int startI, int startE, int current)
{
    
    if (startI > startE)
        return;
  
    if (startI == startE) {
        tree[current] = arr[startI];
        return;
    }
  
    int mid = (startI + startE) / 2;
    constructHelp(arr, startI, mid, current * 2 + 1);
    constructHelp(arr, mid + 1, startE, current * 2 + 2);
  
    tree[current] = max(tree[current * 2 + 1], tree[current * 2 + 2]);
}
  

void constructSegmentTree(int arr[], int n)
{
    constructHelp(arr, 0, n - 1, 0);
}
// Variable Declaration:
// current -> index of current node in segment tree
// startI and endI -> Starting and ending indexes of
// elements for which current nodes stores sum
// us and ue -> starting and ending indexes of update query
// diff -> which we need to add in the range us to ue
// Driver code
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a,b,sum;
 
    cout<<"Starting Index in array for update: ";
    cin>>a;
    cout<<"End Index in array for update:";
    cin>>b;
    cout<<"Amount by which array elements are to be updated:";
    cin>>sum;
    // Build segment tree from given array
    constructSegmentTree(arr, n);
  
    // Add 4 to all nodes in index range [0, 3]
    updateArray(n, a, b, sum);
  
    // Print maximum element in index range [1, 4]
    cout<<"Max element after update is:";
    cout << FindMax(n, a+1, b+1);
  
    return 0;
}

/*
OUTPUT:
Enter the size of the array:10

Enter the array elements:1 2 3 4 5 6 7 8 9 10

Starting Index in array for update: 1

End Index in array for update:8

Amount by which array elements are to be updated:10

19
*/
