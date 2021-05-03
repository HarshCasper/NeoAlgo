/* Union of arrays- Print all the elements that are present in both the arrays
Intersection of arrays- Print all the elements that are common in both the arrays  
NOTE: Element in the output should be distinct */

using namespace std;
#include<iostream>
#include<algorithm>

/* The array are unsorted */

void Intersection(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    
    while (i < n1 && j < n2)
      {
        if (i > 0 && arr1[i] == arr1[i - 1])
	     {
	         i += 1;
	         continue;
	     }
        else if (j > 0 && arr2[j] == arr2[j - 1])
	     {
	        j += 1;
	        continue;
	     }
	 // Increase both the iterating variable when common element is found
        else if (arr1[i] == arr2[j])
	    {
	        cout << arr1[i] << " ";
	        i += 1;
	        j += 1;
	    }
        else if (arr2[j] < arr1[i])
	    { 
	       j += 1;
	    }
        else
	    {
	       i += 1;
	    }
    }
}


void Union( int arr1[], int arr2[], int n1, int n2 )
{
    int i = 0, j = 0;
 
   //
    while (i < n1 && j < n2)
      {
        if (i > 0 && arr1[i] == arr1[i - 1]) 
	     {
	         i += 1;
	         continue;
	     }
	 
        else if (j > 0 && arr2[j] == arr2[j - 1])
	     {
	        j += 1;
	        continue;
	     }
        else if (arr1[i] < arr2[j])
	    {
	        cout << arr1[i] << " ";
	        i += 1;
	    }
        else if (arr2[j] < arr1[i])
	    { 
	       cout << arr2[j] << " ";
	       j += 1;
	    }
        else
	    {
	       cout << arr1[i] << " ";
	       i += 1;
	       j += 1;
	    }
    }
    // To print remaining elements from arr1
    while (i < n1)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
	    {
	        i += 1;
	        continue;
	    }
        else
	    {
	        cout << arr1[i] << " ";
	        i += 1;
	    }
    }
	
    // To print remaining elements from arr2
    while (j < n2)
    {
        if (j > 0 && arr2[j] == arr2[j - 1])
	    {
	       j += 1;
	       continue;
	    }
        else
	    {
	       cout << arr2[j] << " ";
	       j += 1;
	    }
    }
}


int main ()
{
  int n1,n2;
  cin >> n1 >> n2;
  int arr1[n1];
  int arr2[n2];

  for (int i = 0; i < n1; i++)
    cin >> arr1[i];

  for (int i = 0; i < n2; i++)
    cin >> arr2[i];

  sort (arr1, arr1 + n1);
  sort (arr2, arr2 + n2);
  
  cout<<"UNION"<<endl;
  Union(arr1, arr2, n1, n2);
  cout<<endl;
  
  cout<<"INTERSECTION"<<endl;
  Intersection(arr1, arr2, n1, n2);

return 0;
}

/* 
INPUT:
5 3
1 2 3 3 3
1 2 3
OUTPUT:
UNION
1 2 3
INTERSECTION
1 2 3

INPUT:
5 3
1 2 1 1 1
1 1 1
OUTPUT:
UNION
1 2 
INTERSECTION
1 

Time Complexity: O(n1+n2)
Space Complexity: O(1)
*/
