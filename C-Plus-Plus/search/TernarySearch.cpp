#include <bits/stdc++.h> 
using namespace std; 

//Recursive Approach: Time Complexity Is O(log3(N))
int ternarySearchRecursion(int l, int r, int key, int ar[]) 
{ 
	if (r >= l) { 
		// Find the mid1 and mid2 
		int mid1 = l + (r - l) / 3; 
		int mid2 = r - (r - l) / 3;
		
		// Check if key is present at any mid
		if (ar[mid1] == key) { 
			return mid1; 
		} 
		if (ar[mid2] == key) { 
			return mid2; 
		} 
		// Since key is not present at mid, 
        	// check in which region it is present 
	        // then repeat the Search operation 
	        // in that region 
		if (key < ar[mid1]) { 
			 // The key lies in between l and mid1 
			return ternarySearchRecursion(l, mid1 - 1, key, ar); 
		} 
		else if (key > ar[mid2]) { 
			// The key lies in between mid2 and r 
			return ternarySearchRecursion(mid2 + 1, r, key, ar); 
		} 
		else {
       	                // The key lies in between mid1 and mid2 
			return ternarySearchRecursion(mid1 + 1, mid2 - 1, key, ar); 
		} 
	} 
	// Key not found 
	return -1; 
} 

//Iterative Approach: Time Complexity Is O(log3(N))
int ternarySearchIterative(int l, int r, int key, int ar[])   
{ 
    while (r >= l) { 
	// Find the mid1 and mid2 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
	 // Check if key is present at any mid
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        } 
	// Since key is not present at mid, 
        // check in which region it is present 
        // then repeat the Search operation 
        // in that region 
        if (key < ar[mid1]) { 
	    // The key lies in between l and mid1 
            r = mid1 - 1; 
        } 
        else if (key > ar[mid2]) { 
	    // The key lies in between mid2 and r 
            l = mid2 + 1; 
        } 
        else { 
	    // The key lies in between mid1 and mid2 
            l = mid1 + 1; 
            r = mid2 - 1; 
        } 
    } 
    // Key not found 
    return -1; 
} 
int main() 
{ 
	int left, right, index, key; 	
	cout<<"Enter Number Of Elements in the array:\n";
	cin>>right;// length of array 
	int ar[right];
	cout<<"Enter The Elements In Array:\n";
	for(int i=0;i<right;i++){
	    cin>>ar[i];
	}
	left = 0;// Starting index 
	cout<<"Enter The Element To Be Searched:\n";
	cin>>key;// Key to be searched in the array 
	index = ternarySearchIterative(left, right, key, ar);// Search the key using Iterative Ternary Search
	cout << "Iterative Approach : Index of " << key << " is " << index << endl; 
	index = ternarySearchRecursion(left, right, key, ar); // Search the key using Recursive Ternary Search 
	cout << "Recursive Approach : Index of " << key << " is " << index << endl; 
} 
'''
Time Complexity : O(log3(N))
Sample I/O:
INPUT : 
Enter Number Of Elements in the array:
9
Enter The Elements In Array:
1 2 3 4 5 6 7 8 9 
Enter The Element To Be Searched:
5

OUTPUT : 
Iterative Approach : Index of 5 is 4
Recursive Approach : Index of 5 is 4
'''
