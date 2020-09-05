#include<bits/stdc++.h>
using namespace std;

// for calculating gap.
int nextGap(int gap) 
{ 
	if (gap <= 1) 
		return 0; 
	return (gap / 2) + (gap % 2); 
} 

// Function to merge the arrays
// ar1[], ar2[]: input arrays
// n, m: size of arrays ar1[] and ar2[] respectively
void merge(int ar1[], int ar2[], int n, int m)
{ 
	int i, j, gap = n + m; 
	
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
	{ 
	    // comparing elements in the first array. 
		for (i = 0; i + gap < n; i++) 
			if (ar1[i] > ar1[i + gap]) 
				swap(ar1[i], ar1[i + gap]); 

		// comparing elements in both arrays. 
		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
			if (ar1[i] > ar2[j]) 
				swap(ar1[i], ar2[j]); 
        
        // comparing elements in the second array.
		if (j < m) 
		{ 
			for (j = 0; j + gap < m; j++) 
				if (ar2[j] > ar2[j + gap]) 
					swap(ar2[j], ar2[j + gap]); 
		} 
	} 
} 
int main(){

	int n,m;
	cout<<"enter totle no.of elements";
	cin>>n>>m;
	int ar1[n],ar2[m];
	cout<<"enter 1st array elements";
	for(int i=0;i<n;i++) cin>>ar1[i];
	cout<<"enter 2nd array elements";
	for(int j=0;j<m;j++) cin>>ar2[j];
	merge(ar1,ar2,n,m);
	for(int i=0;i<n;i++) cout<<ar1[i]<<" ";
	for(int j=0;j<m;j++) cout<<ar2[j]<<" ";
	cout<<endl;
return 0;
}
/*

Time complexity is O((n+m) log(n+m)).

Sample output:
enter totle no.of elements
3 4
enter 1st array elements
2 4 6
enter 2nd array elements
1 3 5 7
answer:
1 2 3 4 5 6 7

*/


