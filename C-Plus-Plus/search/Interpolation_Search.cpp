//INTERPOLATION SEARCH
#include<bits/stdc++.h> //Importing library (This is the special type of library which will include all basic libraries)
using namespace std; 

// If the searching element is present it will return its index, else it will return -1. 

int interpolationSearch(int arr[], int n, int x) 
{ 
	int lo = 0, hi = (n - 1);					//Assigning lower index as 0 and higher index as n-1

	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
	{ 
		if (lo == hi) 
		{ 
			if (arr[lo] == x) return lo; 
			return -1; 
		} 
		// Probing the position with keeping uniform distribution in mind. 
		int pos = lo + (((double)(hi - lo) / 
			(arr[hi] - arr[lo])) * (x - arr[lo])); 

		// Condition of element to be found 
		if (arr[pos] == x) 
			return pos; 

		// If x is larger, x is in upper part 
		if (arr[pos] < x) 
			lo = pos + 1; 

		// If x is smaller, x is in the lower part 
		else
			hi = pos - 1; 
	} 
	return -1; 
} 


int main()							 //Starting our main function 
{ 
 
	int num,x,loc;          
    std::cout << "Enter size of an array: ";
    std::cin >> num;
    int arr[num];						//Creating array of the size num
    std::cout << "Enter elements: " << std::endl; 
    
    for (int i = 0; i < num; i++)              			//Enter the elements in the array
    {
        std::cin >> arr[i];
    }
    
    //Sorting our array
    
	int n = sizeof(arr)/sizeof(arr[0]); 
	sort(arr, arr+n); 
  
    cout << "\nArray after sorting using "
         "default sort is : \n"<< std::endl; 
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " " ;
    
    }
    cout<< std::endl;
    
    //Entering the searching element
    std::cout << "Enter element to be searched: " << std::endl;
	cin>>x;// Element to be searched 
	int index = interpolationSearch(arr, n, x); 

	// If element was found 
	if (index != -1) 
		cout << "Element found at index " << index;      //Returning the index pf the element
	else
		cout << "Element not found.";                    //Returning -1 as element has not found 
		
	return 0; 
} 
