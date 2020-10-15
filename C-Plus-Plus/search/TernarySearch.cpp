#include <bits/stdc++.h> 
using namespace std; 

//Recursive Approach
int ternarySearchRecursion(int l, int r, int key, int ar[]) 
{ 
	if (r >= l) { 

		int mid1 = l + (r - l) / 3; 
		int mid2 = r - (r - l) / 3; 

		if (ar[mid1] == key) { 
			return mid1; 
		} 
		if (ar[mid2] == key) { 
			return mid2; 
		} 

		if (key < ar[mid1]) { 

			return ternarySearchRecursion(l, mid1 - 1, key, ar); 
		} 
		else if (key > ar[mid2]) { 

			return ternarySearchRecursion(mid2 + 1, r, key, ar); 
		} 
		else { 

			return ternarySearchRecursion(mid1 + 1, mid2 - 1, key, ar); 
		} 
	} 

	return -1; 
} 

//Iterative Approach
int ternarySearchIterative(int l, int r, int key, int ar[]) 
  
{ 
    while (r >= l) { 
  
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        } 
  
        if (key < ar[mid1]) { 
  
            r = mid1 - 1; 
        } 
        else if (key > ar[mid2]) { 
  
            l = mid2 + 1; 
        } 
        else { 
  
            l = mid1 + 1; 
            r = mid2 - 1; 
        } 
    } 
  
    return -1; 
} 
 


int main() 
{ 
	int l, r, p, key; 
	
	cin>>r;

	int *ar = new int[r];
	
	for(int i=0;i<r;i++){
	    cin>>ar[i];
	}

	l = 0; 

	key = 5; 

	p = ternarySearchIterative(l, r, key, ar); 


	cout << "Index of " << key << " is " << p << endl; 



	p = ternarySearchRecursion(l, r, key, ar); 


	cout << "Index of " << key << " is " << p << endl; 
} 
