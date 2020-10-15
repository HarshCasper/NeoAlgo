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
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	l = 0; 
	r = 9;
	key = 5; 
	p = ternarySearchIterative(l, r, key, ar);
	cout << "Iterative Approach : Index of " << key << " is " << p << endl; 
	p = ternarySearchRecursion(l, r, key, ar); 
	cout << "Recursive Approach : Index of " << key << " is " << p << endl; 
} 
